#ifndef NETSEC_MATRIX_HPP_INCLUDED__
#define NETSEC_MATRIX_HPP_INCLUDED__

#include <stdexcept>
namespace gnsp{ namespace NetSec { namespace mod {

class genericModularMatrixException: public std::exception{
    virtual const char *what() const throw(){
        return "<MATRIX.HPP> Some piece of shit just got broken down, debug at your own risk.";
    }
} matrixGenericException;

class modularMatrixOutOfRangeException: public std::exception{
    virtual const char *what() const throw(){
        return "<MATRIX.HPP> Matrix index OUT OF RANGE. (Access Error)";
    }
} matrixOutOfRangeException;


template<typename T, std::size_t R, std::size_t C>
class matrix{
	public:
		matrix(){
			for(std::size_t i=0; i<R; i++)
				for(std::size_t j=0; j<C; j++)
					mat_[i][j] = T(0);
		}

		matrix(const matrix<T,R,C> &m){
			for(std::size_t i=0; i<R; i++)
				for(std::size_t j=0; j<C; j++)
					mat_[i][j] = m[i][j];
		}

		inline T& operator() (std::size_t r, std::size_t c) {
			if(r>=R || r<0 || c>=C || c<0) throw matrixOutOfRangeException;
			return mat_[r][c];
		}

	private:
		T mat_[R][C];
};

template<typename T, std::size_t R, std::size_t C>
class subMatrixAdapter{
	public:
		subMatrixAdapter(){}
};




}}} // END OF NAMESPACE

#endif
