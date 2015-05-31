/*
 * Romber integration
 *
 * author: svtter
 *
 */


#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

// 可以使用函数计算来代替f
//

double f(double x)
{
    return sin(x)/x;
}

void init(int &a, int &b, int &k)
{
    a = 0, b = 1, k = 0;
}


/**
 * a, b 分别为积分下限，积分上限
 * k 为二分次数
 */
double recurrence_trapezoidal(int a, int b, int k)
{
    if(k == 0)
        return (f(a) + f(b))/2;
}

double getT(double a, double b, int k)
{
    if(k == 0)
        return 0;
    int n = pow(2, k);
    double h = (b-a)/n;

    double res = 0;
    for(int i = 0; i <= n-1; i++)
    {
        double x = (2*i+1)*h/2;
        res += f(x);
    }

    res = getT(a, b, k-1)/2 + res*h/2;
}


int main()
{
    int a, b, k;
    init(a, b, k);
    return 0;
}
