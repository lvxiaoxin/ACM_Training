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

int d[1010][1010];


const int dir[][2] = {{1, 2}, {-1, 2}, {-1, -2}, {1, -2}, {2 ,1}, {2, -1}, {-2, 1}, {-2, -1}};

int ex, ey;


struct node{
    int x;
    int y;
    int f;
    bool operator < (const node & k) const 
    {
        return f > k.f;
    }
};

/*
struct comp {
    bool operator() (const node a, const node b) const
    {
        return a.f < b.f;
    }
};
*/


int h(int x, int y)
{
    int hv = 0;
    hv += abs(x - ex) + abs(y - ey);
    return hv*10;
}

int A_star(int x, int y)
{
    priority_queue<node> myQue;
    memset(d, 0, sizeof(d));
    node begin;
    begin.x = x;
    begin.y = y;
    begin.f = h(x, y);
    myQue.push(begin);
    d[x][y] = 0;

    node now, next;
    while(!myQue.empty())
    {
        now = myQue.top();
        if(now.x==ex && now.y==ey) return d[now.x][now.y];
        myQue.pop();

        for(int i=0; i<8; ++i)
        {
            int xx = now.x + dir[i][0];
            int yy = now.y + dir[i][1];
            if(xx>=1 && xx<=8 && yy>=1 && yy<=8)
            {
                if(d[xx][yy]==0)
                {
                    next.x = xx;
                    next.y = yy;
                    next.f = d[now.x][now.y] + h(next.x, next.y) + 1;
                    d[next.x][next.y] = d[now.x][now.y] + 1;
                    myQue.push(next);
                }
                else
                {
                    if( (d[now.x][now.y]+1) < d[next.x][next.y])
                    {
                        next.f = next.f - d[next.x][next.y] + d[now.x][now.y] + 1;
                        d[next.x][next.y] = d[now.x][now.y] + 1;
                        myQue.push(next);
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    char s[6];
    while(gets(s))
    {
        int a = s[0] - 'a' + 1;
        ey = s[3] - 'a' + 1;
        int aa = s[1] - '0';
        ex = s[4] - '0';

        int ans = A_star(a, aa);

        cout<<"To get from "<< s[0] << s[1] <<" to "<< s[3] << s[4] <<" takes "<< ans <<" knight moves."<<endl;
    }
    return 0;
}

