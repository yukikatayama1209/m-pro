#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

// SoundWave クラス
class SoundWave : public vector<int> {
private:
    int samplingRate; // サンプリングレート
    int numSampleBit; // サンプルビット数
public:
    // コンストラクタ
    SoundWave(int rate = 0, int bit = 0, double t = 0)
        : vector<int>(int(rate * t)) {
        samplingRate = rate;
        numSampleBit = bit;
    }

    // コピーコンストラクタ
    SoundWave(const SoundWave& s) {
        samplingRate = s.samplingRate;
        numSampleBit = s.numSampleBit;
        vector<int>::operator=(s);
    }

    // サンプリングレート取得
    int getSamplingRate() {
        return samplingRate;
    }

    // サンプルビット数取得
    int getNumSampleBit() {
        return numSampleBit;
    }
};

// 減衰正弦波の計算（仮実装）
void calcDecayedSineWave(SoundWave& wave, double a0, double f, double decay) {
    for (int i = 0; i < wave.size(); i++) {
        double t = double(i) / wave.getSamplingRate();
        wave[i] += static_cast<int>(a0 * sin(2.0 * M_PI * f * t) * exp(-decay * t));
    }
}

// calcContactSound 関数
void calcContactSound(SoundWave& wave) {
    SoundWave tmp(wave.getSamplingRate(), wave.getNumSampleBit(),
                  double(wave.size()) / double(wave.getSamplingRate()));

    int N = 10; // 符号化用波の数
    for (int i = 0; i < N; i++) {
        double f = double(rand()) / double(RAND_MAX) * 4000 + 100;
        double a0 = double(rand()) / double(RAND_MAX) * 100000 / N;
        double decay = double(rand()) / double(RAND_MAX) * 2 + 3;
        calcDecayedSineWave(tmp, a0, f, decay);
        for (int j = 0; j < wave.size(); j++) wave[j] += tmp[j];
    }
}

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

    return 0;
}
