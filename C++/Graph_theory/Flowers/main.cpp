/**
 * name: Flowers
 * P_ID: 1038
 * Date: 2016-04-03
 *
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str[105][105];
int vis[105][105];
int m, n, ans;
int dir[][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void dfs(int x, int y)
{
    for(int i=0; i<4; i++)
    {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if(str[xx][yy]=='.' && !vis[xx][yy] && xx>=0 && xx<=m+1 && yy>=0 && yy<=n+1)
        {
            vis[xx][yy] = 1;
            dfs(xx, yy);
        }
    }
    return;
}

int main()
{
    scanf("%d%d", &m, &n);
    getchar();
    memset(vis, 0, sizeof(vis));
    memset(str, '.', sizeof(str));
    ans = 0;
    for (int i = 1; i <= m ; ++i)
        scanf("%s", str[i]+1);

    dfs(0, 0);
    for(int i=1; i<=m; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            if(str[i][j]=='.' && vis[i][j]==0)
                ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}