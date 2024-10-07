#include <stdio.h>
void k_Array(double arr[], int n, double k){
      for (int i = 0; i < n; i++){
            arr[i] *= k;
      }
}

int main(){
      int n;
      double k;
      scanf("%d", &n);
      double arr[n];
      for (int i = 0; i < n; i++){
            scanf("%lf", &arr[i]);
      }
      scanf("%lf", &k);
      k_Array(arr, n, k);
      for (int i = 0; i < n; i++){
            printf("%.2lf ", arr[i]);
      }
      printf("\n");
      return 0;
}