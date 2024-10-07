#include  <stdio.h>
#include <iostream>
using namespace std;

void process(int x, int y) {
      cout << "(1)";
}
void process(double x, double y) {
      cout << "(2)";
}
void process(int x, double y) {
      cout << "(3)";
}

int main() {
      int a = 1, b = 2;
      double x = 1, y = 2;
      process(1, 2);
      process(a, b);
      process(x, y);
      process(a, x);
      cout << endl;

      return(0);
}