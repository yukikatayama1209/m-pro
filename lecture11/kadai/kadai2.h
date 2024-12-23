#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

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

unsigned char rgb_to_y(Color c) {
   return((unsigned char)(0.299 * c.r + 0.587 * c.g + 0.114 * c.b));
}

vector<int> calcHistogram(
    Image& image,
    int L
)
{
    vector<int> histogram(L, 0);
    for(int i=0; i<image.size(); i++) {
        Color uc = image[i];
        unsigned char y = rgb_to_y(uc);
        histogram[y]++;
    }
    return(histogram);
}

void printHistogram(
    vector<int> histogram
)
{
    for(int i=0; i<histogram.size(); i++) {
        printf("%d: ", i);
        for(int k=0; k<histogram[i]; k++) printf("*");
        printf("\n");
    }
}

void equalizeHistogram(
    Image&    image,
    int L
)
{
    int N = image.size();
    vector<int> histogram =  calcHistogram(image, L);
    for (int i = 0; i < image.size(); i++) {
        Color uc = image.at(i);
        unsigned char ys = rgb_to_y(uc);
        int n = 0;
        for (int j = 0; j <= ys; j++) n += histogram[j];
        unsigned char yd = (unsigned char)(double(L - 1)*double(n) / double(N));
        double s = double(yd) / double(ys);
        uc = uc * s;
        image.at(i) = uc;
    }
}
