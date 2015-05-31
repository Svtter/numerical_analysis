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
    map <double, double> ff;
    ff[0.0] = 1.0;
    ff[1/8.0] = 0.9973978;
    ff[1/4.0] = 0.9896158;
    ff[3/8.0] = 0.9767267;
    ff[1/2.0] = 0.9588510;
    ff[5/8.0] = 0.9361556;
    ff[3/4.0] = 0.9088516;
    ff[7/8.0] = 0.8771925;
    ff[1.0] = 0.8414709;
    return ff[x];
}

void init(int &a, int &b, int &k)
{
    a = 0, b = 1, k = 2;
}


/**
 * a, b 分别为积分下限，积分上限
 * k 为二分次数
 */
double recurrence_trapezoidal(double a, double b, int k)
{
    if(k == -1)
        return (f(a) + f(b))/2;
    int n = pow(2, k);
    double h = (b-a)/n;

    double res = 0;
    for(int i = 0; i <= n-1; i++)
    {
        double x = (2*i+1)*h/2;
        res += f(x);
    }

    res = recurrence_trapezoidal(a, b, k-1)/2 + res*h/2;
    return res;
}


int main()
{
    int a, b, k;
    init(a, b, k);
    cout << recurrence_trapezoidal(a, b, k-1) << endl;
    return 0;
}
