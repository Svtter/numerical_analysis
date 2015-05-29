// This is for my use of a trapezoidal method of numerical integration procedures.
// author: svtter

#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

const int maxn = 1000;

// give f value
void init(double &a, double &b, double &h, map <double, double> &f)
{
    // could be insteaded
    a = 1.1, b = 1.5, h = 0.2;
    f[1.1] = 3.0042;
    f[1.3] = 3.6693;
    f[1.5] = 4.4817;
}

    template <class t>
void debug(t a)
{
    cout << "debug: "<<  a << endl;
}

double trapezoidal(map <double, double> &f, double a, double b, double h)
{
    double res = 0;
    double i;
    for(i = a+h; i < b; i += h)
        res += f[i];

    res *= 2;
    res += f[a] + f[b];

    return res * h / 2;
} 

int main()
{
    map <double, double> f;
    double a, b, h;
    init(a, b, h, f);
    printf("%lf %lf %lf\n", a, b, h); 

    printf("%lf\n", trapezoidal(f, a, b, h));
    return 0;
}
