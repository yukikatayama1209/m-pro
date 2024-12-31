#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
using namespace std;
#include "./Class_Fuck.h"

int main(void){
    Image image(8, 8);
    drawGradation(image, Color(0,0,0), Color(64, 64, 64));
    print(image); 
    cout << "-----" << endl;
    linearTransform(image, 3, 10);
    print(image); 
    cout << "-----" << endl;
    posterize(image, 4);
    print(image); 
    cout << "-----" << endl;
    binarize(image, 64);
    print(image); 
    
    return(0);
}
