#include "../shiftCipher.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace gnsp::NetSec::crypto;

int main(){
	string msg = "\'Et tu Brute\'... And thus caeser fell";
	cout << "MESSAGE : " << msg << endl;
	shiftCipher<char> caeser(3);
	cout << "ENCRYPTED : " << caeser.encrypt(msg) << endl;
	cout << "DECRYPYED : " << caeser.decrypt(msg) << endl;
	return 0;
}
