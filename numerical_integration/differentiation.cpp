#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;


// 需要计算的f
double f(double x)
{
    // return exp(x);
    return sin(x);
}

double differentiation(double x, double h, int k)
{
    h = h / pow(2, k);
    return (f(x+h) - f(x-h)) / (2*h);
}

double speedup1(double x, double h, int k)
{
    return 4/3.0*differentiation(x, h/2, k) - 1/3.0*differentiation(x, h, k);
}


double speedup2(double x, double h, int k)
{
    return 16/15.0*speedup1(x, h/2, k) - 1/15.0*speedup1(x, h, k);
}


double speedup3(double x, double h, int k)
{
    return 64/63.0*speedup2(x, h/2, k) - 1/63.0*speedup2(x, h, k);
}

int main()
{
    printf("precise: %.10lf\n", cos(1));
    printf("simple: %.9lf\n", differentiation(1, 0.8, 3));
    printf("speedup1: %.10lf\n", speedup1(1, 0.8, 3));
    printf("speedup2: %.10lf\n", speedup2(1, 0.8, 3));
    printf("speedup3: %.10lf\n", speedup3(1, 0.8, 3));
    return 0;
}
