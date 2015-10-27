#include "../vigenereCipher.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace gnsp::NetSec::crypto;

int main(){
	string msg;
	cin >> msg;
	cout << "MESSAGE : " << msg << endl;
	string key;
	cin >> key;
	cout << "KEY : " << key << endl;
	vigenereCipher<char> caeser(key);
	cout << "DECRYPYED : " << caeser.decrypt(msg) << endl;
	return 0;
}
