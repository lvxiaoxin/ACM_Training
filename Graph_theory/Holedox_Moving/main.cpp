/**
 * Name: Gluttonous Snake
 * P_ID: POJ_1324
 * date: 2016-04-27
 * note: bit operation + status memory
 *
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 3;

int n, m, l, b;
int num = 0;
char maze[25][25];
int vis[21][21][1<<14];
const int dir[][2] = {{1,0}, {0,-1}, {-1,0}, {0,1}};
int d[10];
struct cell {
    int x;
    int y;
    cell(int a, int b)
    {
        x = a;
        y = b;
    }
};

struct node {
    int x;
    int y;
    int step;
    int status;
    node(int a, int b, int c, int d)
    {
        x = a;
        y = b;
        step = c;
        status = d;
    }
};

int flag = 0;


bool check(int x, int y, node temp)
{
    if(x<1 || x>n || y<1 || y>m) return false;
    if(maze[x][y]=='X') return false;
    for(int i=l-1; i>=1; --i)
    {
        d[i] = temp.status&3;
        temp.status>>=2;
    }

    int xx = temp.x, yy = temp.y;
    for(int i=1; i<l; ++i)
    {
        xx+=dir[d[i]][0];
        yy+=dir[d[i]][1];
        if(xx==x && yy==y) return false;
    }
    return true;
}

int bfs(node &start)
{
    vis[start.x][start.y][start.status] = num;
    queue<node> myPath;
    myPath.push(start);
    while(!myPath.empty())
    {
        node now = myPath.front();
        myPath.pop();

      //  cout << now.x << "," << now.y << "---" << now.step << endl;
        if(now.x==1 && now.y==1) return now.step;

        int nx = now.x;
        int ny = now.y;
        int ns = now.status;
        int np = now.step;
        for(int i=0; i<4; ++i)
        {
            int xx = nx + dir[i][0];
            int yy = ny + dir[i][1];
            if(xx==1 && yy==1) return np+1;
            int nst = (ns>>2) + (((i+2)%4)<<(2*(l-2)));
            if(check(xx, yy, now) && vis[xx][yy][nst]!=num)
            {
                myPath.push(node(xx, yy, np+1, nst));
                vis[xx][yy][nst] = num;
            }
        }
    }
    return -1;
}

int main()
{
    while(scanf("%d%d%d", &n, &m, &l))
    {
        flag = 0;
        num++;
        if(n==0 && m==0 & l==0) break;

        memset(maze, '.', sizeof(maze));

        int x, y;
        scanf("%d%d", &x, &y);

        node first(x,y,0,0);

        int nx, ny;
        for(int i=1; i<l; ++i)
        {
            scanf("%d%d", &nx, &ny);
            for(int j=0; j<4; ++j)
            {
                if(x+dir[j][0]==nx && y+dir[j][1]==ny)
                {
                    first.status = (first.status<<2) + j;
                    break;
                }
            } 
            x = nx;
            y = ny;
        }
        scanf("%d", &b);
        for(int i=0; i<b; ++i)
        {
            int x;
            int y;
            scanf("%d%d", &x, &y);
            maze[x][y] = 'X';
        }

        int ans;
        ans = bfs(first);
        if(ans==-1) printf("Case %d: -1\n", num);
        else printf("Case %d: %d\n", num, ans);
    }
	return 0;
}
