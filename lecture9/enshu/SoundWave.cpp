#include <iostream>
#include <vector>
#include <cmath>

class SoundWave : public vector<int> {
    private:
    int samplingRate;
    int numSampleBit;
    public:
    SoundWave(
        int rate = 0,
        int bit = 0,
        double t = 0
    )
    : vector<int>(int(rate * t)) {
        samplingRate = rate;
        numSampleBit = bit;
    }
    SoundWave(const SoundWave& s) {
        samplingRate = s.samplingRate;
        numSampleBit = s.numSampleBit;
        vector<int>::operator=(s);
    }
    int getSamplingRate() const {
        return samplingRate;
    }
    int getNumSampleBit() const {
        return numSampleBit;
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
        double t = (double)i * dt;
        double s = a0 * sin(2.0 * PI * f * t) * exp(-decay * t);
        wave[i] = (int)s;
    }
}
int main() {
    SoundWave wave(44100, 16, 1.0);
    calcDecayedSinWave(wave, 440, 0.999);
    return 0;
}