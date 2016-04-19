#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int t, nz, nr;
int id[10000][2];
int vis[10000];
int map[10000][11];
int tripNum[11];
int tripPath[11][21];

struct ans {
    int i;
    int star;
};


void bfs(vector<ans> &myG)
{
    for(int i=0; i<nz; ++i)
    {
        int thisStar = 0;
        int thisI = id[i][0];
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
 //           printf("%d``````````%d\n", id[now.i][0], now.star);
            for(int l=0; l<nr; ++l)
            {
                for(int m=0; m<tripNum[l]; ++m)
                {
                    if(id[now.i][0]==tripPath[l][m])
                    {
   //                     printf("%d------------%d\n", id[now.i][0], thisStar);
                        if(thisStar<now.star)
                        {
                            thisStar = now.star;
                        }
                    }
                }
            }

            for(int j=0; j<id[now.i][1]; ++j)
            {
                ans next;
                if(!vis[map[id[now.i][0]][j]])
                {
                    int kk;
                    for(kk=0; kk<nz; ++kk)
                    {
                        if(map[id[now.i][0]][j]==id[kk][0])
                            break;
                    }
                    next.i = kk;
                    next.star = now.star + 1;
                    vis[map[id[now.i][0]][j]] = 1;
     //               printf("%d******%d\n", id[kk][0], next.star);
                    myAns.push(next);
                }
           }
        }
        ans thisTime;
        thisTime.i = thisI;
        thisTime.star = thisStar;

       // printf("%d  %d\n", i, thisStar);
        myG.push_back(thisTime);
    }
}

int main()
{
    scanf("%d", &t);
    getchar();
    while(t--)
    {
        vector<ans> myG;
        memset(id, 0, sizeof(id));
        memset(map, 0, sizeof(map));
        memset(tripNum, 0, sizeof(tripNum));
        memset(tripPath, 0, sizeof(tripPath));
        scanf("%d%d", &nz, &nr);
        getchar();
        for(int i=0; i<nz; ++i)
        {
            scanf("%d%d", &id[i][0], &id[i][1]);
            for(int j=0; j<id[i][1]; ++j)
            {
                scanf("%d", &map[id[i][0]][j]);
            }
            getchar();
        }
        for(int i=0; i<nr; ++i)
        {
            scanf("%d", &tripNum[i]);
            for(int j=0; j<tripNum[i]; ++j)
            {
                scanf("%d", &tripPath[i][j]);
            }
            getchar();
        }
        bfs(myG);
        ans last;
        last.star = 999999;
        last.i = 999999;
        for(int i=0; i<nz; ++i)
        {
            if(myG[i].star < last.star)
            {
                last.star = myG[i].star;
                if(last.i > myG[i].i)
                    last.i = myG[i].i;
            }
        }

        /*
        printf("%d %d\n", last.star+1, last.i);

        for(int i=0; i<nz; ++i)
        {
            printf("%d   %d\n", myG[i].star, myG[i].i);
        }
        */

        printf("%d %d\n", last.star+1, last.i);
   }
    return 0;
}