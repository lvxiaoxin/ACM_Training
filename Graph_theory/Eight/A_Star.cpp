/**
 * Name: Eight
 * P_ID: POJ 1077
 * Note: A star algorithm + kantuo
 * date: 2016-05-19
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


const int cell = 362880;

//cantor Base 
int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int vis[cell];
int parent[cell];
char step[cell];

//dir
const int dir[][2] = {{-1, 0}, {1,  0}, {0, -1}, {0, 1}}; //u, d, l, r

int Hash(const char* str) 
{
    int n = 9;
    int num = 0;
    int temp;
    int i, j;
    for(i=0; i<n-1; ++i)
    {
        temp = 0;
        for(j=i+1; j<n; j++)
        {
            if(str[j] < str[i])
                temp++;
        }
        num += fac[str[i]-1] * temp;
    }
    return num;
}

struct node {
    char s[9];
    int space;
};



void get_node(int num, node &temp)
{
    int n = 9;
    int a[9];
    for(int i=2; i<=n; ++i)
    {
        a[i-1] = num%i;
        num /= i;
        temp.s[i-1] = 0;
    }
    temp.s[0] = 0;
    int rn, i;
    for(int k=n; k>=2; --k)
    {
        rn = 0;
        for(i=n-1; i>=0; --i)
        {
            if(temp.s[i]!=0)
                continue;
            if(rn==a[k-1])
                break;
            ++rn;
        }
        temp.s[i] = k;
    }
    for(int i=0; i<n; ++i)
    {
        if(temp.s[i]==0)
        {
            temp.s[i] = 1;
            break;
        }
    }
    temp.space = n - a[n-1] - 1;
}

int f[cell], d[cell];
int goal_state[9][2] = {
    {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}
};

int h(const char* str) 
{
    int k;
    int hv = 0;
    for(int i=0; i<3; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            k = i * 3 + j;
            if(str[k]!=9)
            {
                hv += abs(i - goal_state[str[k]-1][0]) + abs(j - goal_state[str[k]-1][1]);
            }
        }
    }
    return hv;
}


struct comp {
    bool operator () (int u, int v) {
        return f[u] > f[v];
    }
};

void A_star(const node &begin) 
{
    priority_queue<int, vector<int>, comp> myQue;
    memset(vis, 0, sizeof(vis));
    int u = Hash(begin.s);
    vis[u] = 1;
    parent[u] = -1;
    d[u] = 0;
    f[u] = h(begin.s);
    myQue.push(u);

    node now, next;
    while(!myQue.empty())
    {
        u = myQue.top();
        if(u==0) return;
        myQue.pop();

        get_node(u, now);

        int k = now.space;
        int x = k/3;
        int y = k%3;

        for(int i=0; i<4; ++i)
        {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if(xx>=0 && xx<=2 && yy>=0 && yy<=2)
            {
                next = now;
                next.space = xx * 3 + yy;
                swap(next.s[k], next.s[next.space]);
                int v = Hash(next.s);
                if(vis[v]==1 && (d[u]+1) < d[v]) 
                {
                    step[v] = i;
                    f[v] = f[v] - d[v] + d[u] + 1;
                    d[v] = d[u] + 1;
                    parent[v] = u;
                    myQue.push(v);
                }
                else if(vis[v]==0)
                {
                    step[v] = i;
                    d[v] = d[u] + 1;
                    f[v] = d[v] + h(next.s);
                    parent[v] = u;
                    myQue.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}

void print()
{
    int n, u;
    char path[1000];
    n = 1;
    path[0] = step[0];
    u = parent[0];
    while(parent[u]!=-1)
    {
        path[n] = step[u];
        ++n;
        u = parent[u];
    }

    for(int i=n-1; i>=0; --i)
    {
        if(path[i]==0)
            cout << "u";
        else if(path[i]==1)
            cout << "d";
        else if(path[i]==2)
            cout << "l";
        else
            cout << "r";
    }
}


int main()
{
    node start;
    char c;
    for(int i=0; i<9; ++i)
    {
        cin >> c;
        if(c=='x')
        {
            start.s[i] = 9;
            start.space = i;
        }
        else start.s[i] = c - '0';
    }

    A_star(start);

    if(vis[0]!=0)
        print();
    else
        printf("unsolvable"); 

    cout << endl;

	return 0;
}
