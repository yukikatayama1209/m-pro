#include <stdio.h>
double calcSum( double *a, int n){
      double sum = 0.0;
      for (int i = 0; i < n; i++){
            sum += a[i];
      }
      return sum;
}

int main(){
      int n;
      scanf("%d", &n);
      double *a;;
      for (int i = 0; i < n; i++){
            scanf("%lf", &a[i]);
      }
      printf("%.2lf\n", sumArray(a, n));
      return 0;
}