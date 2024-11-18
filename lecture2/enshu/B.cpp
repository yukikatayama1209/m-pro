#include <iostream>
using namespace std;

int main(){
      const int N = 10;
      int *data = new int[N];
      for (int i=0; i<N; i++){
            data[i] = i;
      }

      int sum = 0;
      for (int i=0; i<N; i++){
            sum += data[i];
      }

      cout << "sum = " << sum << endl;

      delete[] data;
      return 0;
}