#include "../vigenereCipher.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace gnsp::NetSec::crypto;

int main(){
	string msg = "In fact crapping keeps us happily alive, I have never known anybody who died of constipation but I have never met a happy person with constipation neither";
	cout << "MESSAGE : " << msg << endl;
	string key = "crap";
	vigenereCipher<char> caeser(key);
	cout << "ENCRYPTED : " << caeser.encrypt(msg) << endl;
	cout << "DECRYPYED : " << caeser.decrypt(msg) << endl;
	return 0;
}
