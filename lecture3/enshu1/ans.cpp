#include <iostream>
#include "Vector2D.h"
using namespace std;
int main(){
      Vector2D v1(3.0, 4.0);
      Vector2D v2(2.0, -1.0);

      cout << "v1の(x座標, y座標) : (" << v1.getX() << ", " << v1.getY() << ")" << endl;
      cout << "v2の(x座標, y座標) : (" << v2.getX() << ", " << v2.getY() << ")" << endl;
      double dot_product = v1.dotProduct(v2);
      cout << "v1とv2の内積 : " << dot_product << endl;
      
      return 0;
}