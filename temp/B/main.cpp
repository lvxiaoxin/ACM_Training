#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int T;
double a, b, ans;
double x, y;
long long n;



int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lf%lf%lld", &a, &b, &n);
        x = (b-a)/2.0;
        y = a - x;
        if(n%2==1)
            ans = log10(a) + log10(3.0) * (n/2);
        else ans = log10((a+2*x)/3.0) + log10(3.0) * (n/2);
        printf("%.10lf\n", ans);
    }
    return 0;
}