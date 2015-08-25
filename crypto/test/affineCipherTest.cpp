#include "../affineCipher.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace gnsp::NetSec::crypto;

int main(){
	string msg = "\'Et tu Brute\'... And thus caeser fell";
	cout << "MESSAGE : " << msg << endl;
	affineCipher<char> caeser(3,3);
	cout << "ENCRYPTED : " << caeser.encrypt(msg) << endl;
	cout << "DECRYPYED : " << caeser.decrypt(msg) << endl;
	return 0;
}
