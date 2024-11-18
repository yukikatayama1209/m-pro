#include <iostream>
using namespace std;

struct Data{
      // 実数配列のポインタ
      double *data;
      // 配列の要素数
      int size;
};

void scaleData(
      // Data型への参照
      Data& d,
      // 定数
      double scale
)
{
      // Data型を定数倍
      for (int i=0; i<d.size; i++){
            d.data[i] *= scale;
      }
}

int main() {
    // 動的に配列を確保
    double *a = new double[5];

    // 配列の初期化
    for (int i = 0; i < 5; i++) {
        a[i] = i + 1;  // 1, 2, 3, 4, 5 と初期化
    }

    // Data構造体のインスタンスを作成
    Data d;
    d.data = a;
    d.size = 5;

    // スケーリングする定数
    double scale = 2.0;

    // 定数倍の関数を呼び出す
    scaleData(d, scale);

    // スケールされた結果を表示
    for (int i = 0; i < d.size; i++) {
        cout << d.data[i] << " ";  // 2.0, 4.0, 6.0, 8.0, 10.0 が出力されるはず
    }
    cout << endl;

    // 動的メモリの解放
    delete[] a;

    return 0;
}