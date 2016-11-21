//
// Created by 吕鑫 on 2016/11/18.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

#define MAXN 99999

#define LEN 105

int dist[LEN];

int graph[LEN][LEN];

bool vis[LEN];

void init()
{
    int i,j;

    for(i=0;i<LEN;i++)
    {
        for(j=0;j<LEN;j++)
            graph[i][j]=MAXN;
    }
}

//prime算法

int prime(int n)
{
    int i,j,min,pos,ans;

    ans=0;

    memset(vis, false, sizeof(vis));

    //初始化
    for(i=1; i<=n; i++)
    {
        dist[i] = graph[1][i];
    }


    //从1开始
    vis[1] = true;
    dist[1] = MAXN;

    //找到权值最小点并记录下位置
    for(i=1;i<n;i++)
    {
        min=MAXN;
        for(j=1;j<=n;j++)
        {
            if(!vis[j] && dist[j]<min)
            {
                min=dist[j];
                pos=j;
            }
        }

        if(min==MAXN) return -1;

        ans += min;
        vis[pos]=true;

        //更新权值
        for(j=1; j<=n; j++)
        {
            if(!vis[j] && dist[j]>graph[pos][j])
            {
                dist[j]=graph[pos][j];
            }
        }

    }

    return ans;

}

int main()
{
    int N,M;

    while(scanf("%d%d",&N,&M)!=EOF)
    {
        init();

        int i,a,b,w,ans;

        if(N==0) break;

        for(i=0;i<N;i++)
        {
            cin >> a >> b >> w;

            if(graph[a][b] > w)
            {
                graph[a][b] = w;
                graph[b][a] = w;
            }
        }

        ans=prime(M);

        if(ans==-1)
            cout << "?" << endl;
        else
            cout<< ans << endl;
    }

    return 0;
}