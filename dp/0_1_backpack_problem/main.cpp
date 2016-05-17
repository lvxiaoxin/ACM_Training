/**
 * Name: 0 1 背包问题
 * P_ID: BNUOJ 4183
 * note: 基础01背包
 * date: 2016-5-15
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


int w[1010], v[1010], dp[1010][1001];

int main()
{
    memset(w, 0, sizeof(w));
    memset(v, 0, sizeof(v));
    memset(dp, 0, sizeof(dp));

    int n, c;
    cin >> n >> c;

    for(int i=1; i<=n; ++i)
        cin >> w[i] >> v[i];

    for(int i=1; i<=n; ++i)
    {
        for(int j=0; j<=c; ++j)
        {
            dp[i][j] = dp[i-1][j];
            if(j>=w[i])
                dp[i][c] = max(dp[i][c], dp[i-1][c-w[i]] + v[i]);
        }
    }

    cout << dp[n][c] << endl;

    int temp = c;
    
    for(int i=n; i>0 && temp>0; i--)
    {
        if(dp[i][temp]!=dp[i-1][temp])
        {
            cout << i-1 << " ";
            temp -= w[i];
        }
    }
    cout << endl;
    return 0;
}
