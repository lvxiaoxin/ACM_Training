/**
 * Namw: The Tower of babylon
 * P_ID: UVA 437
 * Date: 2016-06-02
 * Note: difficult to memory tower
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


int n;
int dp[40][3];

struct Tower{
    int d[3][3];
    Tower(int a, int b, int c) 
    {
        d[0][0] = min(b, c); d[0][1] = max(b, c); d[0][2] = a;
        d[1][0] = min(a, c); d[1][1] = max(a, c); d[1][2] = b;
        d[2][0] = min(a, b); d[2][1] = max(a, b); d[2][2] = c;
    }
};

vector<Tower> v;



int solve(int idx, int k)
{
    int &ans = dp[idx][k];
    if(ans >= 0) return ans;
    ans = v[idx].d[k][2];
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            if(v[i].d[j][0] < v[idx].d[k][0] && v[i].d[j][1] < v[idx].d[k][1])
                ans = max(ans, solve(i, j)+v[idx].d[k][2]);
        }
    }
    return ans;
}


int main()
{
    int C = 1;
    while(scanf("%d", &n) && n)
    {
        v.clear();
        int a, b, c;
        for(int i=1; i<=n; ++i)
        {
            cin >> a >> b >> c;
            v.push_back(Tower(a, b, c));
        }
        memset(dp, -1, sizeof(dp));
        int ans = -1;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<3; ++j)
            {
                ans = max(ans, solve(i, j));
            }
        }

        cout << "Case " << C << ": maximum height = " << ans << endl;
        C++;
    }
	return 0;
}
