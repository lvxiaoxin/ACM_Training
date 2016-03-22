#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int n,ans,i,j,k,mp[30][30],t1,t2,c[30];
    char tc;
    while (1)
    {
        scanf("%d",&n);
        if (n == 0)
            break;
        getchar();
        memset(mp,0,sizeof(mp));
        for (i=0; i<n; i++)
        {
            scanf("%c%*c",&tc);
            t1=tc-'A';
            while (1)
            {
                scanf("%c",&tc);
                if (tc == '\n')
                    break;
                t2=tc-'A';
                mp[t1][t2]=1;
            }
        }
        memset(c,-1,sizeof(c));
        ans=-1;
        for (i=0; i<n; i++)
        {
            for (j=0; j<4; j++)
            {
                c[i]=j;
                for (k=0; k<n; k++)
                {
                    if (mp[i][k] == 1 && c[i] == c[k])
                    {
                        break;
                    }
                }
                if (k == n)
                    break;
            }
            ans=j>ans?j:ans;
        }
        ans++;
        if (ans == 1)
            printf("%d channel needed.\n",ans);
        else
            printf("%d channels needed.\n",ans);
    }
}