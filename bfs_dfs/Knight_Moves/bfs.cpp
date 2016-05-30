/**
 * 
 * Name: Knight Moves
 * P_ID: POJ 2243
 * Note: bfs
 * Date: 2016-05-30
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
    int step;
};

int vis[10][10];


int bfs(int x, int y)
{
    node begin;
    begin.x = x;
    begin.y = y;
    begin.step = 0;
    queue<node> myQue;
    myQue.push(begin);
    memset(vis, 0, sizeof(vis));

    node now, next;
    while(!myQue.empty())
    {
        now = myQue.front();
        vis[now.x][now.y] = 1;
        if(now.x==ex && now.y==ey) return now.step;
        myQue.pop();

        for(int i=0; i<8; ++i)
        {
            int xx = now.x + dir[i][0];
            int yy = now.y + dir[i][1];
            if(xx>=0 && xx<8 && yy>=0 && yy<8 && vis[xx][yy]==0)
            {
                next.x = xx;
                next.y = yy;
                next.step = now.step + 1;
                if(next.x==ex && next.y==ey) return next.step;
                myQue.push(next);
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
   
        int ans = bfs(bx, by);

        cout<<"To get from "<< s1 <<" to "<< s2 << " takes "<< ans <<" knight moves."<<endl;
    }
	return 0;
}
