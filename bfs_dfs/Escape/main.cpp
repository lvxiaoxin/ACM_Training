/**
 * name: Escape
 * P_ID: BNUOJ 49278
 * date:
 */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

char str[1005][1005];
int dir[][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int vis[1005][1005];
int N, M;
int x, y;

struct maze {
    int x;
    int y;
};


bool bfs(int x, int y)
{
    maze first;
    first.x = x;
    first.y = y;
    queue<maze> myPath;
    myPath.push(first);
    while(!myPath.empty())
    {
        maze temp;
        temp = myPath.front();
        myPath.pop();
        if(str[temp.x][temp.y]=='E') return true;
        for(int i=0; i<4; ++i)
        {
            int xx = temp.x + dir[i][0];
            int yy = temp.y + dir[i][1];
            if(xx>=0 && xx<N && yy>=0 && yy<M && str[xx][yy]!='#' && vis[xx][yy]==0 && str[xx][yy]!='!')
            {
                maze next;
                next.x = xx;
                next.y = yy;
                vis[xx][yy] = 1;
                myPath.push(next);
            }
        }
        for(int i=0; i<N; ++i)
        {
            for(int j=0; j<M; ++j)
            {
                if(str[i][j]=='!' && vis[i][j]==0)
                {
                    for(int k=0; k<4; k++)
                    {
                        int xx = i + dir[k][0];
                        int yy = j + dir[k][1];
                        if(xx>=0 && xx<N && yy>=0 && yy<M && str[xx][yy]!='#' && str[xx][yy]!='!')
                        {
                            str[xx][yy] = '!';
                            if( (xx>i) || (xx==i && yy>j) )
                                vis[xx][yy] = 2;
                        }
                    }
                    str[i][j] = '#';
                }
                if(str[i][j]=='!' && vis[i][j]==2)
                {
                    vis[i][j] = 0;
                }
            }
        }
    }
    return false;
}


int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        memset(vis, 0, sizeof(vis));
        scanf("%d%d", &N, &M);
        for(int i=0; i<N; i++)
            scanf("%s", str[i]);

        for(int i=0; i<N; ++i)
            for(int j=0; j<M; j++)
                if(str[i][j]=='S')
                {
                    x = i;
                    y = j;
                }
        vis[x][y] = 1;
        if(bfs(x, y)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
