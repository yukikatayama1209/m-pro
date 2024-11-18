#include <stdio.h>
#include <iostream>
using namespace std;

int sub(const int x, const int y){
      return (x - y);
}

int mul(int& x, int& y){
      return (x * y);
}

int main(){
      int x = 1, y = 3;
      int a = sub(x, y);
      int b = mul(x, y);
      x = sub(a, b);
      y = mul(a, b);
      cout << "x, y = " << x << ", " << y << endl;
      return(0);
}