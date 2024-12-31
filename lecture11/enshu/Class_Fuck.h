#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
using namespace std;

// RGB color class
class Color {
    public:
    unsigned char r, g, b;
    
    Color(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0) {
        this->r = r;
        this->g = g;
        this->b = b;
    }
    Color operator*(double s) {
        return(Color(r*s, g*s, b*s));
    }
    Color operator+(Color c) {
        return(Color(r+c.r, g+c.g, b+c.b));
    }
};

// Image class
class Image : public vector<Color> {
    private:
    int width, height;
    public:
    Image(int w, int h) : vector<Color>(w * h) {
        width = w;
        height = h;
    }
    Image(const Image& image) {
        width = image.width;
        height = image.height;
        vector<Color>::operator=(image);
    }
    int getWidth() { 
        return(width); 
    }
    int getHeight() {
        return(height);
    }
    Color getPixel(int i, int j) {
        return(this->at(j*width + i));
    }
    void setPixel(int i, int j, Color c) {
        this->at(j*width + i) = c;
    }
    Image operator=(const Image& image) {
        width = image.width;
        height = image.height;
        vector<Color>::operator=(image);
        return(*this);
    }
    void clear(Color c) {
        for(int i=0; i<this->size(); i++) this->at(i) = c;
    }
};

// Draw checker pattern
void drawChecker(Image& image, int size, Color color1, Color color2) {
    for (int j = 0; j < image.getHeight(); j++) {
        for (int i = 0; i < image.getWidth(); i++) {
            Color c;
            if ((i / size + j / size) % 2) {
                image.setPixel(i, j, color1);
            }
            else {
                image.setPixel(i, j, color2);
            }
        }
    }
}

// Draw gradation
void drawGradation(Image& image, Color color1, Color color2) {
    for(int j=0; j<image.getHeight(); j++) {
        for(int i=0; i<image.getWidth(); i++) {
            double a = double(i)/double(image.getWidth()-1);
            Color c = color1 * (1-a) + color2 * a;
            image.setPixel(i, j, c);
        }
    }
}

void print(Image& image) {
    for(int j=0; j<image.getHeight(); j++) {
        for(int i=0; i<image.getWidth(); i++) {
            printf("%4d ", int(image.getPixel(i, j).r));
        }
        printf("\n");
    }
}


// Draw circle
void linearTransform(Image& image, double a, double b) {
    for (int i = 0; i < image.size(); i++) {
        image[i] = image[i] * a + Color(1, 1, 1) * b;
    }
}


// Draw circle
unsigned char rgb_to_y(Color c) {
   return((unsigned char)(0.299 * c.r + 0.587 * c.g + 0.114 * c.b));
}

// Binarize image
void binarize(Image& image, unsigned char thresh) {
    const Color black(0, 0, 0), white(255, 255, 255);
    for(int i=0; i<image.size(); i++) {
        image[i] = (rgb_to_y(image[i]) < thresh) ? black : white;
    }
}

// Quantize color
unsigned char quantize(unsigned char uc, int level) {
    double delta = 256.0/double(level);
    int k = (double)uc/delta;
    return((unsigned char)(k * delta));
}

// Posterize image
void posterize(Image& image, int level) {
    for(int i=0; i<image.size(); i++) {
            Color c = image[i];
            c.r = quantize(c.r, level);
            c.g = quantize(c.g, level);
            c.b = quantize(c.b, level);
            image[i] = c;
    }
}

// Apply filter
Image applyFilter(Image& input, vector<double>& matrix, int size) {
    Image output = input;
    for (int iy = size/2; iy < input.getHeight()-size/2; iy++) {
        for (int ix = size/2; ix < input.getWidth()-size/2; ix++) {
            double sr = 0, sg = 0, sb = 0;
            int k = 0;
            for (int j = iy - size/2; j <= iy + size/2; j++) {
                for (int i = ix - size/2; i <= ix + size/2; i++) {
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
    return(output);
}


// Apply median filter
Image applyMedianFilter(Image& input, int size) {
    Image output = input;
    for (int iy = size / 2; iy < input.getHeight() - size / 2; iy++) {
        for (int ix = size / 2; ix < input.getWidth() - size / 2; ix++) {
            vector<Color> cc;
            for (int j = iy - size / 2; j <= iy + size / 2; j++) {
                for (int i = ix - size / 2; i <= ix + size / 2; i++) {
                    cc.push_back(input.getPixel(i, j));
                }
            }
            for (int j = 0; j < cc.size(); j++) {
                for (int i = j + 1; i < cc.size(); i++) {
                    if (rgb_to_y(cc[j]) < rgb_to_y(cc[i])) {
                        swap(cc[j], cc[i]);
                    }
                }
            }
            output.setPixel(ix, iy, cc[cc.size() / 2]);
        }
    }
    return(output);
}
