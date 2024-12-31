#include "./Class_Fuck.h"

int main(void) {
    Color black(0, 0, 0);
    Color white(255, 255, 255);
    Image image(16, 16);
    drawGradation(image, Color(0,0,0), Color(128, 128, 128));
    for (int j = 1; j < image.getHeight() - 1; j++) {
        for (int i = 1; i < image.getWidth() - 1; i++) {
            double x = (double)rand() / (double)RAND_MAX;
            if (x < 0.1)
                image.setPixel(i, j, white);
        }
    }
    print(image);

    Image output = applyMedianFilter(image, 3);
    cout << "-----" << endl;
    print(output);

    return 0;
}
