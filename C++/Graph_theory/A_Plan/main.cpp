/**
 * name: A Plan
 * P_ID: HDU 2102
 * date: 2016-04-15
 */
#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int T, N, M, C;
int vis[2][12][12];
char maze[2][12][12];
int dir[][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int ans;

struct Maze {
    int floor;
    int x;
    int y;
    int step;
};

bool easyGo(int k, int x, int y)
{
    if((k!=1 && k!=0) || x<0 || x>=N || y<0 || y>=M) return false;
    if(maze[k][x][y]=='*') return false;
    if(maze[k][x][y]=='#')
    {
        if(k==1)
        {
            if(maze[0][x][y]=='#' || maze[0][x][y]=='*') return false;
        }
        if(k==0)
        {
            if(maze[1][x][y]=='#' || maze[1][x][y]=='*') return false;
        }
    }
    return true;
}

bool bfs(int k, int x, int y)
{
    Maze first;
    first.floor = k;
    first.x = x;
    first.y = y;
    first.step = 0;
    queue<Maze> myMaze;
    myMaze.push(first);
    while(!myMaze.empty())
    {
        Maze now = myMaze.front();
        myMaze.pop();
        if(maze[now.floor][now.x][now.y]=='P' && now.step<=T)
        {
            return true;
        }
        for(int i=0; i<4; ++i)
        {
            int xx = now.x + dir[i][0];
            int yy = now.y + dir[i][1];
            if(easyGo(now.floor, xx, yy) && !vis[now.floor][xx][yy])
            {
                Maze next;
                if(maze[now.floor][xx][yy]=='#')
                {
                    if(now.floor==1)
                        next.floor = 0;
                    if(now.floor==0)
                        next.floor = 1;
                    next.x = xx;
                    next.y = yy;
                    next.step = now.step + 1;
                    vis[next.floor][next.x][next.y] = 1;
                    vis[now.floor][next.x][next.y] = 1;
                    myMaze.push(next);
                }
                else
                {
                    next.floor = now.floor;
                    next.x = xx;
                    next.y = yy;
                    next.step = now.step + 1;
                    vis[next.floor][next.x][next.y] = 1;
                    myMaze.push(next);
                }
           }
        }
    }
    return false;
}


int main()
{
    scanf("%d", &C);
    getchar();
    while(C--)
    {
        ans = 0;
        memset(maze, 0, sizeof(maze));
        memset(vis, 0, sizeof(vis));
        scanf("%d%d%d", &N, &M, &T);
        getchar();
        for(int i=0; i<N; ++i)
        {
            scanf("%s", maze[0][i]);
            getchar();
        }
        for(int i=0; i<N; ++i)
        {
            scanf("%s", maze[1][i]);
            getchar();
        }

        if(bfs(0, 0, 0)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}