#include <iostream>
using namespace std;

struct Vector2d{
      double x, y;
};

struct Vector2darray{
      Vector2d *data;
      int size;
};
void allocate(Vector2darray& v, int size){
      v.data = new Vector2d[size];
      v.size = size;
}
void release(Vector2darray& v){
      delete[] v.data;
      v.data = nullptr;
      v.size = 0;
}

int main() {
    // ベクトル配列を保持する構造体の宣言
    Vector2dArray vectors;

    // 要素数の指定
    int numVectors;
    cout << "Enter number of 2D vectors: ";
    cin >> numVectors;

    // 配列のメモリを動的に確保
    allocate(vectors, numVectors);

    // 2次元ベクトルに値を入力
    for (int i = 0; i < vectors.size; i++) {
        cout << "Enter x and y for vector " << i + 1 << ": ";
        cin >> vectors.data[i].x >> vectors.data[i].y;
    }

    // 入力されたベクトルを表示
    cout << "\nThe vectors are:" << endl;
    for (int i = 0; i < vectors.size; i++) {
        cout << "Vector " << i + 1 << ": (" << vectors.data[i].x << ", " << vectors.data[i].y << ")" << endl;
    }

    // 動的メモリの解放
    release(vectors);

    return 0;
}