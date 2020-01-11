#include <bits/stdc++.h>
using namespace std;
#define odd (a[i]&1)
const int maxn = 1e2 + 5;
int a[maxn];
int dp[maxn][maxn][2];

int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", &a[i]);
	int c = (n + 1) / 2;
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0][0] = dp[0][0][1] = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i]) {
			for (int j = 0; j <= c; ++j) {
				dp[i][j + odd][odd] = min(dp[i][j + odd][odd], 
					min(dp[i - 1][j][odd], dp[i - 1][j][1 - odd] + 1));
			}
		}
		else {
			for (int j = 0; j <= c; ++j) {
				dp[i][j][0] = min(dp[i][j][0], 
					min(dp[i - 1][j][0], dp[i - 1][j][1] + 1));
				if (j >= 1)
					dp[i][j][1] = min(dp[i][j][1], 
						min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][0] + 1));
			}
		}
	}
	printf("%d\n", min(dp[n][c][0], dp[n][c][1]));
}