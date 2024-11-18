#include <iostream>
using namespace std;

class DoubleArray {
protected:
    int array_size;
    double *data;
    void allocate_data(int n) {
        if(data != NULL) delete [] data;
        this->array_size = n;
        data = (n == 0) ? NULL : new double[n];
    }
public:
    DoubleArray(int size = 0) {
        data = NULL;
        allocate_data(size);
    }
    DoubleArray(const DoubleArray& a) {
        allocate_data(a.array_size);
        for(int i=0; i<a.array_size; i++) data[i] = a.data[i];
    }
    DoubleArray operator=(DoubleArray a) {
        allocate_data(a.array_size);
        for(int i=0; i<a.array_size; i++) data[i] = a.data[i];
        return(*this);
    }
    ~DoubleArray() {
        delete [] data;
    }
    int size() {
        return(array_size);
    }
};

class Matrix3x3 : public DoubleArray {
public:
    Matrix3x3() : DoubleArray(9) {}
    double& operator()(int i, int j){
        return (data[i*3+j]);
    }

};

int main(){
    Matrix3x3 m;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            m(i, j) = i+j;
        }
    }
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout << m(i, j) << " ";
        }
        cout << endl;
    }

}