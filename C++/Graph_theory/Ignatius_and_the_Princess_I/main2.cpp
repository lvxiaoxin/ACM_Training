/**
 * method2: priority_queue最短路 + stack输出
 * P_ID: HDU 1026
 * date: 2016-04-22
 * level: dificult
 */
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


int N, M;
struct cell {
    int x;
    int y;
    int time;
    friend bool operator < (const cell& a, const cell &b)
    {
        return a.time > b.time;
    }
}p[105][105],path[105][105];
char maze[105][105];
int vis[105][105];
const int dir[][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int ansTime;



bool check(int x, int y)
{
    if(x<0 || y<0 || x>=N || y>=M) return false;
    if(maze[x][y]=='X') return false;
    return true;
}


int bfs(cell s)
{
    priority_queue<cell> myCell;
    myCell.push(s);
    vis[0][0] = 1;
    while (!myCell.empty())
    {
        cell head = myCell.top();
        myCell.pop();
        if(head.x==N-1 && head.y==M-1)
            return head.time;
        for(int i=0; i<4; ++i)
        {
            int xx = head.x + dir[i][0];
            int yy = head.y + dir[i][1];
            if(check(xx, yy) && !vis[xx][yy])
            {
                vis[xx][yy] = 1;
                path[xx][yy].x = head.x;
                path[xx][yy].y = head.y;
                path[xx][yy].time = head.time + 1;
                cell next;
                next.x = xx;
                next.y = yy;
                next.time = head.time + 1;
                if(maze[xx][yy]=='.') myCell.push(next);
                else
                {
                    next.time = next.time + maze[xx][yy] - '0';
                    myCell.push(next);
                }
           }
        }
    }
    return -1;
}


void print()
{
    if(ansTime==-1) printf("God please help our poor hero.\n");
    else
    {
        printf("It takes %d seconds to reach the target position, let me show you the way.\n", ansTime);
        stack<cell> st;
        cell t = path[N-1][M-1];
        cell rMin;
        rMin.x = N-1;
        rMin.y = M-1;
        rMin.time = ansTime;
        st.push(rMin);
        while (t.x||t.y)
        {
            st.push(t);
            t = path[t.x][t.y];
        }
        int k=1;
        while (!st.empty())
        {
            t = st.top();
            st.pop();
            printf("%ds:(%d,%d)->(%d,%d)\n", k++, path[t.x][t.y].x, path[t.x][t.y].y, t.x, t.y);
            if(maze[t.x][t.y]!='.')
            {
                int tmp = maze[t.x][t.y] - '0';
                while(tmp--)
                {
                    printf("%ds:FIGHT AT (%d,%d)\n", k++, t.x, t.y);
                }
            }

        }
    }
    printf("FINISH\n");
    return;
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
        cell start;
        start.x = 0;
        start.y = 0;
        start.time = 0;
        ansTime = bfs(start);
        print();
    }
    return 0;
}
