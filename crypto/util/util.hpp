#ifndef NETSEC_CRYPTO_UTIL_HPP_INCLUDED__
#define NETSEC_CRYPTO_UTIL_HPP_INCLUDED__

#include <cctype>
#include <string>
#include <set>
#include <utility>

namespace gnsp{ namespace NetSec { namespace crypto{ namespace util{

	std::string &format(std::string &str){
		for(std::size_t i=0; i<str.size(); i++){
			if( !std::isalpha(str[i]) ) str.erase(i--, 1);
			else str[i] = std::toupper(str[i]);
		}
		return str;
	}

	std::set<char> unique(std::string &str){
		std::set<char> charset;
		for(std::size_t i=0; i<str.size(); i++){
			if(charset.find(str[i]) != charset.end())
				str.erase(i--, 1);
			else charset.insert(str[i]);
		}
		return charset;
	}

	std::string &insertNulls(std::string &str){
		for(std::size_t i=0; i<(str.size()-1); i++)
			if(str[i] == str[i+1] ) str.insert(i++, "X");
		if(str.size() % 2 == 1) str.insert(str.end(), 'X');
		return str;
	}


}}}} // END OF NAMESPACE

#endif
