#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Colord {
    public:
    double r, g, b;
    
    Colord(double r = 0, double g = 0, double b = 0) {
        this->r = r;
        this->g = g;
        this->b = b;
    }
    Colord operator*(double s) {
        return(Colord(r*s, g*s, b*s));
    }
    Colord operator+(Colord c) {
        return(Colord(r+c.r, g+c.g, b+c.b));
    }
};

class Imaged : public vector<Colord> {
    private:
    int width, height;
    public:
    Imaged(int w, int h) : vector<Colord>(w * h) {
        width = w;
        height = h;
    }
    Imaged(const Imaged& image) {
        width = image.width;
        height = image.height;
        vector<Colord>::operator=(image);
    }
    int getWidth() {
        return(width);
    }
    int getHeight() {
        return(height);
    }
    Colord getPixel(int i, int j) {
        return(this->at(j*width + i));
    }
    void setPixel(int i, int j, Colord c) {
        this->at(j*width + i) = c;
    }
    Imaged operator=(const Imaged& image) {
        width = image.width;
        height = image.height;
        vector<Colord>::operator=(image);
        return(*this);
    }
    void clear(Colord c) {
        for(int i=0; i<this->size(); i++) this->at(i) = c;
    }
};



void drawGradation(
    Imaged& image,
    Colord color1,
    Colord color2)
{
    for(int j=0; j<image.getHeight(); j++) {
        for(int i=0; i<image.getWidth(); i++) {
            double a = double(i)/double(image.getWidth()-1);
            Colord c = color1 * (1-a) + color2 * a;
            image.setPixel(i, j, c);
        }
    }
}

void print(Imaged& image) {
    for(int j=0; j<image.getHeight(); j++) {
        for(int i=0; i<image.getWidth(); i++) {
            printf("%2d ", int(image.getPixel(i, j).r));
        }
        printf("\n");
    }
}

Imaged applyFilter(
    Imaged& input,
    Imaged& mask,
    vector<double>& matrix,
    int size
) {
    Imaged output = input;
    for (int iy = size/2; iy < input.getHeight()-size/2; iy++) {
        for (int ix = size/2; ix < input.getWidth()-size/2; ix++) {
            if (mask.getPixel(ix, iy).r > 0) {
                double sr = 0, sg = 0, sb = 0;
                int k = 0;
                for (int j = iy - size / 2; j <= iy + size / 2; j++) {
                    for (int i = ix - size / 2; i <= ix + size / 2; i++) {
                        Colord c = input.getPixel(i, j);
                        sr += matrix[k] * double(c.r);
                        sg += matrix[k] * double(c.g);
                        sb += matrix[k] * double(c.b);
                        k++;
                    }
                }
                output.setPixel(ix, iy, Colord(sr, sg, sb));
            }
        }
    }
    return(output);
}
