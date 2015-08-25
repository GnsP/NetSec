#ifndef NETSEC_AFFINE_CIPHER_HPP_INCLUDED__
#define NETSEC_AFFINE_CIPHER_HPP_INCLUDED__

#include "shiftCipher.hpp"
#include "multiplicativeCipher.hpp"
#include <string>

namespace gnsp{ namespace NetSec { namespace crypto{
		
		template<typename T=char>
		class affineCipher{
			public:
				affineCipher():	multkey_(1), addkey_(0){}
				affineCipher(T multkey, T addkey){
					if(multkey%2 == 0 || multkey == 13) multkey_ = 1;
					else multkey_ = multkey;
					addkey_ = addkey;
				}
				inline void setKey(T multkey, T addkey){
					if(multkey%2 == 0 || multkey == 13) multkey_ = 1;
					else multkey_ = multkey;
					addkey_ = addkey;
				}
				
				inline std::string &encrypt(std::string &message){
					multiplicativeCipher<T> multCipher(multkey_);
					shiftCipher<T> addCipher(addkey_);
					return addCipher.encrypt(multCipher.encrypt(message));
				}

				inline std::string &decrypt(std::string &message){
					multiplicativeCipher<T> multCipher(multkey_);
					shiftCipher<T> addCipher(addkey_);
					return multCipher.decrypt(addCipher.decrypt(message));
				}


			private:
				modular<26, T> multkey_;
				modular<26, T> addkey_;
		};


}}} //END OF NAMESPACE

#endif
