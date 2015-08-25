#include <iostream>
#include <string>
#include "util.hpp"
using namespace std;
using namespace gnsp::NetSec::crypto::util;

int main(){
	string pt = "This is an example of a plain text string.";
	cout << format(pt) << endl;
	return 0;
}
