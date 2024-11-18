#include <iostream>
class Point3d{
    public:
        double x, y, z;
    Point3d(
        double x = 0,
        double y = 0,
        double z = 0 ) {
            this -> x = x;
            this -> y = y;
            this -> z = z;
        }
    Point3d operator=(
        Point3d p
    ){
        x = p.x;
        y = p.y;
        z = p.z;
        return *this;
    }
    Point3d operator++(){
        x++; y++; z++;
        return *this;
    }

};

