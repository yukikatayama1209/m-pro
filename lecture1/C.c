#include <stdio.h>
double sumArray(double arr[], int n){
      double sum = 0;
      for (int i = 0; i < n; i++){
            sum += arr[i];
      }
      return sum;
}

int main(){
      int n;
      scanf("%d", &n);
      double arr[n];
      for (int i = 0; i < n; i++){
            scanf("%lf", &arr[i]);
      }
      printf("%.2lf\n", sumArray(arr, n));
      return 0;
}