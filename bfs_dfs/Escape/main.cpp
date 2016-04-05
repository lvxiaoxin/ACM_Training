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
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if(str[xx][yy]=='.' && vis[xx][yy]==0)
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
                if(str[i][j]=='!')
                {
                    for(int k=0; k<4; k++)
                    {
                        int xx = i + dir[i][0];
                        int yy = j + dir[i][1];
                        if(xx>=0 && xx<N && yy>=0 && yy<M && str[xx][yy]=='.')
                        {
                            str[i][j] = '!';
                        }
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
