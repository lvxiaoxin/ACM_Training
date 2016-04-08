/**
 * name: Apple
 * P_ID: BNUOJ 1783
 * date: 2016-04-06
 */
#include <cstdio>
#include <cstring>
using namespace std;

int a, b, ans;
int f(int x, int n)
{
    if(x<=1 || n<=1) return 1;
    if(x<n) return f(x, x);
    return (f(x-n, n) + f(x, n-1));

}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        ans = 0;
        scanf("%d%d", &a, &b);
        ans = f(a, b);
        printf("%d\n", ans);
    }
    return 0;
}