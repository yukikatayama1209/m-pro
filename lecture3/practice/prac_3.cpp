#include <iostream>
#include "prac.h"
using namespace std;

int main(){
    Complex c(1.4, 2);
    cout << "cの実部 : " << c.getRe() << endl;
    cout << "cの虚部 : " << c.getIm() << "j" << endl;

    return 0;
}