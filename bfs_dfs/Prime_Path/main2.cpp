#include<iostream>
#include<cmath>
#include <queue>
#include <cstring>
using namespace std;

int N = 0;
int a, b;
bool result = 0;

struct g{
    int x;
    int step;
};

int vis[9999];

bool even(int x)
{
    if(x%2==0)
        return true;
    else return false;
}

bool prim(int x)
{
    int m = floor(sqrt(x) + 0.5);
    for (int i = 2; i <= m; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}



int bfs()
{
    g first = {a, 0};
    queue<g> myInt;
    myInt.push(first);
    while(!myInt.empty())
    {
        if(myInt.front().x==b)
        {
            result = true;
            return myInt.front().step;
        }
        g temp = myInt.front();
        myInt.pop();
        for(int i=0; i<=9; ++i)
        {
            if(!even(i))
            {
                int t_1 =  (temp.x / 10) * 10 + i;
                if(prim(t_1) && !vis[t_1])
                {
                    g next;
                    next.x = t_1;
                    next.step = temp.step + 1;
                    vis[t_1] = 1;
                    myInt.push(next);
                }
            }
            int t_2 = temp.x % 10 + (temp.x / 100) * 100 + i * 10;
            if(prim(t_2) && !vis[t_2])
            {
                g next;
                next.x = t_2;
                next.step = temp.step + 1;
                vis[t_2] = 1;
                myInt.push(next);
            }
            int t_3 = temp.x % 100 + (temp.x / 1000) * 1000 + i * 100;
            if(prim(t_3) && !vis[t_3])
            {
                g next;
                next.x = t_3;
                next.step = temp.step + 1;
                vis[t_3] = 1;
                myInt.push(next);
            }
            if(i!=0)
            {
                int t_4 = temp.x % 1000 + i*1000;
                if(prim(t_4) && !vis[t_4])
                {
                    g next;
                    next.x = t_4;
                    next.step = temp.step + 1;
                    vis[t_4] = 1;
                    myInt.push(next);
                }
            }
       }

    }
    return -1;
}



int main()
{
    cin >> N;
    while (N--)
    {
        memset(vis, 0, sizeof(vis));
        cin >> a >> b;
        result = false;
        int r = bfs();
        if(result)
            cout << r << endl;
        else cout << "Impossible" << endl;
    }
    return 0;
}

