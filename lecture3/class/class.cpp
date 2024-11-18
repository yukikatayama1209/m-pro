#include <iostream>
#include "myclass.h"
using namespace std;

int main(){
      myclass ob;
      ob.setab(5);
      cout << ob.geta() << ", " << ob.b << endl;
      ob.b = 20;
      cout << ob.geta() << ", " << ob.b << endl;
      ob.reset();
      cout << ob.geta() << ", " << ob.b << endl;
      // ob.a = 1;

}