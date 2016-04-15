/**
 * name: Find a way
 * date: 2016-04-15
 * P_ID: HDU 2612
 * note: bfs, a little complicate
 */

#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N, M;
char city[205][205];
int vis[205][205];
int sx, sy;
int px, py;
int ans;
int dir[][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
struct path {
    int x;
    int y;
    int step;
};
int mark[2][205][205];


bool easyGo(int x, int y)
{
    if(x<0 || x>=N || y<0 || y>=M) return false;
    if(city[x][y]=='#') return false;
    return true;
}


void bfs(int x, int y, int k)
{
    path first;
    first.x = x;
    first.y = y;
    first.step = 0;
    queue<path> myPath;
    myPath.push(first);
    while(!myPath.empty())
    {
        path now = myPath.front();
        myPath.pop();
        if(city[now.x][now.y]=='@')
        {
            if(now.step<mark[k][now.x][now.y])
                mark[k][now.x][now.y] = now.step;
        }
        for(int i=0; i<4; ++i)
        {
            int xx = now.x + dir[i][0];
            int yy = now.y + dir[i][1];
            if(easyGo(xx, yy) && !vis[xx][yy])
            {
                path next;
                next.x = xx;
                next.y = yy;
                next.step = now.step + 1;
                vis[xx][yy] = 1;
                myPath.push(next);
            }
        }
    }
    return;
}

int main()
{
    while(~scanf("%d%d", &N, &M))
    {
        ans = 0;
        int count = 0;
        memset(city, '\0', sizeof(city));
        memset(mark, 999999, sizeof(mark));
        getchar();
        for(int i=0; i<N; ++i)
        {
            scanf("%s", city[i]);
            getchar();
        }
        for(int i=0; i<N; ++i)
        {
            for(int j=0; j<M; ++j)
            {
                if(city[i][j]=='Y')
                {
                    sx = i;
                    sy = j;
                }
                if(city[i][j]=='M')
                {
                    px = i;
                    py = j;
                }
                if(city[i][j]=='@')
                {
                    count++;
                }
           }
        }
        memset(vis, 0, sizeof(vis));
        vis[sx][sy] = 1;
        bfs(sx, sy, 0);
        memset(vis, 0, sizeof(vis));
        vis[px][py] = 1;
        bfs(px, py, 1);
        vector<int> myAns;
        for(int i=0; i<N; ++i)
        {
            for(int j=0; j<M; ++j)
            {
                if(city[i][j]=='@')
                {
                   // printf("%d,%d; %d %d\n",i, j, mark[0][i][j], mark[1][i][j]);
                    ans = mark[0][i][j] + mark[1][i][j];
                    ans *= 11;
                    //printf("%d\n", ans);
                    myAns.push_back(ans);
                }
            }
        }
        sort(myAns.begin(), myAns.end());
        printf("%d\n", myAns[0]);
    }
    return 0;
}

