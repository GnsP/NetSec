#include "../playfairCipher.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace gnsp::NetSec::crypto;

int main(){
	string msg = "Hide the gold in the tree Stump";
	cout << "MESSAGE : " << msg << endl;
	playfairCipher<char> pfCipher("playfair example");
	cout << "CIPHER CONSTRUCTED"<< endl;
	cout << "ENCRYPTED : " << pfCipher.encrypt(msg) << endl;
	cout << "DECRYPYED : " << pfCipher.decrypt(msg) << endl;
	return 0;
}
