#include <stdio.h>
double max1(double a, double b){
      if (a > b){
            return a;
      }
      else{
            return b;
            }
      }

int main (){
      double a;
      double b;
      scanf("%f", &a);
      scanf("%f", &b);
      printf("%.2f\n", max1(a, b));
      return 0;
}