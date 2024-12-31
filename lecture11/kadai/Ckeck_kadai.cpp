#include <iostream>
#include <vector>
#include "../enshu/Class_Fuck.h"

int main(){
    Image image(5, 5);
    drawChecker(image, 4, Color(32, 32, 32), Color(16, 16, 16));
    vector<double> h = {
        0, -1, 0,
        -1, 4, -1,
        0, -1, 0
    };
    Image output = applyFilter(image, h, 3);
    print(output);

    return 0;
}