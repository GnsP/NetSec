#ifndef NETSEC_MODULAR_HPP_INCLUDED__
#define NETSEC_MODULAR_HPP_INCLUDED__

#include <stdexcept>
namespace gnsp{ namespace NetSec { namespace mod {

class modularInverseException: public std::exception{
    virtual const char *what() const throw(){
        return "Modular Inverse does not exist in this case.";
    }
} modularInverseDoesNotExist;

template<int Mod, typename STORAGE = char>
class modular{
    public:
        modular():n_(0){}
        modular(STORAGE n){
            n = n % Mod;
            if(n<0) n = (n + Mod) % Mod;
            n_ = n;
        }
        modular(const modular &m):n_(m.n_){}

        inline void setval(STORAGE n){ 
            n = n % Mod;
            if(n<0) n = (n + Mod) % Mod;
            n_ = n;
        }
        inline STORAGE getval() const { return n_; }
        inline int getmod() const { return Mod; }

        inline STORAGE operator()(STORAGE val){
            setval(val);
            return n_;
        }

        inline STORAGE operator()() const{
            return n_;
        }

        inline modular operator+(const modular &m) const{
            STORAGE res = (n_ + m.n_) % Mod;
            res = (res + Mod)%Mod;
            return modular<Mod>(res);
        }

        inline void operator+=(const modular &m){
            STORAGE res = (n_ + m.n_) % Mod;
            res = (res + Mod) % Mod;
            n_ = res;
            return;
        }

        inline modular operator-(const modular &m) const{
            STORAGE res = (n_ - m.n_) % Mod;
            res = (res + Mod)%Mod;
            return modular<Mod>(res);
        }

        inline void operator-=(const modular &m){
            STORAGE res = (n_ - m.n_) % Mod;
            res = (res + Mod) % Mod;
            n_ = res;
            return;
        }

        inline modular operator*(const modular &m) const{
            STORAGE res = (n_ * m.n_) % Mod;
            res = (res + Mod)%Mod;
            return modular<Mod>(res);
        }

        inline void operator*=(const modular &m){
            STORAGE res = (n_ * m.n_) % Mod;
            res = (res + Mod) % Mod;
            n_ = res;
            return;
        }

        inline void operator=(const modular &m){
            n_ = m.n_;
            return;
        }

        inline bool operator==(const modular &m) const{
            return n_ == m.n_;
        }

        inline void operator=(const STORAGE &m){
            setval(m);
            return;
        }

        inline modular addInv() const{
            STORAGE res = (Mod - n_) % Mod;
            return modular<Mod>(res);
        }
        
        inline modular multInv() const{
            STORAGE res = 0;
            for ( res=0; res < Mod; res++ )
                if((n_ * res) % Mod == 1)
                    return modular<Mod>(res);
            throw modularInverseDoesNotExist;
        }

		inline operator char(){
			return static_cast<char>(n_);
		}
    
    private:
        STORAGE n_;
};


}}} // END OF NAMESPACE

#endif
