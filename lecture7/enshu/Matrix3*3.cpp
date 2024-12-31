#include <iostream>
#include <vector>
using namespace std;

template <class X>
class Matrix3x3 : public vector<X>{
    public:
    Matrix3x3(){
        this->resize(9);
        for (int i=0; i<9; i++){
            this->at(i) = 0;
        }
    }
    X& operator()(int i, int j){
        return this->at(3*i + j);
    }
};

int main(){
    Matrix3x3<double> m;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            m(i, j) = i + j;
        }
    }
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout << m(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}