#ifndef NETSEC_SHIFT_CIPHER_HPP_INCLUDED__
#define NETSEC_SHIFT_CIPHER_HPP_INCLUDED__

#include "../Modular/modular.hpp"
#include "./util/util.hpp"
#include <string>

namespace gnsp{ namespace NetSec {
	
	using namespace mod;
	namespace crypto{
		using namespace util;
		
		template<typename T=char>
		class shiftCipher{
			public:
				shiftCipher():	key_(0){}
				shiftCipher(T key): key_(key) {}
				inline void setKey(T key){ key_ = key; }
				
				inline std::string &encrypt(std::string &message){
					format(message);
					modular<26, T> ch;
					for(std::size_t i=0; i<message.size(); i++){
						ch = message[i] - 'A';
						ch += key_;
						message[i] = 'A' + char(ch);
					}
					return message;
				}

				inline std::string &decrypt(std::string &message){
					modular<26> ch;
					for(std::size_t i=0; i<message.size(); i++){
						ch = message[i] - 'A';
						ch -= key_;
						message[i] = 'A' + char(ch);
					}
					return message;
				}


			private:
				modular<26, T> key_;
		};


}}} //END OF NAMESPACE

#endif
