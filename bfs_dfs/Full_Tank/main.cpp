/**
 * name: Full Tank?
 * P_ID: POJ 3635
 * method: priority queue + date deal 
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


int n, m;
int ans;
int price[1005];
int vis[1005][105];
struct road {
    int goal;
    int dis;
    road(int a, int b)
    {
        goal = a;
        dis = b;
    }
};
vector<road> cityR[1005]; 
int q, c, s, e;

struct node {
    int vol;
    int city;
    int cost;
    node(int a, int b, int c)
    {
        vol = a;
        city = b;
        cost = c;
    }
    bool operator < (node b) const
    {
        return cost > b.cost;
    }
};


int bfs(int cap, int sta, int end)
{
    memset(vis, 0, sizeof(vis));
    node first(0, sta, 0);
    priority_queue<node> myNode;
    myNode.push(first);
    while(!myNode.empty())
    {
        node now = myNode.top();
        myNode.pop();
 //       cout << "***"  << now.city << "city" << endl;
        int x = now.city;
        int y = now.vol;
        int z = now.cost;
        if(now.city==end) 
            return now.cost;
        vis[now.city][now.vol] = 1;
        if(now.vol<cap)
            myNode.push(node(y+1, x, z+price[x]));
 //       cout << cityR[now.city].size() << "---"<< endl;
        for(int i=0; i<cityR[now.city].size(); ++i)
        {
            int g = cityR[now.city][i].goal;
            int d = cityR[now.city][i].dis;
            if(now.vol>=d && !vis[g][now.vol-d])
            {
                myNode.push(node(now.vol-d, g, now.cost));
            }
        }
    }
    return -1;
}


int main()
{
    ans = 0;
    memset(price, 0, sizeof(price));
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; ++i)
        scanf("%d", &price[i]);
    for(int i=0; i<m; ++i)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        cityR[a].push_back(road(b,c));
        cityR[b].push_back(road(a,c));
    }
    scanf("%d", &q);
    for(int i=0; i<q; ++i)
    {
        scanf("%d%d%d", &c, &s, &e);
        ans = bfs(c, s, e);
        if(ans==-1)
            printf("impossible\n");
        else printf("%d\n", ans);
    }

	return 0;
}
