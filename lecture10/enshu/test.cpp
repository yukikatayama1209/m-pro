#include <iostream>
#include <vector>
#include <complex>
#include "../Sound.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;


class DPCM {
    double delta;
    double xp;
public:
    DPCM(int B, int R) {
        int B2 = 1;
        for (int i = 0; i < B; i++) B2 *= 2;
        delta = 2.0 * double(R) / double(B2);
        xp = 0.0;
    }

    int encode(int x) {
        double diff = x - xp;
        int c = static_cast<int>(round(diff / delta));
        xp += c * delta;
        return c;
    }
    int decode(int c) {
        xp += c * delta;
        return static_cast<int>(round(xp));
    }
    void clear() {
        xp = 0.0;
    }
};


// メイン関数
int main() {
    // パラメータ設定
    int B = 3, Rd = 4096;
    int B2 = 1;
    for (int i = 0; i < B; i++) B2 *= 2;
    double delta = 2.0 * Rd / B2;

    // SoundWave の生成と前処理
    SoundWave x(44100, 16, 0.5); // 44.1kHz, 16bit, 0.5秒の音声波形
    calcContactSound(x);         // 接触音の計算

    // 符号化用ベクター
    vector<int> c(x.size());

    // DPCM のインスタンス
    DPCM dpcm(3, 4096);

    // 符号化処理
    for (int i = 0; i < x.size(); i++) {
        c[i] = dpcm.encode(x[i]);
    }

    // 復号化処理
    dpcm.clear();
    SoundWave xc(x);
    for (int i = 0; i < xc.size(); i++) {
        xc[i] = dpcm.decode(c[i]);
    }

    // 誤差計算
    double err = 0;
    for (int i = 0; i < x.size(); i++) {
        err += pow(x[i] - xc[i], 2);
    }
    cout << "err = " << sqrt(err / double(x.size())) << endl;

    // WAV ファイルの保存
    saveWav("./output.wav", x, 44100, 16);
    cout << "WAVファイル 'output.wav' を作成しました。" << endl;

    return 0;
}