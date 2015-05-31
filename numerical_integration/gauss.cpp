/**
 *
 * Gauss
 *
 * author: svtter
 * date: 2015年 05月 31日 星期日 12:35:08 CST
 *
 */

#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
    return 8/(4+(x+1)*(x+1));
}

double two_point_gauss(double a, double b)
{
    return (b-a)*(f(-(b-a)/(2*sqrt(3.0)) + (a+b)/2.0) 
            + f((b-a)/(2.0*sqrt(3.0)) + (a+b)/2.0))/2;
}

double three_point_gauss()
{
    return 5/9.0*f(-sqrt(3/5.0)) + 8/9.0*f(0) + 5/9.0*f(sqrt(3/5.0));
}

int main()
{
    // double a, b;
    cout << three_point_gauss() << endl;
    return 0;
}
