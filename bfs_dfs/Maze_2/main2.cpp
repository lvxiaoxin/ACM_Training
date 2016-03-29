#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#define Mod 1908
using namespace std;
bool visited[100][100];
int dp[100][100];
char maze[100][100];
int sx, sy, ex, ey, n, m;
void dpsearch(int p, int q)
{
	if (p > sx || q < sy || maze[p][q] == '*')return;
	if (!visited[p][q]){
		visited[p][q] = 1;
		dpsearch(p + 1, q);
		dpsearch(p, q - 1);
		if (p < n)dp[p][q] += dp[p + 1][q] % Mod;
		if (q > 0)dp[p][q] += dp[p][q - 1] % Mod;
	}
}
int main()
{
	scanf("%d%d%*c", &n, &m);
	for (int i = 0; i <= n - 1; i++){
		for (int j = 0; j <= m - 1; j++){
			scanf("%c", &maze[i][j]);
			if (maze[i][j] == 'S'){
				sx = i;
				sy = j;
			}
			if (maze[i][j] == 'T'){
				ex = i;
				ey = j;
			}
		}
		scanf("%*c");
	}
	dp[sx][sy] = 1;
	dpsearch(ex, ey);
	printf("%d\n", dp[ex][ey] % Mod);
	return 0;
}
