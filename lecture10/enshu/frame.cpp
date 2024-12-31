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

int main() {
    // 波形データを生成
    SoundWave wave(44100, 16, 1.0); // 1秒間の波形データ (44.1kHz, 16bit)
    calcContactSound(wave);         // 接触音を生成

    // フレーム設定
    int frame_size = 1024; // フレームサイズ
    int shift_size = 512;  // シフトサイズ

    // フレーム番号を指定して取得
    int frame_id = 0;
    vector<complex<double>> frame = getFrame(wave, frame_id, frame_size, shift_size);

    // 結果の出力（フレーム内の最初の10サンプルを表示）
    cout << "Frame " << frame_id << ":" << endl;
    for (int i = 0; i < 10 && i < frame.size(); i++) {
        cout << frame[i] << endl;
    }

    return 0;
}