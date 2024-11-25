template <class X>
class Matrix : public vector<X> {
    int r, c;

public:
    Matrix(int rows, int cols) : r(rows), c(cols) {
        this->resize(rows * cols);
        for (int i = 0; i < rows * cols; i++) {
            this->at(i) = 0;
        }
    }
    int rows() const {
        return r;
    }
    int cols() const {
        return c;
    }
    X& operator()(int i, int j) {
        if (i < 0 || i >= r || j < 0 || j >= c) {
            throw out_of_range("Index out of range");
        }
        return this->at(i * c + j);
    }
    const X& operator()(int i, int j) const {
        if (i < 0 || i >= r || j < 0 || j >= c) {
            throw out_of_range("Index out of range");
        }
        return this->at(i * c + j);
    }
};