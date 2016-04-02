/**
 * name: Guilty_Prince
 * P_ID : bnuoj 12931
 * Date: 2016-04-02
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int N, M, x, y;
int ans = 0;
int dir[][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
char str[25][25];
bool vis[25][25];

void dfs(int x, int y)
{
    for(int i=0; i<4; i++)
    {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if(str[xx][yy]=='.' && vis[xx][yy]==0)
        {
            ans++;
            vis[xx][yy] = ans;
            dfs(xx, yy);
        }
    }
    return;
}

int main()
{
    int T;
    cin >> T;
    int c = 1;
    while(T--)
    {
        cin >> M >> N;
        memset(str, '\0', sizeof(str));
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < N; i++)
            scanf("%s", str[i]);
        for(int i=0; i<N; ++i)
            for(int j=0; j<M; ++j)
                if(str[i][j]=='@')
                {
                    x = i;
                    y = j;
                }
        ans = 1;
        vis[x][y] = 1;
        dfs(x, y);
        printf("Case %d: %d\n", c, ans);
        c++;
    }
    return 0;
}
