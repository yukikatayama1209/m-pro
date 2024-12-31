#include <iostream>
using namespace std;

template <typename X>
double integrare(
    X *f, double a, double b
)
{
    const int N = 10;
    double dx = (b - a) /double(N);
    double s = 0;
    for (int i=0; i<N; i++){
        double x = (i+0.5) * dx;
    }
}

int main(){
    double s = integrate
}