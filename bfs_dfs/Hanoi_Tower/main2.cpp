/**
 *name: Hanoi_Tower
 *P_ID: 42695
 *date: 2016-04-03
 */
#include<cstdio>
using namespace std;

int n;
bool even(int a)
{
    if(a%2==0)
        return true;
    else return false;
}
int power(int x, int n)
{
    if(n==1)
        return x;
    if(even(n))
    {
        int a = power(x, n/2);
        return a * a;
    }
    else
    {
        int b = power(x, (n-1)/2);
        return b * b * x;
    }
}


int main()
{
    while(~scanf("%d", &n))
    {
        printf("%d\n", power(2, n)-1);
    }
    return 0;
}

