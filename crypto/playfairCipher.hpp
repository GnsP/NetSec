#ifndef NETSEC_PLAYFAIR_CIPHER_HPP_INCLUDED__
#define NETSEC_PLAYFAIR_CIPHER_HPP_INCLUDED__

#include "../Modular/matrix.hpp"
#include "./util/util.hpp"
#include <string>
#include <map>
#include <utility>
#include <set>
#include <iostream>

namespace gnsp{ namespace NetSec {
	
	using namespace mod;
	namespace crypto{
		using namespace util;

		template<typename T=char>
		class playfairMatrix{
			public:
				playfairMatrix(){}
				playfairMatrix(const matrix<T, 5, 5> &mat){
					for(std::size_t i=0; i<5; i++){
						for(std::size_t j=0; j<5; j++){
							tab_[mat[i][j]] = std::make_pair<int, int>(i, j);
							if(mat[i][j] == T('J'))
								tab_[T('I')] = std::make_pair<int, int>(i, j);
						}
					}
				}

				inline void createMatrix(){
					for(char ch='A'; ch<='Z'; ch++){
						if(ch == 'J') continue;
						std::pair<int, int> pos = tab_[ch];
						std::cout << pos.first << "  " << pos.second <<std::endl;
						mat_(pos.first, pos.second) = ch;
					}
				}


				inline bool insert(int i, int j, T k){
					if(tab_.find(k) != tab_.end()) return false;
					tab_[k] = std::make_pair<int, int>(i, j);
					return true;
				}

				const std::pair<int, int> &indexOf(const T &val){
					return tab_[val];
				}

				char at(int i, int j) {
					return mat_(i, j);
				}

			private:
				std::map<T, std::pair<int, int> > tab_;
				matrix<T, 5, 5> mat_;
		};


		
		template<typename T=char>
		class playfairCipher{
			public:
				playfairCipher(){}
				playfairCipher(std::string key){
					setKey(key);
				}

				inline void setKey(std::string key){
					format(key);
					std::set<char> chars = unique(key);
					int row = 0, col = 0;
					for(std::size_t i=0; i<key.size(); i++){
						char ch =  key[i];
						if(ch == 'J') ch = 'I';
						bool flg = mat_.insert(row, col, ch);
						if(flg) col++;
						if(col == 5){
							col = 0;
							row++;
						}
					}
					for(char ch='A'; ch<='Z'; ch++){
						if( chars.find(ch) == chars.end()){
							bool flg = mat_.insert(row, col, ch);
							if(flg) col++;
							if( col == 5){
								col = 0;
								row++;
							}
						}
					}
					mat_.createMatrix();
				}

				
				inline std::string &encrypt(std::string &message){
					format(message);
					insertNulls(message);
					std::pair<int, int> pos1, pos2;

					for(std::size_t i=0; i<message.size(); i+=2){
						pos1 = mat_.indexOf(message[i]);
						pos2 = mat_.indexOf(message[i+1]);

						if(pos1.first == pos2.first){
							int row = pos1.first;
							int col1 = (pos1.second+1)%5;
							int col2 = (pos2.second+1)%5;
							message[i] = mat_.at(row, col1);
							message[i+1] = mat_.at(row, col2);
						}
						else if(pos1.second == pos2.second){
							int col = pos1.second;
							int row1 = (pos1.first+1)%5;
							int row2 = (pos2.first+1)%5;
							message[i] = mat_.at(row1, col);
							message[i+1] = mat_.at(row2, col);
						}
						else{
							int row1 = pos1.first;
							int row2 = pos2.first;
							int col1 = pos1.second;
							int col2 = pos2.second;
							message[i] = mat_.at(row1, col2);
							message[i+1] = mat_.at(row2, col1);
						}
					}
					return message;
				}
				

				inline std::string &decrypt(std::string &message){
					std::pair<int, int> pos1, pos2;
					for(std::size_t i=0; i<message.size(); i+=2){
						pos1 = mat_.indexOf(message[i]);
						pos2 = mat_.indexOf(message[i+1]);

						if(pos1.first == pos2.first){
							int row = pos1.first;
							int col1 = (pos1.second+4)%5;
							int col2 = (pos2.second+4)%5;
							message[i] = mat_.at(row, col1);
							message[i+1] = mat_.at(row, col2);
						}
						else if(pos1.second == pos2.second){
							int col = pos1.second;
							int row1 = (pos1.first+4)%5;
							int row2 = (pos2.first+4)%5;
							message[i] = mat_.at(row1, col);
							message[i+1] = mat_.at(row2, col);
						}
						else{
							int row1 = pos1.first;
							int row2 = pos2.first;
							int col1 = pos1.second;
							int col2 = pos2.second;
							message[i] = mat_.at(row1, col2);
							message[i+1] = mat_.at(row2, col1);
						}
					}
					return message;
				}
				
			private:
				playfairMatrix<T> mat_;
		};


}}} //END OF NAMESPACE

#endif
