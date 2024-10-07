#include <stdio.h>
#include <iostream>
using namespace std;
int func1(int x, int y){
      return (x+y);
}

void func2(int& x, int& y){
      y *= 2;
      x = x * y;
}

int main(){
      int x = 1, y = 2;
      x = func1(x, y);
      std::cout << "x, y = " << x << ", " << y << std::endl;
      func2(x, y);
      cout << "x, y = " << x << ", " << y << endl;

      return(0);


}