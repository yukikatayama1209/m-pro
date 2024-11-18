#include <iostream>
#include <cmath>
using namespace std;

class Function {
    public:
    virtual double calc(double x) = 0;
};

class Parabola : public Function {
    private:
    double a, b, c;
    public:
    Parabola(
        double a,
        double b,
        double c
    ){
        this -> a = a;
        this -> b = b;
        this -> c = c;
    }
    double calc(double x){
        return a * x * x + b * x + c;
    }
};

class Logarithm : public Function {
    private:
    double amplitude, base;
    public:
    Logarithm(
        double a,
        double b
    ){
        amplitude = a;
        base = b;
    }
    double calc(double x){
        return (amplitude * log(x) / log(base));
    }
};
class Sinusoid : public Function {
    private:
    double a, b, c;

    public:
    Sinusoid(
        double a,
        double b,
        double c
    ) {
        this -> a = a;
        this -> b = b;
        this -> c = c;
    }

    double calc(double x) {
        return a * sin(b * x + c);
    }
};
double integrate(
    Function *f,
    double a,
    double b) {
    const int N = 10;
    double dx = (b-a)/double(N);
    double s = 0;
    for(int i=0; i<N; i++) {
        double x = (i+0.5)*dx + a;
        s += f->calc(x) * dx;
    }
    return(s);
}


// int main(){
//     Parabola my_para(1, 0, 0);
//     Logarithm my_log(1.0, 10.0);
//     cout << integrate(&my_para, 0., 1.) << endl;
//     cout << integrate(&my_log, 0., 1.) << endl;

//     return 0;
// }

#include <iostream>

int main() {
    Sinusoid sinusoid(1.0, 2.0, 3.0); // a=1, b=2, c=3 の Sinusoid オブジェクト
    double result = integrate(&sinusoid, 0.0, 1.0); // 区間 [0, 1] の積分
    std::cout << "answer: " << result << std::endl;
    return 0;
}
