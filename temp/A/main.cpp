#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int N, a, b;
int sum = 0;
int ans;

int cal(int x)
{
    int i = 2;
    if(x<4)
    {
        i = 1;
        return i;
    }

    while( x >= ((i*(i+1)*(2*i+1))/6 - 1) )
    {
        ++i;
    }
    if(i<=100)
        return i-1;
    else return 99;
}


int main()
{
    scanf("%d", &N);
    while(N--)
    {
        scanf("%d%d", &a, &b);
        sum += a*b;
    }
    ans = cal(sum);
 //   ans = cal(824);
    printf("Team Liserious' rank is %d\n", ans);
    return 0;
}