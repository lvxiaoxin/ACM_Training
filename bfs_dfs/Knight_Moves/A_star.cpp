/**
 * 
 * Name: Knight Moves
 * P_ID: POJ 2243
 * Note: A* algorithm
 * Date: 2016-05-27
 *
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

const int dir[][2] = {{1, 2}, {-1, 2}, {-1, -2}, {1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}}; 

int ex, ey;


struct node{
    int x;
    int y;
    int f;
    int g;
    int step;
    bool operator < (const node & a) const 
    {
        return f > a.f;
    }
};

int vis[10][10];

int h(int x, int y)
{
    //int hv = 0;
    //hv = abs(x - ex) + abs(y - ey);

    double a = abs(x-ex);
    double b = abs(y-ey);
    //double hv = sqrt(a*a + b*b);
    double hv = max(a, b);
    return (int)hv;
}

int A_star(int x, int y) 
{
    priority_queue<node> myQue;
    memset(vis, 0, sizeof(vis));
    node begin;
    begin.x = x;
    begin.y = y;
    begin.g = 0;
    begin.f = h(x, y);
    begin.step = 0;
    myQue.push(begin);

    node now, next;
    while(!myQue.empty())
    {
        now = myQue.top();
        if(now.x==ex && now.y==ey) return now.step;
        vis[now.x][now.y] = 1;
        myQue.pop();

        for(int i=0; i<8; ++i)
        {
            int xx = now.x + dir[i][0];
            int yy = now.y + dir[i][1];
            if(xx>=0 && xx<8 && yy>=0 && yy<8) 
            {
                if(vis[xx][yy]==0) 
                {
                    next.x = xx;
                    next.y = yy;
                    next.step = now.step + 1;
                    next.g = now.g + 1;
                    next.f = next.g + h(next.x, next.y); 
                    if(now.x==ex && now.y==ey) return now.step;
                    myQue.push(next);
                }
            }
        }
    }
    return -1;
}

int main()
{
    string s1, s2;
    while(cin >> s1 >> s2) 
    {
        int  bx = s1[0] - 'a';
        ex = s2[0] - 'a';
        int by = s1[1] - '1';
        ey = s2[1] - '1';
   
        int ans = A_star(bx, by);

        cout<<"To get from "<< s1 <<" to "<< s2 << " takes "<< ans <<" knight moves."<<endl;
    }
	return 0;
}
