#include <iostream>
#include <cmath>

using namespace std;


double f(double x)
{
    return 20 / (x*x+2*x+10) ;
}

const double eps = 1e-4;

double cal()
{
    double x = 0;
    while (abs(f(x) - x) > eps)
        x = f(x);
    return x;
}

void test(double x)
{
    cout << x*x*x + 2*x*x + 10*x - 20 << endl;
}

int main()
{
    double x = cal();
    cout << x << endl;
    cout << "test: ";
    test(x);
    return 0;
}

