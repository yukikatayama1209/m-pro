#include <iostream>
#include <cmath>
using namespace std;

class Vector2d {
    public:
    double x, y;

    Vector2d(
        double x = 0,
        double y = 0)
    {
        this -> x = x;
        this -> y = y;

    }
    Vector2d operator=(
        Vector2d v
    ){
        x = v.x;
        y = v.y;
        return *this;
    }
    Vector2d operator+(
        Vector2d v
    ){
        Vector2d temp;
        temp.x = x + v.x;
        temp.y = y + v.y;
        return temp;
    }
    Vector2d operator-(
        Vector2d v
    ){
        Vector2d temp;
        temp.x = x - v.x;
        temp.y = y - v.y;
        return temp;
    }
    bool operator!=(
        Vector2d v
    ){
        return (x != v.x) || (y != v.y);
    }
    Vector2d operator*=(
        double s
    ){
        x *= s;
        y *= s;
        return *this;
    }
    Vector2d operator/(
        double s
    ){
        Vector2d temp;
        temp.x = x / s;
        temp.y = y / s;
        return temp;
    }
    Vector2d operator*(
        double s
    ){
        Vector2d temp;
        temp.x = x * s;
        temp.y = y * s;
        return temp;
    }
    
    
    
    
    double abs(Vector2d v){
        return sqrt(v.x * v.x + v.y * v.y);
    }

    friend Vector2d operator+(
        double s,
        Vector2d v
    );
    friend Vector2d operator-(
        double s,
        Vector2d v
    );
    Vector2d operator-(){
        Vector2d temp;
        temp.x = -x;
        temp.y = -y;
        return temp;
    }

};

int main(){
    Vector2d a(1, 2), b(3, 4), c(5, 6);
    Vector2d d = a + b - c;

    if (a != b){
        d *= 2;
    }else{
        d *= 4;
    }

    Vector2d e = 2.0 * a + b / 3.0;
    Vector2d f = -e;

    double s = abs(f);

    return 0;

}