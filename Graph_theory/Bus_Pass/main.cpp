#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int t, nz, nr;
int id[10000];
int vis[10000];
int map[10000][11];
int tripNum[11];
int tripPath[11][21];
int ansStar, ansID;
int edge[10000][105];
int k;
int fillC[10000];

struct ans {
    int i;
    int star;
};


void bfs(int i)
{
 //       printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    memset(vis, 0, sizeof(vis));
    queue<ans> myAns;
    ans first;
    first.i = i;
    first.star = 0;
    myAns.push(first);
    vis[i] = 1;
    while(!myAns.empty())
    {
        ans now = myAns.front();
        myAns.pop();
        for(int j=0; j<id[now.i]; ++j)
        {
            ans next;
            if(!vis[map[now.i][j]])
            {
                next.i = map[now.i][j];
                next.star = now.star + 1;
                vis[map[now.i][j]] = 1;
                myAns.push(next);
                edge[next.i][k] = next.star;
 //               printf("%d   %d   %d\n", next.i, next.star, i);
            }
        }
    }
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        k = 0;
        ansStar = 9999999;
        ansID = 9999999;
        memset(edge, 0, sizeof(edge));
        memset(id, 0, sizeof(id));
        memset(map, 0, sizeof(map));
        memset(tripNum, 0, sizeof(tripNum));
        memset(tripPath, 0, sizeof(tripPath));
        memset(fillC, 0, sizeof(fillC));
        scanf("%d%d", &nz, &nr);
        for(int i=0; i<nz; ++i)
        {
            int temp;
            scanf("%d", &temp);
            fillC[i] = temp;
            scanf("%d", &id[temp]);
            for(int j=0; j<id[temp]; ++j)
            {
                scanf("%d", &map[temp][j]);
            }
        }
        for(int i=0; i<nr; ++i)
        {
            scanf("%d", &tripNum[i]);
            for(int j=0; j<tripNum[i]; ++j)
            {
                scanf("%d", &tripPath[i][j]);
                bfs(tripPath[i][j]);
                k++;
            }
        }

       // printf("%d\n\n", k);
        for(int i=0; i<nz; ++i)
        {
            for(int j=1; j<k; ++j)
            {
                if(edge[fillC[i]][j]>edge[fillC[i]][0])
                    edge[fillC[i]][0] = edge[fillC[i]][j];
            }
        }

        for(int i=0; i<nz; ++i)
        {
            if(ansStar>edge[fillC[i]][0])
            {
                ansStar = edge[fillC[i]][0];
                ansID = fillC[i];
            }
            if(ansStar==edge[fillC[i]][0] && ansID>fillC[i])
            {
                ansID = fillC[i];
            }
        }
        printf("%d %d\n", ansStar+1, ansID);

   }
    return 0;
}
