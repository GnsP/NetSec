#ifndef NETSEC_EXTENDED_EUCLID_HPP_INCLUDED__
#define NETSEC_EXTENDED_EUCLID_HPP_INCLUDED__

#include <utility>

namespace gnsp{ namespace NetSec{ namespace aux{

class extendedEuclideanEngine{
    public:
        extendedEuclideanEngine(){}
        extendedEuclideanEngine(int a, int b){
            run_(a, b);
        }
        inline void run(int a, int b){
            run_(a, b);
        }

        inline const std::pair<int, int> &getBezoutCoeffs() const { return bezoutCoeff_; }
        inline const std::pair<int, int> &getQuotients() const { return quotients_; }
        inline const int &getGCD() const { return gcd_; }


    private:
        std::pair<int, int> bezoutCoeff_;
        std::pair<int, int> quotients_;
        int gcd_;

        inline void run_(int a, int b) {
            int s = 0, old_s = 1;
            int p = 1, old_p = 0;
            int r = b, old_r = a;
            int quotient, temp;

            while( r != 0 ){
                quotient = old_r / r;
                
                temp = old_r;
                old_r = r;
                r = temp - quotient * r;

                temp = old_s;
                old_s = s;
                s = temp - quotient * s;

                temp = old_p;
                old_p = p;
                p = temp - quotient * p;
            }

            bezoutCoeff_    = std::make_pair <int, int> (old_s, old_p);
            quotients_      = std::make_pair <int, int> (p, s);
            gcd_            = old_r;
            
            return;
        }
};



}}} //END OF NAMESPACE

#endif
