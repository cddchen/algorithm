#include <cassert>
#include <cmath>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map> 
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int maxn = 1e4 + 5;
int dp[13][maxn];
int fib_2[13];
int a[13], p, all;
int dfs(int pos, int sum, bool limit) {
	if (pos == -1) return sum <= all;
	if (sum > all) return 0;
	if (!limit && dp[pos][all - sum] != -1)
		return dp[pos][all - sum];
	int up = limit ? a[pos] : 9, ans = 0;
	for (int i = 0; i <= up; ++i) 
		ans += dfs(pos - 1, sum + i * fib_2[pos], limit && i == a[pos]);

	if (!limit) 
		dp[pos][all - sum] = ans;
	return ans;
}
int solve(int x, int y) {
	p = all = 0;
	for (int i = 0; x; ++i) {
		all += (x % 10) * fib_2[i];
		x /= 10;
	}
	while (y) {
		a[p++] = y % 10;
		y /= 10;
	}
	return dfs(p - 1, 0, 1);
}

int main()
{
	fib_2[0] = 1;
	for (int i = 1; i <= 9; ++i)
		fib_2[i] = fib_2[i - 1] * 2;
	memset(dp, -1, sizeof(dp));
	int t; scanf("%d", &t);
	for (int cas = 1; cas <= t; ++cas) {
		int x, y; scanf("%d%d", &x, &y);
		printf("Case #%d: %d\n", cas, solve(x, y));
	}
}