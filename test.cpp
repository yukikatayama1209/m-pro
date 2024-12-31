class Spectrogram: public vector<complex<double>> ‹
privacte
int frame_size;
int num_frame;
public:
Spectrogram(SoundWave& wave, int f, int s) {
Trame Saze T
num_frame = (wave.size() -frame_size)/s;
vector<complex<double>> x, xw,
tor int k=o: K<num trame: K++) 1
x = getFrame (wave, k,
frame_size, s);
for (int 1=0; i<x.size();
itt) f
this-›push_back(X[i]);
｝
complex<double> operator()(int frame, int
returnuns-aretrane
int getFrameSize) {
return (frame_size);
Int getNumFrame () (
return (num_frame);