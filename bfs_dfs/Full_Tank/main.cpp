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
#include <utility>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 3;

int n, m;
int price[1050];
int edge[1050][1050];
int vis[1050];
int q;
int capacity;
int sx;
int sy;
int u, v, x;

#define pii pair<int,int>
vector< pii > Map[1050];


struct node {
    int now;
    int vol;
    int cost;
};


void bfs_dis(int VOL, int be, int en)
{
    memset(vis, 0, sizeof(vis));
    vis[sx] = 1;
}


int main()
{
    memset(edge, 0, sizeof(edge));
    memset(price, 0, sizeof(price));
	scanf("%d%d", &n, &m);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &price[i]);
    }
    for(int i=0; i<m; ++i)
    {
        scanf("%d%d%d", &u, &v, &x);
        Map[v].push_back( pii(v, x) );
        Map[x].push_back( pii(x, v) );

    }
    scanf("%d", &q);
    for(int i=0; i<q; ++i)
    {
        scanf("%d%d%d", &capacity, &sx, &sy);
        bfs_dis(capacity, sx, sy);
    }


   
	return 0;
}
