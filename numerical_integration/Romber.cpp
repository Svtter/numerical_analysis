/*
 * Romber integration
 *
 * author: svtter
 *
 */


#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>

using namespace std;

// 可以使用函数计算来代替f
//

double f(double x)
{
    // map <double, double> ff;
    // ff[0.0] = 1.0;
    // ff[1/8.0] = 0.9973978;
    // ff[1/4.0] = 0.9896158;
    // ff[3/8.0] = 0.9767267;
    // ff[1/2.0] = 0.9588510;
    // ff[5/8.0] = 0.9361556;
    // ff[3/4.0] = 0.9088516;
    // ff[7/8.0] = 0.8771925;
    // ff[1.0] = 0.8414709;
    // return ff[x];
    return 1/x;
}

void init(double &a, double &b, int &k)
{
    // a = 0, b = 1, k = 2;
    a = 1, b = 5, k = 3;
}


/**
 * a, b 分别为积分下限，积分上限
 * k 为二分次数
 */
const int maxn = 100;
double T[maxn];
double recurrence_trapezoidal(double a, double b, int k)
{
    if(k == -1)
    {
        T[k+1] = (f(a) + f(b))/2;
        return T[k+1];
    }
    int n = pow(2, k);
    double h = (b-a)/n;

    double res = 0;
    for(int i = 0; i <= n-1; i++)
    {
        double x = a + (2*i+1)*h/2;
        res += f(x);
    }

    res = recurrence_trapezoidal(a, b, k-1)/2 + res*h/2;
    T[k+1] = res;
    return res;
}

double Romber(int k)
{
    double S[maxn];
    double C[maxn];
    double R[maxn];
    for(int i = 0; i < k; i++)
        S[i] = 4/3.0*T[i+1] - 1/3.0*T[i];
    for(int i = 0; i < k-1; i++)
        C[i] = 16/15.0*S[i+1]-1/15.0*S[i];
    for(int i = 0; i < k-2; i++)
        R[i] = 64/63.0*C[i+1] - 1/63.0*C[i];

    return R[k-3];
}


int main()
{
    double a, b; 
    int k;
    init(a, b, k);
    printf("%.6lf\n", recurrence_trapezoidal(a, b, k-1));
    printf("%.6lf\n", Romber(k));
    return 0;
}
