#include <vector>
#include <cmath>
#include <fstream>
#include <cstdint>
using namespace std;

class SoundWave : public vector<int> {
    public:
    int samplingRate;
    int numSampleBit;
    SoundWave(
        int rate = 0,
        int bit = 0,
        double t = 0) : vector<int>(int(rate*t)) {
            samplingRate = rate;
            numSampleBit = bit;
        }
    SoundWave(const SoundWave& s) {
        samplingRate = s.samplingRate;
        numSampleBit = s.numSampleBit;
        vector<int>::operator=(s);
    }
    int getSamplingRate() {
        return(samplingRate);
    }
    int getNumSampleBit() {
        return(numSampleBit);
    }
};
void calcDecayedSineWave(
    SoundWave& wave,
    double a0,
    double f,
    double decay
)
{
    const double PI = 3.1415926;
    double dt = 1.0 / double(wave.getSamplingRate());
    for (int i = 0; i < wave.size(); i++) {
        double t = (i + 0.5) * dt;
        double s = a0 * sin(2.0 * PI * f * t) * exp(-decay * t);
        wave[i] = (int)s;
    }
}

void calcContactSound(SoundWave& wave)
{
    SoundWave tmp(wave.getSamplingRate(),
        wave.getNumSampleBit(),
        double(wave.size())/double(wave.getSamplingRate()));

    int N = 10;
    for (int i = 0; i < N; i++) {
        double f = double(rand()) / double(RAND_MAX) * 4000 + 100;
        double a0 = double(rand()) / double(RAND_MAX) * 100000/N;
        double decay = double(rand()) / double(RAND_MAX) * 2 + 3;
        calcDecayedSineWave(tmp, a0, f, decay);
        for (int j = 0; j < wave.size(); j++) wave[j] += tmp[j];
    }
}


// WAV ファイルに保存する関数
void saveWav(const string& filename, const SoundWave& wave, int sampleRate, int bitDepth) {
    ofstream file(filename, ios::binary);

    int numSamples = wave.size();
    int subchunk2Size = numSamples * (bitDepth / 8);
    int chunkSize = 36 + subchunk2Size;

    // WAV ヘッダ
    file.write("RIFF", 4);
    file.write(reinterpret_cast<const char*>(&chunkSize), 4);
    file.write("WAVE", 4);
    file.write("fmt ", 4);
    int subchunk1Size = 16;
    file.write(reinterpret_cast<const char*>(&subchunk1Size), 4);
    int audioFormat = 1;
    file.write(reinterpret_cast<const char*>(&audioFormat), 2);
    int numChannels = 1; // モノラル
    file.write(reinterpret_cast<const char*>(&numChannels), 2);
    file.write(reinterpret_cast<const char*>(&sampleRate), 4);
    int byteRate = sampleRate * (bitDepth / 8);
    file.write(reinterpret_cast<const char*>(&byteRate), 4);
    int blockAlign = (bitDepth / 8);
    file.write(reinterpret_cast<const char*>(&blockAlign), 2);
    file.write(reinterpret_cast<const char*>(&bitDepth), 2);
    file.write("data", 4);
    file.write(reinterpret_cast<const char*>(&subchunk2Size), 4);

    // PCM データ
    for (const auto& sample : wave) {
        int16_t value = static_cast<int16_t>(sample);
        file.write(reinterpret_cast<const char*>(&value), 2);
    }
    file.close();
}