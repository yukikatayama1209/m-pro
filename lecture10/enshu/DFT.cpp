#include <iostream>
#include <vector>
#include <complex>
#include "../Sound.h"
using namespace std;


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

vector<complex<double>> idft(vector<complex<double>>& X) {
    const double PI = 3.1415926;
    int N = (int)X.size();
    vector<complex<double>> x(N, complex<double>(0, 0));
    for (int n = 0; n < N; n++) {
        for (int k = 0; k < N; k++) {
            double f = (double)(k*n)/(double)N;
            complex<double> e = exp(complex<double>(0, 2.0*PI*f));
            x[n] += X[k] * e;
        }
        x[n] /= (double)N;
    }
    return(x);
}

int main(void){
    SoundWave wave(16000, 16, 0.1);
    calcContactSound(wave);
    
    vector<complex<double>> x;
    for(int i=0; i<wave.size(); i++)
        x.push_back(complex<double>(wave[i], 0));
    vector<complex<double>> X = dft(x);
    double xmax = 0;
    for(int i=0; i<X.size(); i++)  xmax = max(abs(X[i]), xmax);
    for(int i=0; i<X.size(); i++) {
        if(abs(X[i])/xmax > 0.5) cout << i << " : " << X[i] << endl;
    }
    
    x = idft(X);
    for(int i=0; i<x.size(); i++) {
        cout << x[i].real() << ", " << wave[i] << endl;
    }   
}
