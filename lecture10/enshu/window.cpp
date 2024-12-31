#include <iostream>
#include <vector>
#include <complex>
#include "../Sound.h"
using namespace std;

vector<complex<double>> getFrame(
    SoundWave& wave, //入力波形
    int frame_id,    //フレーム番号
    int frame_size,  //フレームサイズ
    int shift_size   //シフトサイズ
)
{
    int start_id = frame_id * shift_size;
    vector<complex<double>> x;
    for(int i=start_id; i<start_id + frame_size; i++) {
        x.push_back(complex<double>(wave[i], 0));
    }
    return(x);
}

vector<complex<double>> multWindowFunc(
    vector<complex<double>>&    x
)
{
    const double PI = 3.1415926;
    int N = x.size();
    vector<complex<double>> xw(N);
    for(int i=0; i< N; i++) {
        double w = 0.5 - 0.5*cos(2.0*PI*(i+0.5)/double(N));
        xw[i] = w * x[i];
    }
    return(xw);
}


int main() {
    // パラメータ設定
    int frame_size = 1024; // フレームサイズ
    int sampling_rate = 44100; // サンプリングレート

    // 仮の入力波形データを生成（正弦波 + ゼロパディング）
    SoundWave wave(sampling_rate, 16, 1.0); // 1秒間の波形データ
    calcContactSound(wave);                 // 接触音の計算

    // 最初のフレームを取得
    vector<complex<double>> frame = getFrame(wave, 0, frame_size, frame_size);

    // 窓関数を適用
    vector<complex<double>> frame_windowed = multWindowFunc(frame);

    // 結果を表示（窓関数適用後のデータの一部を出力）
    cout << "Original frame:" << endl;
    for (int i = 0; i < min(10, (int)frame.size()); i++) {
        cout << frame[i] << endl;
    }

    cout << "\nWindowed frame:" << endl;
    for (int i = 0; i < min(10, (int)frame_windowed.size()); i++) {
        cout << frame_windowed[i] << endl;
    }

    return 0;
}