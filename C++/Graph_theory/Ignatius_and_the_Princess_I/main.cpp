/**
 *method: dfs 深搜
 *note： TLE    
 */
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;


int N, M;
char maze[105][105];
int vis[105][105];
const int dir[][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int ff = 0;

struct pathS {
    int x;
    int y;
};

struct cell {
    int x;
    int y;
    int time;
    vector<pathS> path;
};

int ansTime;
vector<pathS> ansPath;


bool check(int x, int y)
{
    if(x<0 || y<0 || x>=N || y>=M) return false;
    if(maze[x][y]=='X') return false;
    return true;
}

void dfs(cell &a)
{

   // printf("(%d,%d)-----%dtimes\n", a.x, a.y, a.time);
    if(a.x==N-1 && a.y==M-1)
    {
        if(a.time < ansTime)
        {
            ansTime = a.time;
            ansPath = a.path;
        }
    //    printf("************%d\n", a.time);
        return;
    }
    if(a.time >= ansTime) return;
    for(int i=0; i<4; ++i)
    {
        int xx = a.x + dir[i][0];
        int yy = a.y + dir[i][1];
        if(check(xx, yy) && !vis[xx][yy])
        {
            if(maze[xx][yy]=='.')
            {
                cell next;
                next.x = xx;
                next.y = yy;
                vis[xx][yy] = 1;
                next.time = a.time + 1;
                pathS ns;
                ns.x = xx;
                ns.y = yy;
                a.path.push_back(ns);
                next.path = a.path;
                dfs(next);
                vis[xx][yy] = 0;
                a.path.pop_back();
            }
            else
            {
                cell next;
                next.x = xx;
                next.y = yy;
                vis[xx][yy] = 1;
                int tmp = (int)maze[xx][yy] - 48;
         //       printf("%d----------------\n", tmp);
                next.time = a.time + tmp + 1;
                pathS ns;
                ns.x = xx;
                ns.y = yy;
                for(int k=0; k<tmp; ++k)
                    a.path.push_back(ns);
                next.path = a.path;
                dfs(next);
                for(int k=0; k<tmp; ++k)
                    a.path.pop_back();
                vis[xx][yy] = 0;
            }
        }
    }
}


int main()
{
    while (~scanf("%d%d", &N, &M))
    {
        ansTime = 999999;
        memset(maze, 0, sizeof(maze));
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<N; ++i)
            scanf("%s", maze[i]);

        ff = 0;
        cell first;
        first.x = 0;
        first.y = 0;
        first.time = 0;
        pathS zero;
        zero.x = 0;
        zero.y = 0;
 //       first.path.clear();
        first.path.push_back(zero);
        dfs(first);

        int tim = 1;
        if(ansTime==999999)
            printf("God please help our poor hero.\n");
        else
        {
            printf("It takes %d seconds to reach the target position, let me show you the way.\n", ansTime);
            int i;
            for(i=0; i<ansTime-1; ++i)
            {
               // printf("%ds:(%d,%d)->(%d,%d)\n", i+1, ansPath[i].x, ansPath[i].y, ansPath[i+1].x, ansPath[i+1].y);
                if(maze[ansPath[i].x][ansPath[i].y]!='.' && maze[ansPath[i].x][ansPath[i].y]!='X')
                {
                    int tx = ansPath[i].x;
                    int ty = ansPath[i].y;
        //            int tmp = (int)maze[ansPath[i].x][ansPath[i].y] - 48;

                    printf("%ds:FIGHT AT (%d,%d)\n", tim, tx, ty);
                    ff = 1;
                }
                else
                {
                    if(ff==1)
                    {
                        printf("%ds:(%d,%d)->(%d,%d)\n", tim, ansPath[i-1].x, ansPath[i-1].y, ansPath[i].x, ansPath[i].y);
                        tim++;
                        ff = 0;
                    }
                    printf("%ds:(%d,%d)->(%d,%d)\n", tim, ansPath[i].x, ansPath[i].y, ansPath[i+1].x, ansPath[i+1].y);
                }
                tim++;
            }
        }
        printf("FINISH\n");


        /*
        printf("%d\n", ansTime);
        for(int i=0; i<ansPath.size(); ++i)
        {
            printf("(%d,%d)\n", ansPath[i].x, ansPath[i].y);
        }
         */
    }
    return 0;
}
