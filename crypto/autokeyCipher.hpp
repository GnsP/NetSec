#ifndef NETSEC_AUTOKEY_CIPHER_HPP_INCLUDED__
#define NETSEC_AUTOKEY_CIPHER_HPP_INCLUDED__

#include "../Modular/modular.hpp"
#include "./util/util.hpp"
#include <string>
#include <vector>

namespace gnsp{ namespace NetSec {
	
	using namespace mod;
	namespace crypto{
		using namespace util;
		
		template<typename T=char>
		class autokeyCipher{
			public:
				autokeyCipher(){}
				autokeyCipher(std::string key){
					setKey(key);
				}

				inline void setKey(std::string key){
					for(std::size_t i=0; i<key.size(); i++)
				}
				
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
				std::vector< modular<26, T> >  key_;
		};


}}} //END OF NAMESPACE

#endif
