// #include <iostream>

// class Vector2D{
//     private: double x;
//     private: double y;

//     public:

//     void set(double x0, double y0) {
//         x = x0;
//         y = y0;
//     }
//     Vector2D(double x0, double y0 = 0) {
//         this -> x = x0;
//         this -> y = y0;

//     }
//     double getX() const{
//         return x;
//     }
//     double getY() const {
//         return y;
//     }

//     double dotProduct(const Vector2D& other) const {
//         return (x * other.x) + (y * other.y);
//     }
// };

// // 多角形を表すPolygonクラス
// class Polygon{
//     private:
//         int num_verts;
//         Vector2D *verts;
//     public:
//         Polygon(int n){
//             this->num_verts = n;
//             verts = new Vector2D[n];
//         }
//         ~Polygon(){
//             delete [] verts;
//         }
//         int getNumVerts() {
//             return num_verts;
//         }
//         Vector2D get(int i){
//             return verts[i];
//         }
//         void set(int i, double x, double y){
//             verts[i].set(x, y);
//         }
//         void set(int i)

// };

class Complex{
    private:
        double re;
        double im;
    public:
        Complex(double re0 = 0, double im0 = 0){
            this -> re = re0;
            this -> im = im0;
        }

        double getRe() const{
            return re;
        }
        double getIm() const{
            return im;
        }
};


