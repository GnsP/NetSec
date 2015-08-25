#include <iostream>
#include "modular.hpp"
using namespace std;
using namespace gnsp::NetSec::mod;

int main(){
    modular<7> a,b,c,d;
    a=3;
    b=8;
    c=-5;
    cout<<a()<<" "<<b()<<" "<<c()<<endl; // expected 3 1 2
    d = a+b;
    cout<<d()<<endl; //expected 4
    d=b-c;
    cout<<d()<<endl; //expected 6
    d=a*b;
    cout<<d()<<endl; //expected 3
    d=a.addInv();
    cout<<d()<<endl; //expected 4
    d=a.multInv();
    cout<<d()<<endl; //expected 5
    return 0;
}
