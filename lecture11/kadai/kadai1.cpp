#include "./kadai.h"

int main(void){
    Imaged image(16, 16), output(16, 16);
    Imaged mask(16,16);
    drawGradation(image, Colord(0, 0, 0), Colord(32, 32, 32));
    mask.clear(Colord(0, 0, 0));
    for(int j=4; j<12; j++) {
        for(int i=4; i<12; i++) {
            image.setPixel(i, j, Colord(0,0,0));
            mask.setPixel(i, j, Colord(1, 1, 1));
        }
    }
    print(image);
    Imaged* ptr_image[2] = { new Imaged(image), new Imaged(image) };
    vector<double> h = {
        0, 1.0/4.0, 0,
        1.0/4.0, 0, 1.0/4.0,
        0, 1.0/4.0, 0
    };
    const int num_iter = 50;
    for(int i=0; i<num_iter; i++) {
        *ptr_image[1] = applyFilter(*ptr_image[0], mask, h, 3);
        swap(ptr_image[0], ptr_image[1]);
    }
    cout << "----" << endl;
    print(*ptr_image[0]);    
    
    delete ptr_image[0];
    delete ptr_image[1];

    return(0);
}
