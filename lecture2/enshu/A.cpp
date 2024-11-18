#include <iostream>
using namespace std;

int calcSum(int a[], int size){
      int sum = 0;
      for(int i = 0; i < size; i++){
            sum += a[i];
      }
      return sum;
}

double calcSum(double a[], int size){
      double sum = 0;
      for(int i = 0; i < size; i++){
            sum += a[i];
      }
      return sum;
}


int main(){
      int a[5] = {1, 2, 3, 4, 5};
      double b[3] = {1.1, 2.3, 3.5};
      cout << "sum a: " << calcSum(a, 5) << endl;
      cout << "sum b: " << calcSum(b, 3) << endl;

      return 0;
}