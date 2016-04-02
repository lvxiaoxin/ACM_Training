/**
 * name: Oil Deposits
 * P_ID : bnuoj 1681
 * Date: 2016-04-02
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int N, M, x, y;
int ans = 0;
int dir[][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}, {1,1}, {1,-1}, {-1,-1}, {-1,1}};
char str[105][105];
bool vis[105][105];

void dfs(int x, int y)
{
    for(int i=0; i<8; i++)
    {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if(vis[xx][yy]==0 && str[xx][yy]=='@')
        {
            vis[xx][yy] = ans;
            dfs(xx, yy);
        }
    }
    return;
}


int main()
{
    cin >> N >> M;
    while(N!=0)
    {
        ans = 0;
        memset(str, '\0', sizeof(str));
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < N; i++)
            scanf("%s", str[i]);

        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(vis[i][j]==0 && str[i][j]=='@')
                {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        printf("%d\n", ans);
        cin >> N >> M;
    }
    return 0;
}
