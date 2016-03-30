/**
 *name: Maze_2
 *p_ID: bnuoj 1055
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

int N, M, x, y, xx, yy;
char str[101][101];
bool vis[101][101];
int dp[101][101];


void dpsearch(int p, int q)
{

    if(p>x || q<y || str[p][q]=='*') return;
    if(!vis[p][q])
    {
        vis[p][q] = true;
        dpsearch(p+1, q);
        dpsearch(p, q-1);
        if(p<N)
            dp[p][q] += dp[p+1][q]%1908;
        if(q>0)
            dp[p][q] += dp[p][q-1]%1908;
    }
}

int main()
{
    while(scanf("%d%d", &N, &M)!=EOF)
    {
        memset(str, '\0', sizeof(str));
        memset(vis, false, sizeof(vis));
        memset(dp, 0, sizeof(dp));
        int i=0;
        for(int i=0; i<N; i++)
            scanf("%s", str[i]);
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(str[i][j]=='S')
                {
                    x = i;
                    y = j;
                }
                if(str[i][j]=='T')
                {
                    xx = i;
                    yy = j;
                }
            }
        }

        dp[x][y] = 1;
        dpsearch(xx, yy);
        printf("%d\n", dp[xx][yy]%1908);
    }

    return 0;
}
