//
// Created by 吕鑫 on 2016/11/18.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10000+100
#define MAXM 50000+100

using namespace std;

int n, m;
int u[MAXM],v[MAXM], w[MAXM], r[MAXM], p[MAXN];

int cmp(const int i, const int j)
{
    return w[i] < w[j];
}

int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}

long long Kruskal()
{
    long long ans = 0;
    int cnt = 0;
    for (int i=1; i<=n; i++)
        p[i] = i;
    for (int i=0; i<m; i++)
        r[i] = i;
    sort(r, r+m, cmp);
    for (int i=0; i<m; i++)
    {
        int e = r[i];
        int x = find(u[e]);
        int y = find(v[e]);
        if (x != y)
        {
            ans += w[e];
            p[x] = y;
            cnt++;
            if (cnt == n-1) return ans;
        }
    }
    return -1;
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (int i=0; i<m; i++)
        {
            scanf("%d%d%d", &u[i], &v[i], &w[i]);
        }
        printf("%lld\n", Kruskal());
    }
    return 0;
}

