#include <iostream>
#include "overload.h"
using namespace std;

int main(){
    Point3d a(1, 2, 3);
    Point3d c;

    c = a;
    cout << c.x << " " << c.y << " " << c.z << endl;
    return 0;
}