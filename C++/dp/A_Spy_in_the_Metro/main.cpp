/**
 * Name: A Spy in the Metro
 * P_ID: UVA 1025
 * date: 2016-06-01
 * Note: basic dp + modeling
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

int n, T, t[55], M1, d[55], M2, b[55];

bool train[210][55][2];

int dp[210][55];

void init()
{
    memset(train, false, sizeof(train));

    int temp = 0;
    for(int i=1; i<=M1; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            temp = d[i];
            for(int k=1; k<j; ++k)
            {
                temp += t[k];
            }
            if(temp>=0 && temp<=200)
                train[temp][j][0] = true;
        }
    }

    for(int i=1; i<=M2; ++i)
    {
        for(int j=n; j>=1; j--)
        {
            temp = b[i];
            for(int k=n; k>j; --k)
            {
                temp += t[k-1];
            }
            if(temp>=0 && temp <=200)
                train[temp][j][1] = true;
        }
    }
}

int main()
{
    int Case = 1;
	cin >> n;
    while(1)
    {
        memset(t, 0, sizeof(t));
        memset(d, 0, sizeof(d));
        memset(b, 0, sizeof(b));

        if(n==0) break;

        cin >> T;

        for(int i=1; i<n; ++i) dp[T][i] = MAXN;

        dp[T][n] = 0;

        for(int i=1; i<n; ++i)
            cin >> t[i];

        cin >> M1;

        for(int i=1; i<=M1; ++i) cin >> d[i];

        cin >> M2;

        for(int i=1; i<=M2; ++i) cin >> b[i];

        init();


        for(int i=T-1; i>=0; --i)
        {
            for(int j=1; j<=n; ++j)
            {
                dp[i][j] = dp[i+1][j] + 1;
                if(train[i][j][0] && j<n && i+t[j]<=T)
                    dp[i][j] = min(dp[i][j], dp[i+t[j]][j+1]);
                if(train[i][j][1] && j>1 && i+t[j-1]<=T)
                    dp[i][j] = min(dp[i][j], dp[i+t[j-1]][j-1]);
            }
        }

        int ans = dp[0][1];

        if(ans>=MAXN)
            cout << "Case Number " << Case << ": " << "impossible" << endl;
        else 
            cout << "Case Number " << Case << ": " << ans << endl;

        Case++;

        cin >> n;
    }
	return 0;
}
