/**
 * Name: Dungeon Master
 * date: 2016-04-16
 * note: 3 dimensions
 * P_ID: UVA 532
 *
 */
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int L, R, C;
char maze[35][35][35];
int vis[35][35][35];
int sx, sy, sl;
int ans;

int dir[][3] = {{1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1}};

struct Maze {
    int l;
    int x;
    int y;
    int step;
};

bool easyGo(int l ,int x, int y)
{
    if(l<0 || x<0 || y<0 || l>=L || x>=R || y>=C) return false;
    if(maze[l][x][y]=='#') return false;
    return true;
}


bool bfs(int l, int x, int y)
{
    Maze first;
    first.l = l;
    first.x = x;
    first.y = y;
    first.step = 0;
    queue<Maze> myPath;
    myPath.push(first);
    while(!myPath.empty())
    {
        Maze now = myPath.front();
        myPath.pop();
        if(maze[now.l][now.x][now.y]=='E')
        {
            ans = now.step;
            return true;
        }
        for(int i=0; i<6; ++i)
        {
            int ll = now.l + dir[i][0];
            int xx = now.x + dir[i][1];
            int yy = now.y + dir[i][2];
            if(easyGo(ll, xx, yy) && !vis[ll][xx][yy])
            {
                Maze next;
                next.l = ll;
                next.x = xx;
                next.y = yy;
                next.step = now.step + 1;
                vis[ll][xx][yy] = 1;
                myPath.push(next);
            }
        }
    }
    return false;
}


int main()
{
    while(scanf("%d%d%d", &L, &R, &C))
    {
        if(L==0 && R==0 && C==0) break;
        memset(vis, 0, sizeof(vis));
        memset(maze, '\0', sizeof(maze));
        for(int i=0; i<L; ++i)
        {
            for(int j=0; j<R; ++j)
            {
                scanf("%s", maze[i][j]);
                getchar();
                for(int k=0; k<C; ++k)
                {
                    if(maze[i][j][k]=='S')
                    {
                        sl = i;
                        sx = j;
                        sy = k;
                    }
                }
            }
            getchar();
        }

        vis[sl][sx][sy] = 1;
        if(bfs(sl, sx, sy))
        {
            printf("Escaped in %d minute(s).\n", ans);
        }
        else printf("Trapped!\n");

    }

    return 0;
}