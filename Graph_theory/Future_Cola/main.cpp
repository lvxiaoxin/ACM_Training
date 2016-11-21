/**
 * name: Future Cola
 * P_ID: BNUOJ 5693
 * date: 2016-04-03
 */
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int s, n, m;
int vis[105][105][105];

struct cola {
    int s;
    int v1;
    int v2;
    int step;
};
bool even(int a)
{
    if(a%2==0) return true;
    else return false;
}

bool judge(cola c)
{
    if(c.step==0) return false;
    if((c.s==c.v1 && !c.v2) || (c.s==c.v2 && !c.v1) || (c.v1==c.v2 && !c.s)) return true;
    return false;
}

int bfs(int a, int b, int c)
{
    memset(vis, 0, sizeof(vis));
    queue<cola> myCola;
    cola now, next;
    now.s = a;
    now.v1 = b;
    now.v2 = c;
    now.step = 0;
    vis[a][b][c] = 1;
    myCola.push(now);
    while(!myCola.empty())
    {
        cola temp;
        temp = myCola.front();
        myCola.pop();

        if(judge(temp)) return temp.step;

        if(temp.s!=s)
        {
            if(temp.v1)
            {
                next.s = temp.s + temp.v1;
                next.v1 = 0;
                next.v2 = temp.v2;
                if(!vis[next.s][next.v1][next.v2])
                {
                    next.step = temp.step + 1;
                    vis[next.s][next.v1][next.v2] = 1;
                    myCola.push(next);
                }
            }
            if(temp.v2)
            {
                next.s = temp.s + temp.v2;
                next.v2 = 0;
                next.v1 = temp.v1;
                if(!vis[next.s][next.v1][next.v2])
                {
                    next.step = temp.step + 1;
                    vis[next.s][next.v1][next.v2] = 1;
                    myCola.push(next);
                }
            }
        }

        if(temp.v1!=n)
        {
            if(temp.s)
            {
                next.v1 = n;
                next.s = temp.s - n + temp.v1;
                next.v2 = temp.v2;
                if(!vis[next.s][next.v1][next.v2])
                {
                    next.step = temp.step + 1;
                    vis[next.s][next.v1][next.v2] = 1;
                    myCola.push(next);
                }
            }
            if(temp.v2)
            {
                next.s = temp.s;
                if(temp.v2 + temp.v1 > n)
                {
                    next.v1 = n;
                    next.v2 = temp.v2 - n + temp.v1;
                }
                else
                {
                    next.v1 = temp.v2 + temp.v1;
                    next.v2 = 0;
                }
                if(!vis[next.s][next.v1][next.v2])
                {
                    next.step = temp.step + 1;
                    vis[next.s][next.v1][next.v2] = 1;
                    myCola.push(next);
                }
            }
        }

        if(temp.v2!=m)
        {
            if(temp.s)
            {
                next.v2 = m;
                next.s = temp.s - m + temp.v2;
                next.v1 = temp.v1;
                if(!vis[next.s][next.v1][next.v2])
                {
                    next.step = temp.step + 1;
                    vis[next.s][next.v1][next.v2] = 1;
                    myCola.push(next);
                }
            }
            if(temp.v1)
            {
                next.s = temp.s;
                if(temp.v1 + temp.v2 > m)
                {
                    next.v2 = m;
                    next.v1 = temp.v1 - m + temp.v2;
                }
                else
                {
                    next.v2 = temp.v1 + temp.v2;
                    next.v1 = 0;
                }
                if(!vis[next.s][next.v1][next.v2])
                {
                    next.step = temp.step + 1;
                    vis[next.s][next.v1][next.v2] = 1;
                    myCola.push(next);
                }
            }
        }
    }
    return -1;
}

int main()
{
    while(1)
    {
        scanf("%d%d%d", &s, &n, &m);
        if(s==0 && n==0 && m==0) break;
        if(!even(s))
        {
            printf("NO\n");
            continue;
        }
        else
        {
            int ans = bfs(s, 0, 0);
            if(ans==-1)
                printf("NO\n");
            else printf("%d\n", ans);
        }
    }
    return 0;
}

