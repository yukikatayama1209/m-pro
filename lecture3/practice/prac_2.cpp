#include <iostream>
#include "prac.h"
using namespace std;

int main(){
    Polygon poly(4);

    poly.set(0, 0, 0);
    poly.set(1, 1, 0);
    poly.set(2, 1, 1);
    poly.set(3, 0, 1);

    for (int i=0; i<poly.getNumVerts(); i++){
        cout << poly.get
    }
}