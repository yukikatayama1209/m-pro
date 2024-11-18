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

// DoubleArrayクラスを継承して区間[xmin, xmax]の間を等間隔にサンプリングして得られる折れ線上の値を計算するPiecewiseLinearクラス
class PiecewiseLinear : public DoubleArray {
public:
    PiecewiseLinear(int n, double *data):
        DoubleArray(n+1) {
        for(int i=0; i<=n; i++) data[i] = data[i];
    }
    double calc(double x){
        int i = 0;
        while (i<array_size && x>data[i]) i++;
        if (i == 0) return data[0];
        if (i == array_size) return data[array_size];
        return data[i-1] + (x-data[i-1])/(data[i]-data[i-1]);
    }
};

int main(){
    double data[5] = {1, 2, 3, 2, 4};
    PiecewiseLinear f(4, data);

    for (int i=0; i<=10; i++){
        double x = double(i)/double(10);
        cout << x << ": " << f.calc(x) << endl;
    }
    return 0;
}