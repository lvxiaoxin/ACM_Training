/**
 * name: Escape
 * P_ID: BNUOJ 49278
 * date:2014-04-05
 */
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dir[4][2] = {{1,0}, {-1,0}, {0,-1}, {0,1}};
char str[1005][1005];
bool vis[1005][1005];
int dis[1005][1005];
int N, M;
int x, y;
int ex, ey;
const int inf = 0x3f3f3f3f;

struct maze {
    int x;
    int y;
    int t;
};

bool judge(maze now)
{
    int a = now.x;
    int b = now.y;
    if(a<0 || a>=N || b<0 || b>=M) return false;
    return true;
}

void bfs_hot()
{
    queue<maze> myHot;
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            if(str[i][j]=='!')
            {
                dis[i][j] = 0;
                maze temp;
                temp.x = i;
                temp.y = j;
                temp.t = 0;
                myHot.push(temp);
            }
        }
    }

    while(!myHot.empty())
    {
        maze temp = myHot.front();
        myHot.pop();
        for(int i=0; i<4; ++i)
        {
            maze next;
            next.x = temp.x + dir[i][0];
            next.y = temp.y + dir[i][1];
            next.t = temp.t + 1;
            if(judge(next) && next.t<dis[next.x][next.y])
            {
                dis[next.x][next.y] = next.t;
                myHot.push(next);
            }
        }
    }
}

bool bfs(int x, int y)
{
    queue<maze> myPath;
    maze first, next;
    first.x = x;
    first.y = y;
    first.t = 0;
    myPath.push(first);
    while(!myPath.empty())
    {
        maze temp = myPath.front();
        myPath.pop();
        if(temp.x==ex && temp.y==ey) return true;
        for(int i=0; i<4; ++i)
        {
            next.x = temp.x + dir[i][0];
            next.y = temp.y + dir[i][1];
            next.t = temp.t + 1;
            if(judge(next) && next.x==ex && next.y==ey && (next.t<=dis[next.x][next.y]))//终点处就算同时到达也算作Yes
                return true;
            if(!vis[next.x][next.y] && judge(next) && next.t<dis[next.x][next.y])//中间过程
            {
                vis[next.x][next.y] = 1;
                myPath.push(next);
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
        //配合之后的'#'变更，使得所有岩浆可到达点的dis初始都是inf
        memset(dis, inf, sizeof(dis));
        scanf("%d%d", &N, &M);
        for(int i=0; i<N; i++)
            scanf("%s", str[i]);

        for(int i=0; i<N; ++i)
            for(int j=0; j<M; j++)
            {
                if(str[i][j]=='S')
                {
                    x = i;
                    y = j;
                }
                //用来标记，之后传播岩浆遇到'#'会受阻
                if(str[i][j]=='#')
                {
                    dis[i][j] = 0;
                }
                if(str[i][j]=='E')
                {
                    ex = i;
                    ey = j;
                }
            }
        bfs_hot();
        if(bfs(x, y)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
