#include "../multiplicativeCipher.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace gnsp::NetSec::crypto;

int main(){
	string msg = "\'Et tu Brute\'... And thus caeser fell";
	cout << "MESSAGE : " << msg << endl;
	multiplicativeCipher<char> test(3);
	cout << "ENCRYPTED : " << test.encrypt(msg) << endl;
	cout << "DECRYPYED : " << test.decrypt(msg) << endl;
	return 0;
}
