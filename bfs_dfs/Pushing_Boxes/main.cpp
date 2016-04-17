/**
 * name: Pushing box
 * p_id: POJ 1475
 * date: 2016-04-17
 * note: 嵌套bfs,双重bfs
 */
#include <cstring>
#include <string>
#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
char maze[25][25];
int sx, sy;
int bx, by;
const int dir[][2] = {{1,0}, {0,1}, {0,-1}, {-1,0}};
const char dpathB[4] = {'S', 'E', 'W', 'N'};
const char dpathP[4] = {'s', 'e', 'w', 'n'};
string ans;


struct person {
    int x;
    int y;
    string path;
};

struct status {
    int px;
    int py;
    int bx;
    int by;
    string path;

};

bool easyGo(int x, int y)
{
    if(x<0 || x>=N || y<0 || y>=M) return false;
    if(maze[x][y]=='#') return false;
    return true;
}

bool bfs2(int ppx, int ppy, int bbx, int bby, int kx, int ky, string &path)
{
    int vis[25][25];
    memset(vis, 0, sizeof(vis));
    vis[ppx][ppy] = 1;
    vis[kx][ky] = 1;
    person first;
    first.x = ppx;
    first.y = ppy;
    first.path = "";
    queue<person> myPerson;
    myPerson.push(first);
    while(!myPerson.empty())
    {
        person now = myPerson.front();
        myPerson.pop();
        if(now.x==bbx && now.y==bby)
        {
            path = now.path;
            return true;
        }
        for(int i=0; i<4; ++i)
        {
            int zx = now.x + dir[i][0];
            int zy = now.y + dir[i][1];
            if(easyGo(zx, zy) && !vis[zx][zy])
            {
                vis[zx][zy] = 1;
                person next;
                next.x = zx;
                next.y = zy;
                next.path = now.path +  dpathP[i];
                myPerson.push(next);
            }
        }
    }
    return false;
}

bool bfs()
{
    int vis[25][25];
    memset(vis, 0, sizeof(vis));
    status first;
    first.bx = bx;
    first.by = by;
    first.px = sx;
    first.py = sy;
    first.path = "";
    vis[bx][by] = 1;
    queue<status> myPath;
    myPath.push(first);
    while(!myPath.empty())
    {
        status now = myPath.front();
        myPath.pop();
        for(int i=0; i<4; ++i)
        {
            int bbx = now.bx + dir[i][0];
            int bby = now.by + dir[i][1];
            int tx = now.bx - dir[i][0];
            int ty = now.by - dir[i][1];
            string path = "";
            if(easyGo(bbx, bby) && easyGo(tx, ty) && !vis[bbx][bby])
            {
                if(bfs2(now.px, now.py, tx, ty, now.bx, now.by, path))
                {
                    vis[bbx][bby] = 1;
                    status next;
                    next.bx = bbx;
                    next.by = bby;
                    next.px = now.bx;
                    next.py = now.by;
                    next.path = now.path + path + dpathB[i];
                    if(maze[bbx][bby]=='T')
                    {
                        ans = next.path;
                        return true;
                    }
                    myPath.push(next);
                }
            }
        }
    }
    return false;
}

int main()
{
    int cc = 0;
    while(scanf("%d%d", &N, &M))
    {
        ans = '\0';
        cc++;
        getchar();
        memset(maze, '\0', sizeof(maze));
        if(N==0 && M==0) break;
        for(int i=0; i<N; ++i)
        {
            scanf("%s", maze[i]);
            getchar();
            for(int j=0; j<M; j++)
            {
                if(maze[i][j]=='S')
                {
                    sx = i;
                    sy = j;
                }
                if(maze[i][j]=='B')
                {
                    bx = i;
                    by = j;
                }
            }
        }
        printf("Maze #%d\n", cc);
        if(bfs())
            cout << ans << endl;
        else printf("Impossible.\n");
        printf("\n");
    }
    return 0;
}