#include "../enshu/Class_Fuck.h"

class Filter {
private:
    int size;
    vector<double> matrix;

public:
    Filter(int size, vector<double> h) : size(size), matrix(h) {
        if (h.size() != size * size) {
            cerr << "Error: Filter matrix size does not match filter dimensions!" << endl;
            exit(1);
        }
    }

    Image operator*(Image& input) {
        Image output = input;

        for (int iy = size / 2; iy < input.getHeight() - size / 2; iy++) {
            for (int ix = size / 2; ix < input.getWidth() - size / 2; ix++) {
                double sr = 0, sg = 0, sb = 0;
                int k = 0;

                for (int j = iy - size / 2; j <= iy + size / 2; j++) {
                    for (int i = ix - size / 2; i <= ix + size / 2; i++) {
                        Color c = input.getPixel(i, j);
                        sr += matrix[k] * double(c.r);
                        sg += matrix[k] * double(c.g);
                        sb += matrix[k] * double(c.b);
                        k++;
                    }
                }

                output.setPixel(ix, iy, Color(sr, sg, sb));
            }
        }

        return output;
    }
};

int main(){
    Image image(5, 5);
    drawChecker(image, 4, Color(32, 32, 32), Color(16, 16, 16));
    vector<double> h = {
        0, -1, 0,
        -1, 4, -1,
        0, -1, 0
    };
    Filter filter(3, h);
    Image output = filter * image;
    print(output);

    return 0;
}