#include "./kadai2.h"

int main(void){
    const int NUM_LEVEL = 32;
    Image image(16, 4);
    drawGradation(
        image,
        Color(0,0,0),
        Color(NUM_LEVEL/2, NUM_LEVEL/2, NUM_LEVEL/2));
    
    Image equated = image;
    equalizeHistogram(equated, NUM_LEVEL);
    print(image);
    cout << "---"<< endl; 
    print(equated);

    cout << "---"<< endl; 
    printHistogram(calcHistogram(image, NUM_LEVEL));
    cout << "---"<< endl; 
    printHistogram(calcHistogram(equated, NUM_LEVEL));
    cout << "---"<< endl; 
}
