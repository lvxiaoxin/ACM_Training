/**
 * name: A strange lift.
 * P_ID: HDU 1548
 */
#include <cstdio>
#include <queue>
using namespace std;


struct lift {
    int up;
    int down;
    int dis;
}g[210];

int N, A, B;
int w[210];
const int INF = 10000;

void prework(int size)
{
   for(int j=1; j<=size; j++)
   {
       g[j].up = j + w[j];
       g[j].down = j - w[j];
       g[j].dis = INF;
   }
}

void bfs()
{
   queue<lift> myLift;
   myLift.push(g[A]);
   while(!myLift.empty())
    {
        if(g[B].dis!=INF) return;
        lift temp = myLift.front();
        myLift.pop();
        if(temp.up>=1 && temp.up<=N && g[temp.up].dis==INF)
        {
            g[temp.up].dis = temp.dis + 1;
            myLift.push(g[temp.up]);
        }
        if(temp.down>=1 && temp.down<=N && g[temp.down].dis==INF)
        {
            g[temp.down].dis = temp.dis + 1;
            myLift.push(g[temp.down]);
        }
    }
}

int main() {
    scanf("%d", &N);
    while(N!=0)
    {
        scanf("%d%d", &A, &B);
        for(int i=1; i<=N; i++)
           scanf("%d", &w[i]);
        prework(N);
        g[A].dis = 0;
        bfs();
        if(g[B].dis==INF)
            printf("-1\n");
        else
            printf("%d\n", g[B].dis);
        scanf("%d", &N);
    }
   return 0;
}
