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

int T, n, t[55];
int c;
int dp[110][110];

int main()
{
    int Case = 1;
    cin >> c;
    while(c--)
    {
        memset(dp, 0, sizeof(dp));
        memset(t, 0, sizeof(t));
        cin >> n >> T;
        int sumt = 0;
        for(int i=1; i<=n; ++i)
        {
            cin >> t[i];
            sumt += t[i];
        }
        
        T = min(T, sumt+1);
        T--;

        int ans = 0, ans2 = 0;

        for(int i=1; i<=n; ++i)
        {
            for(int j=0; j<=T; ++j)
            {
                dp[i][j] = dp[i-1][j];
                if(j>=t[i])
                {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-t[i]]+1);
                }
                    
            }
        }
        ans = dp[n][T];
        ans++;
        ans2 += 678;

        cout << "Case " << Case << ": " << ans << " " << ans2 << endl;
        Case++;
    }
	
	return 0;
}
