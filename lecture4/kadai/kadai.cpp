#include <iostream>
using namespace std;
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
        Complex operator+(
            Complex c
        ){
            Complex temp;
            temp.re = re + c.re;
            temp.im = im + c.im;
            return temp;
        }
        Complex operator*(
            Complex c
        ){
            Complex temp;
            temp.re = re * c.re - im * c.im;
            temp.im = re * c.im + im * c.re;
            return temp;
        }
        Complex operator=(
            Complex c
        ){
            re = c.re;
            im = c.im;
            return *this;
        }
};

int main() {
    Complex c1(2, 3);  // 2 + 3i
    Complex c2(4, -1); // 4 - i

    // = 演算子
    Complex c3;
    c3 = c1;
    cout << "c3 = (" << c3.getRe() << ", " << c3.getIm() << "i)" << endl;

    // + 演算子
    Complex c4 = c1 + c2;
    cout << "c1 + c2 = (" << c4.getRe() << ", " << c4.getIm() << "i)" << endl;

    // * 演算子
    Complex c5 = c1 * c2;
    cout << "c1 * c2 = (" << c5.getRe() << ", " << c5.getIm() << "i)" << endl;

    return 0;
}