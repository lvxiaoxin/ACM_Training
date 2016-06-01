/**
 *
 * Name: 数字三角形
 * P_ID: BNU 50925
 * Date: 2016-06-01
 * Note: basic dp
 *
 */
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[105][105];
int map[105][105];

int ans;
int n;

int solve(int x, int y)
{
    if(dp[x][y]>=0) return dp[x][y];
    else
    {
        if(x==n) return map[x][y];
        else
        {
            dp[x][y] = map[x][y] + max(solve(x+1, y), solve(x+1, y+1));
            return dp[x][y];
        }
    }
}

int main()
{
    cin >> n;
    memset(map, 0, sizeof(map));
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=i; ++j)
            cin >> map[i][j];
    }
    memset(dp, -1, sizeof(dp));

    ans = solve(1, 1);

    cout << ans << endl;
}
