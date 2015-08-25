#include "../shiftCipher.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace gnsp::NetSec::crypto;

int main(){
	string msg = "BEEAKFYDJXEQYHYJIQRYHTYJIQFBQBUYJIIKFUHCQD";
	cout << "MESSAGE : " << msg << endl;
	shiftCipher<char> caeser(0);
	for(char i=0; i<26; i++){
		caeser.setKey(i);
		cout << "DECRYPYED : "  << "< KEY = " << int(i) << " >   " << caeser.decrypt(msg) << endl;
	}
	return 0;
}
