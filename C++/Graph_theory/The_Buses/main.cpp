/**
 *name: The Buses
 *date: 2016-04-21
 *note: dfs + modeling    difficult
 */
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

struct busRoute {
    int begin;
    int interval;
    int times;
};

busRoute route[1300];
int n, sumBus[1300];
int tot = 0, ans = 17;

bool comp(const busRoute a, const busRoute b)
{
    return (a.times > b.times);
}

bool checkRoute(int a, int b)
{
    for(int i=a; i<60; i+=b)
    {
        if(sumBus[i]==0)
            return false;
    }
    return true;
}


void dfs(int a, int num)
{
    if(n<=0)
    {
        if(num < ans)
            ans = num;
        return;
    }
    for(int k=a; k<tot; ++k)
    {
        if(num + n/(route[k].times) >= ans) return;

        if(checkRoute(route[k].begin, route[k].interval))
        {
            int temp = route[k].interval;
            for (int i = route[k].begin; i < 60; i += temp)
            {
                sumBus[i]--;
                n--;
            }
            dfs(k, num + 1);
            for (int i = route[k].begin; i < 60; i += temp)
            {
                sumBus[i]++;
                n++;
            }
        }
    }
}




int main()
{
    scanf("%d", &n);
    memset(sumBus, 0, sizeof(sumBus));
    int bus;
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &bus);
        sumBus[bus]++;
    }

    tot = 0;
    for(int i=0; i<30; ++i)
    {
        if(sumBus[i]==0) continue;
        for(int j=i+1; j<60-i; ++j)
        {
            if(checkRoute(i, j))
            {
                route[tot].begin = i;
                route[tot].interval = j;
                route[tot].times = (59-i)/j + 1;
                tot++;
            }
        }
    }

    sort(route, route+tot, comp);
    ans = 17;
    dfs(0, 0);

    printf("%d\n", ans);


    return 0;
}
