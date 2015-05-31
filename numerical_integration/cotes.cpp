/* 
 * trapezoidal method of numerical integration procedures.
 *
 * author:  svtter
 * time:    2015年 05月 31日 星期日 11:03:20 CST
 *
 */

#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

const int maxn = 1000;

// give f value
// double 的精确值为15位
void init(double &a, double &b, int &n)
{
    // could be insteaded
    // a = 1.1, b = 1.5, n = 2;
    // f[1.1] = 3.0042;
    // f[1.3] = 3.6693;
    // f[1.5] = 4.4817;

    a = 0, b = 1;
}

double f(double x)
{
    // setx;
    map<double, double> ff;
    ff[0.00] = 1.00000;
    ff[0.25] = 1.65534;
    ff[0.50] = 1.55152;
    ff[0.75] = 1.06666;
    ff[1.00] = 0.72159;
    return ff[x];
}

// read from file
void fread(double &a, double &b, int &n)
{
    // filename: input
    /*
     * example:
     *
     * 1.1 1.5 2
     * 3
     * 1.1 3.0042
     * 1.3 3.6693
     * 1.5 4.4817
     * */

    freopen("input", "r", stdin);

    scanf("%lf %lf", &a, &b);
    scanf("%d", &n);
    int num;
    scanf("%d", &num);
    double x, y;
    for(int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &x, &y);
        // f[x] = y;
    }
}

    template <class t>
void debug(t a)
{
    cout << "debug: "<<  a << endl;
}

double simpsons(double a, double b)
{
    double res = 0;
    res = f(a) + f(b) + 4 * f((a+b)/2);
    return res * (b-a)/6;
}

double compound_trapezoidal(double a, double b, int n)
{
    double res = 0;
    double h = (b-a)/n;
    for(int k = 1; k <= n-1; k++)
        res += f(a+k*h);

    res *= 2;
    res += f(a) + f(b);

    return res * h / 2;
} 

double compound_simpsons(double a, double b, int n)
{
    double res;
    res = 0;
    res += f(a) + f(b);
    double h = (b-a)/n;
    double sum = 0;
    for(int k = 0; k <= n-1; k++)
    {
        double mid = a + (2*k+1)*h/2;
        sum += f(mid);
    }
    res += 4*sum;

    sum = 0;
    for(int k = 1; k <= n-1; k++)
        sum += f(a+k*h);

    res += 2*sum;

    return res * h / 6;
}

double cotes(double a, double b, int n)
{
    double res = 0;
    double h = (b-a)/n;
    res += 7*f(a) + 7*f(b);

    double sum = 0;
    for(int k = 0; k <= n-1; k++)
    {
        double quater = a + (4*k+1)*h/4;
        sum += f(quater);
    }
    res += 32*sum;

    sum = 0;
    for(int k = 0; k <= n-1; k++)
    {
        double mid = a + (2*k+1)*h/2;
        sum += f(mid);
    }
    res += 12*sum;


    sum = 0;
    for(int k = 0; k <= n-1; k++)
    {
        double quater = a + (4*k+3)*h/4;
        sum += f(quater);
    }
    res += 32*sum;

    sum = 0;
    for(int k = 1; k <= n-1; k++)
        sum += f(a+k*h);
    res += 14*sum;

    return res * h / 90;
}

int main()
{
    double a, b;
    int n;
    double h = (b-a)/n;
    init(a, b, n);
    printf("%lf %lf %lf\n", a, b, h); 

    printf("simpsons: %lf\n", simpsons(a, b));
    // printf("compound_trapezoidal: %lf\n", compound_trapezoidal(a, b, 4));
    // printf("compound_simpsons: %lf\n", compound_simpsons(a, b, 2));
    // printf("cotes: %lf\n", cotes(a, b, 1));
    return 0;
}
