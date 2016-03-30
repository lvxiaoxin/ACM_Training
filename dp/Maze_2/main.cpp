/**
 *name: Maze_2
 *p_ID: bnuoj 1055
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

int N, M, x, y, num = 0;
int dir[][2] = {{-1,0}, {0, 1}};
char str[101][101];
bool vis[101][101];


bool easyGo(int x, int y)
{
    if(x>=0 && y>=0 && x<N && y<M && str[x][y]!='*' && !vis[x][y])
        return true;
    else return false;
}

void dfs(int x, int y)
{
    if(str[x][y]=='T')
    {
        num++;
        num %= 1908;
        return;
    }

    if(easyGo(x-1, y))
    {
        vis[x-1][y] = true;
        dfs(x-1, y);
        vis[x-1][y] = false;
    }
    if(easyGo(x, y+1))
    {
        vis[x][y+1] = true;
        dfs(x, y+1);
        vis[x][y+1] = false;
    }
    return;
}

int main()
{
    while(scanf("%d%d", &N, &M)!=EOF)
    {
        num = 0;
        memset(str, '\0', sizeof(str));
        memset(vis, false, sizeof(vis));
        int i=0;
        for(int i=0; i<N; i++)
            scanf("%s", str[i]);
        int flag = 1;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(str[i][j]=='S')
                {
                    x = i;
                    y = j;
                    vis[i][j] = true;
                    flag = 0;
                    break;
                }
            }
            if(flag==0)
                break;
        }
        dfs(x, y);
        printf("%d\n", num);
    }
}
