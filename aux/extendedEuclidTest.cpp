#include <iostream>
#include "extendedEuclid.hpp"

using namespace std;
using namespace gnsp::NetSec::aux;

int main(){
	cout << "TESTING EUCLIDEAN GCD ALGORITHM" << endl;
	cout << "gcd(4,10) = " << GCD(4,10) << endl;
	cout << "gcd(3,5) = " << GCD(3,5) << endl;
	cout << "gcd(6,7) = " << GCD(6,7) << endl;
	
	cout << "TESTING EXTENDED EUCLIDEAN ALGORITHM" << endl;
	cout << "a = 12, b = 9" << endl;
	extendedEuclideanEngine test(12, 9);
	cout << "GCD = " << test.getGCD() << endl;
	cout << "Bezout Coefficients = " << test.getBezoutCoeffs().first << " " << test.getBezoutCoeffs().second << endl;
	cout << "Quotients = " << test.getQuotients().first << " " << test.getQuotients().second << endl;
	return 0;
}
