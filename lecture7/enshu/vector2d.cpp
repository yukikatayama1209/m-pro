#include <iostream>
using namespace std;

template <class Ty>
class Vector2d(double x, double y){
    publuc:
        double x, y;
    Vector2d(double x=0, double y=0){
        this ->x = x;
        this ->y = y;
    }
    Vector2d operator+(const Vector2d &v){
        return Vector2d(x + v.x, y + v.y);
    }
    Vector2d operator-(const Vector2d &v){
        return Vector2d(x - v.x, y - v.y);
    }
};

int main(){
    
}