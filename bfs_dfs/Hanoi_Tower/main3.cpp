/**
 *name: Hanoi_Tower
 *P_ID: 42696
 *date: 2016-04-03
 */
#include<cstdio>
using namespace std;

int n;
long long ans,year, day, hour, min, sec;
bool even(int a)
{
    if(a%2==0)
        return true;
    else return false;
}

long long power(int x, int n)
{
    if(n==1)
        return x;
    if(even(n))
    {
        long long a = power(x, n/2);
        return a * a;
    }
    else
    {
        long long b = power(x, (n-1)/2);
        return b * b * x;
    }
}

void trans(long long x)
{
    int a = 31536000;
    year = x/a;
    x%=a;
    int b = 86400;
    day = x/b;
    x%=b;
    int c = 3600;
    hour = x/c;
    x%=c;
    int d = 60;
    min = x/d;
    x%=d;
    sec = x;
}


int main()
{
    while(~scanf("%d", &n))
    {
        ans = power(2, n)-1;
        trans(ans);
        printf("%lld years %lld days %lld hours %lld minute %lld seconds\n", year, day, hour, min, sec);
    }
    return 0;
}

