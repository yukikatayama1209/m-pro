#include <iostream>
#include <cmath>
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

class Polynomial : public DoubleArray {
public:
    Polynomial(int degree, double *coeff):
        DoubleArray(degree+1) {
        for(int i=0; i<=degree; i++) data[i] = coeff[i];
    }
    double calc(double x){
        double result = data[0];
        for(int i=0; i<=array_size; i++){
            result += data[i] * pow(x, double(i));
        }
        return result;
    }
    int degree(){
        return array_size-1;
    }
};


int main(){
    double c[4] = {1, 2, 3, 4};
    Polynomial f(3, c);

    cout << f.degree() << endl;
    cout << f.calc(0.5) << endl;
}