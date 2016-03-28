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



int prework(int x, int i)
{
 //   x = (x/(int)pow(10, i))*(int)pow(10,i) + x%((x/(int)pow(10, i-1))*(int)pow(10, i-1)) + (int)pow(10, i-1);
    if(i==1)
        x = (x/10)*10 + 1;
    else if(i==2)
        x = (x/100)*100 + x%((x/10)*10) + 10;
    else if(i==3)
        x = (x/1000)*1000 + x%((x/100)*100) + 100;
    else if(i==4)
        x = (x/10000)*10000 + x%((x/1000)*1000) + 1000;
    return x;

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
        for(int i=1; i<=4; ++i)
        {
            g ff = temp;
            temp.x = prework(temp.x, i);
            for(int j=0; j<=9; ++j)
            {
                g tt = temp;
                tt.x += j*i*(int)(pow(10, i-1));
                if(prim(tt.x))
                {
                    g next;
                    next.x = tt.x;
                    next.step = ++tt.step;
                    myInt.push(next);
                }
            }
            temp = ff;
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
        if(a==b)
        {
            cout << "0" << endl;
            return 0;
        }
        result = false;
        int r = bfs();
        if(result)
            cout << r << endl;
        else cout << "Impossible" << endl;
    }
    return 0;
}
