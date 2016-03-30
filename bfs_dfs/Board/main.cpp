#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, k, ans;
char str[10][10];


int main()
{
    while(1)
    {
        scanf("%d%d", &n, &k);
        if(n==-1 && k==-1) break;
        memset(str, '\0', sizeof(str));
        ans = 0;

        for(int i=0; i<n; i++)
            scanf("%s", str[i]);


    }
    return 0;
}