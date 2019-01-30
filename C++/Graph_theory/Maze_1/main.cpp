/**
 *name: Maze_1
 *p_ID: bnuoj 1054
 */
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int N, M, x, y;
int dir[][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
char str[101][101];
bool vis[101][101];

struct pan {
    int x;
    int y;
    int step;
};

queue<pan> myPan;

bool easyGo(int x, int y)
{
    if(x>=0 && y>=0 && x<N && y<M && str[x][y]!='*' && !vis[x][y])
        return true;
    else return false;
}

int bfs()
{
   while(!myPan.empty())
   {
       pan temp = myPan.front();
       myPan.pop();
       if(str[temp.x][temp.y]=='T') return temp.step;
       for(int i=0; i<4; ++i)
       {
           int xx = temp.x + dir[i][0];
           int yy = temp.y + dir[i][1];
           if(easyGo(xx, yy))
           {
               pan next;
               next.x = xx;
               next.y = yy;
               next.step = temp.step+1;
               vis[xx][yy] = true;
               myPan.push(next);
           }
       }
   }
    return -1;
}

int main()
{
    while(scanf("%d%d", &N, &M)!=EOF)
    {
        memset(str, '\0', sizeof(str));
        memset(vis, false, sizeof(vis));
        while(!myPan.empty())
            myPan.pop();
        int i=0;
        for(int i=0; i<N; i++)
            scanf("%s", str[i]);
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
            {
                if(str[i][j]=='S')
                {
                    pan first;
                    first.x = i;
                    first.y = j;
                    first.step = 0;
                    vis[i][j] = true;
                    myPan.push(first);
                }
            }

        printf("%d\n", bfs());
    }
}
