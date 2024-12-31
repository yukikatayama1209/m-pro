#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#include "../Sound.h"

vector<complex<double>> dft(vector<complex<double>>& x) {
    const double PI = 3.1415926;
    int N = (int)x.size();
    vector<complex<double>> X(N);
    for (int k = 0; k < N; k++) {
        X[k] = complex<double>(0.0, 0.0);
        for (int n = 0; n < N; n++) {
            double f = (double)(k*n)/(double)N;
            complex<double> e = exp(complex<double>(0, -2.0*PI*f));
            X[k] += x[n]*e;
        }
    }
    return(X);
}


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



class Spectrogram : public vector<complex<double>> {
private:
    int frame_size;
    int num_frame;

public:
    Spectrogram(SoundWave& wave, int f, int s) {
        frame_size = f;
        num_frame = (wave.size() - frame_size) / s;
        for (int k = 0; k < num_frame; k++) {
            vector<complex<double>> x = getFrame(wave, k, frame_size, s);
            vector<complex<double>> xw = multWindowFunc(x);
            vector<complex<double>> X = dft(xw);
            for (int i = 0; i < X.size(); i++) {
                push_back(X[i]);
            }
        }
    }
    complex<double> operator()(int frame, int freq) {
        return (*this)[frame * frame_size + freq];
    }
    int getFrameSize() {
        return frame_size;
    }
    int getNumFrame() {
        return num_frame;
    }
};


int main(void){
    const int frame_size = 128;
    const int shift_size = 64;
    SoundWave wave(16000, 16, 0.1);
    calcContactSound(wave);
    
    Spectrogram s(wave, frame_size, shift_size);
    int num_frame =  s.size()/frame_size;
    double smax = 0;
    for(int i=0; i<s.size(); i++) smax = max(smax, abs(s[i]));
    cout << "smax = " << smax << endl;
    for(int i=0; i<num_frame; i++) {
        for(int j=0; j<frame_size/2; j++) {
            double a =  abs(s[i*frame_size+j])/smax;
            char c = (a > 0.4) ? '*' : '.';
            cout << c;
        }
        cout << endl;
    }
}
