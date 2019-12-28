#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int dp[35][100], a[35], p;
int dfs(int pos, int num, bool lead, bool limit) {
	if (pos == -1) return num >= 32;
	if (!lead && !limit && dp[pos][num] != -1)
		return dp[pos][num];
	int up = limit ? a[pos] : 1;
	int ans = 0;
	for (int i = 0; i <= up; ++i) {
		if (lead && i == 0)
			ans += dfs(pos - 1, num, lead && i == 0, limit && i == a[pos]);
		else
			ans += dfs(pos - 1, num + (i == 0 ? 1 : -1), lead && i == 0, limit && i == a[pos]);
	}
	if (!lead && !limit)
		dp[pos][num] = ans;
	return ans;
}
int solve(int x) {
	p = 0;
	while (x) {
		a[p++] = x % 2;
		x /= 2;
	}
	return dfs(p - 1, 32, true, true);
}
int main()
{
	memset(dp, -1, sizeof(dp));
	int a, b;
	while (~scanf("%d%d", &a, &b)) {
		printf("%d\n", solve(b) - solve(a - 1));
	}
}