/**
 *
 * name: Victor Escape
 * P_ID: BNUOJ 5453
 * date: 2016-04-10
 *
 */
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

const int max_N = 55;
int A, B, C, T, N;
int dir[][3] = {{1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1}};
int castle[max_N][max_N][max_N];
int vis[max_N][max_N][max_N];
int ans;

struct location {
    int x;
    int y;
    int z;
    int step;
};


bool bfs(int a, int b, int c)
{
    queue<location> myLoc;
    location first;
    first.x = a;
    first.y = b;
    first.z = c;
    first.step = 0;
    myLoc.push(first);
    while(!myLoc.empty())
    {
        location now = myLoc.front();
        myLoc.pop();

        if(now.x==A-1 && now.y==B-1 && now.z==C-1 && now.step<=T)
        {
            ans = now.step;
            return true;
        }

        if(now.step > T) return false;

        for(int i=0; i<6; ++i)
        {
            int xx = now.x + dir[i][0];
            int yy = now.y + dir[i][1];
            int zz = now.z + dir[i][2];
            if(xx>=0 && xx<A && yy>=0 && yy<B && zz>=0 && zz<C && !vis[xx][yy][zz] && castle[xx][yy][zz]==0)
            {
                location next;
                next.x = xx;
                next.y = yy;
                next.z = zz;
                next.step = now.step + 1;
                vis[xx][yy][zz] = 1;
                myLoc.push(next);
            }
        }

    }
    return false;
}

int main()
{
    scanf("%d", &N);
    getchar();
    while(N--)
    {
        memset(castle, -1, sizeof(castle));
        memset(vis, 0, sizeof(vis));
        scanf("%d%d%d%d", &A, &B, &C, &T);
        getchar();
        for(int i=0; i<A; ++i)
        {
            for(int j=0; j<B; ++j)
            {
                for(int k=0; k<C; ++k)
                {
                    scanf("%d", &castle[i][j][k]);
                }
                getchar();
            }
        }

        if(bfs(0, 0, 0))
            printf("%d\n", ans);
        else printf("-1\n");
    }
    return 0;
}