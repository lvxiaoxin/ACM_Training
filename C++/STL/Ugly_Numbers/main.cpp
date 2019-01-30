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

typedef long long ll;

int mut[] = {2, 3, 5};
int main()
{
	int n;
    while(scanf("%d", &n) && n!=0)
    {
        priority_queue<ll, vector<ll>, greater<ll> > num;
        set<ll> s;
        num.push(1);
        s.insert(1);
        for(int i=1; ; i++)
        {
            ll x = num.top();
            num.pop();
            if(n==i)
            {
                cout << x << endl;
                break;
            }
            for(int j=0; j<3; ++j)
            {
                ll xx = x * mut[j];
                if(!s.count(xx))
                {
                    s.insert(xx);
                    num.push(xx);
                }
            }
        }
    }
	return 0;
}
