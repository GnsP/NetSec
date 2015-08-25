#include <iostream>
#include "extendedEuclid.hpp"

using namespace std;
using namespace gnsp::NetSec::aux;

int main(){
	extendedEuclideanEngine test(12, 9);
	cout << test.getGCD() << endl;
	cout << test.getBezoutCoeffs().first << " " << test.getBezoutCoeffs().second << endl;
	cout << test.getQuotients().first << " " << test.getQuotients().second << endl;
	return 0;
}
