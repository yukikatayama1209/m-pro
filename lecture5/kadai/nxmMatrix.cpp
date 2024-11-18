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
    double& at(int i) {
        return(data[i]);
    }
};

// class Matrix : public DoubleArray {
// private:
//     int num_rows;
//     int num_cols;

// public:
//     Matrix(int rows, int cols) : DoubleArray(rows * cols), num_rows(rows), num_cols(cols) {}

//     int rows() const {
//         return num_rows;
//     }

//     int cols() const {
//         return num_cols;
//     }

//     double &at(int i, int j) {
//         return DoubleArray::at(i * num_cols + j);
//     }

//     const double &at(int i, int j) const {
//         return const_cast<Matrix *>(this)->at(i, j);
//     }
// };

class Matrix : public DoubleArray {
private:
    int num_rows;
    int num_cols;

public:
    Matrix(int rows, int cols) : DoubleArray(rows * cols), num_rows(rows), num_cols(cols) {}
    int rows() const {
        return num_rows;
    }
    int cols() const {
        return num_cols;
    }
    double &at(int i, int j) {
        return data[i * num_cols + j];
    }

    const double &at(int i, int j) const {
        return data[i * num_cols + j];
    }
};

int main(){
    Matrix m(5, 9);
    for (int i=0; i<m.rows(); i++){
        for (int j=0; j<m.cols(); j++){
            m.at(i, j) = (i+1)*10 + j + 1;
        }
    }
    for (int i=0; i<m.rows(); i++){
        for (int j=0; j<m.cols(); j++){
            cout << m.at(i, j) << " ";
        }
        cout << endl;
    }
}