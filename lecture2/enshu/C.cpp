#include <iostream>
using namespace std;

double calcArea(double a, double b=0){
      // return (b > 0 ? a*b : a*a);
      if (b == 0){
            return a*a;
      } else {
            return a*b;
      }
}


int main(){
      double a = calcArea(3.0, 3.5);
      double b = calcArea(3.0);

      cout << "a, b = " << a << ", " << b << endl;

      return 0;
}