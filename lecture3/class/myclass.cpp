#include "myclass.h"

void myclass::setab(int i){
      a = i;
      b = i*i;
}
int myclass::geta(){
      return a;
}

void myclass::reset(){
      setab(0);
}