#include <iostream>
#include<cstdio>
#include<queue>
#include<vector>
 
using namespace std;
const int N=10000;
struct st
{
    int id,step;
}w,v;
vector<int>map[N];
bool visit[N];
int dist[N];
 
void bfs(int s)
{
    queue<st>q;
    w.id=s;
    w.step=1;
    q.push(w);
    visit[s]=true;
    while(!q.empty())
    {
        w=q.front();
        q.pop();
        if(w.step>dist[w.id])
            dist[w.id]=w.step;
        for(int i=0;i<map[w.id].size();i++)
        {
            int j=map[w.id][i];
            if(!visit[j])
            {
                visit[j]=true;
                v.id=j;
                v.step=w.step+1;
                q.push(v);
            }
        }
    }
}
 
int main()
{
    int i,j,k,t,nz,nr,id,mz,mr;
    int city[N];
    int route[N],cnt;//经过的城市
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&nz,&nr);
        for(i=1;i<N;i++)
            map[i].clear();
        for(i=1;i<=nz;i++)
        {
            scanf("%d%d",&id,&mz);
            city[i]=id;//记录出现的城市的编号
            for(k=0;k<mz;k++)
            {
                int to;
                scanf("%d",&to);
                //建边
                map[id].push_back(to);
                map[to].push_back(id);
            }
        }
        cnt=1;
        for(i=1;i<=nr;i++)
        {
            scanf("%d",&mr);
            for(j=0;j<mr;j++)
            {
                int c;
                scanf("%d",&c);
                for(k=1;k<cnt;k++)//去重
                    if(c==route[k])
                        break;
                if(k==cnt)
                    route[cnt++]=c;
            }
        }
        for(i=1;i<=nz;i++)
            dist[city[i]]=0;
        for(i=1;i<cnt;i++)
        {
            for(j=1;j<=nz;j++)
                visit[city[j]]=false;
            bfs(route[i]);
        }
        dist[0]=10000000;
        int pos=0;
        for(i=1;i<=nz;i++)
            if(dist[city[i]]<dist[pos])
                pos=city[i];
            else if(dist[city[i]]==dist[pos]&&city[i]<pos)
                pos=city[i];
        printf("%d %d\n",dist[pos],pos);
    }
    return 0;
}
