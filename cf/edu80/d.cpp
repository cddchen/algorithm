#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 5;
const int digit = 8 + 2;
int n, m, mx;
int a[maxn][digit];
int dp[1 << digit];
bool solve(int x) {
	memset(dp, 1, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		int tmp = 0;
		for (int j = 0; j < m; ++j) 
			if (a[i][j] >= x) 
				tmp += (1 << j);

		//printf("%d - %d\n", i, tmp);
		for (int j = 0; j < mx; ++j) 
			dp[(tmp | j)] = min(dp[(tmp | j)], dp[j] + 1);
	}
	//printf("%d - %d\n", x, dp[mx - 1]);
	return dp[mx - 1] <= 2;
}
int id[1 << digit];
void getAns(int x) {
	memset(dp, 1, sizeof(dp));
	memset(id, -1, sizeof(id));
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		int tmp = 0;
		for (int j = 0; j < m; ++j) 
			if (a[i][j] >= x) 
				tmp += (1 << j);

		id[tmp] = i;
		for (int j = 0; j < mx; ++j)  {
			if (dp[j] + 1 < dp[(tmp | j)]) {
				dp[(tmp | j)] = dp[j] + 1;
				if (dp[(tmp | j)] <= 2 && (tmp | j) == mx - 1) {
					printf("%d %d\n", id[j] == -1 ? id[tmp] + 1 : id[j] + 1, id[tmp] + 1);
					return;
				}
			}
		}
	}

}
int main()
{
	scanf("%d%d", &n, &m); mx = (1 << m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	int l = 0, r = 1e9 + 1;
	while (l < r) {
		int mid = l + (r - l) / 2;
		//printf("%d - %d\n", l, r);
		if (!solve(mid))
			r = mid;
		else
			l = mid + 1;
	}
	getAns(l - 1);
}