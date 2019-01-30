/**
 * Name: Team Queue
 * P_ID: UVA 540
 * Note: 嵌套queue + map + set
 * Date: 2016-05-18
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

int vis[1010];

int main()
{
    int n;
    int cc = 1;
    while(scanf("%d", &n)&&n!=0)
    {
       cout << "Scenario #" << cc << endl;
       map<int, set<int> > Team;
       queue<int> S;
       map<int, queue<int> > s;
       memset(vis, 0, sizeof(vis));
       for(int i=0; i<n; ++i)
       {
           int nn;
           scanf("%d", &nn);
           set<int> team;
           for(int j=0; j<nn; j++)
           {
               int temp;
               scanf("%d", &temp);
               team.insert(temp);
           }
           Team[i] = team;
       }
       string op;
       cin >> op;
 
       while(1) {
       if(op[0]=='E')
       {
           int tmp;
           cin >> tmp;
           int flag = MAXN;
           for(int i=0; i<n; ++i)
           {
               if(Team[i].count(tmp)!=0)
               {
                   flag = i;
                   break;
               }
           }
           if(vis[flag]==0)
           {
                s[flag].push(tmp);
                S.push(flag);
                vis[flag] = 1;
           }
           else 
           {
                s[flag].push(tmp);
           }
       }
       else if(op[0]=='D')
       {
           int a = S.front();
           int out = s[a].front();
           cout << out << endl;
           s[a].pop();
           if(s[a].empty())
           {
               int b = S.front();
               S.pop();
               vis[b] = 0;
           }
       }
       else if(op[0]=='S')
       {
            break;
       }
       cin >> op;
       }
       cout << endl;
       cc++;
    }
	return 0;
}
