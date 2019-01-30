/**
 *
 * Name: Eight
 * P_ID: POJ 1077
 * Date: 2016-05-30
 * Note: IDA star + 八数码无解判定 + 剪枝
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

struct node {
    char s[9];
    int space;
};


node start;
const int dir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; //u, d, l, r
int maxD;
int mov[1000];


int cal_h() 
{
    int ans = 0;
    for(int i=0; i<9; ++i)
    {
        if(start.s[i]==9) continue;
        int x = (start.s[i]-1)/3;
        int y = (start.s[i]-1)%3;
        int nx = i/3;
        int ny = i%3;
        ans += abs(x-nx) + abs(y-ny);
    }
    return ans;
}


bool dfs(int d, int last)
{
    if(d==maxD)
    {
        if(cal_h()==0) return true;
        return false;
    }
    for(int i=0; i<4; ++i)
    {
        int xx = start.space/3 + dir[i][0];
        int yy = start.space%3 + dir[i][1];
        int newP;
        if(xx<0 || xx>2 || yy<0 || yy >2) continue;
        else
            newP = xx*3 + yy;
        swap(start.s[newP], start.s[start.space]);
        swap(start.space, newP);
        if(d+cal_h() > maxD)
        {
            swap(start.s[newP], start.s[start.space]);
            swap(start.space, newP);
            continue;
        }
        mov[d+1] = i;
        if(dfs(d+1, i)) return true;
        swap(start.s[newP], start.s[start.space]);
        swap(start.space, newP);
    }
    return false;
}

void IDA_Star() 
{
    maxD = 0;
    while(1)
    {
        if(dfs(0, 100)) return;
        maxD++;
    }
}

bool Unsolve()
{
    int cnt = 0;
    for(int i=0; i<9; ++i)
    {
        if(start.s[i]==9) continue;
        for(int j=0; j<i; ++j) 
        {
            if(start.s[j]==9) continue;
            if(start.s[j] > start.s[i]) cnt++;
        }
    }
    return !(cnt%2);
}

void print(int dep)
{
    if(!dep) return;
    print(dep-1);
    if(!mov[dep]) printf("u");
    else if(mov[dep]==1) printf("l");
    else if(mov[dep]==2) printf("d");
    else printf("r");
}

int main()
{
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

    if(!Unsolve()) printf("unsolvable");
    else 
    {
        IDA_Star();
        print(maxD);
    }
    cout << endl;

	return 0;
}
