#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 5;
const ll mod = 1e9 + 7;
ll add(ll a, ll b) {
	if (a + b >= mod)
		return a + b - mod;
	return a + b;
}
ll mul(ll a, ll b) {
	return a * b >= mod ? a * b % mod : a * b;
}
struct node
{
	ll cnt, sum, sqr;
	node() {}
	node(ll _cnt, ll _sum, ll _sqr) {
		cnt = _cnt; sum = _sum; sqr = _sqr;
	}
} dp[25][10][10];
int a[25], p;
ll fib_10[25];
node dfs(int pos, int sum, int val, bool limit) {
	if (pos == -1) {
		if (sum != 0 && val != 0)
			return node(1, 0, 0);
		return node(0, 0, 0);
	}
	if (!limit && dp[pos][sum][val].cnt != -1) 
		return dp[pos][sum][val];
	int up = limit ? a[pos] : 9;
	node now = node(0, 0, 0);
	for (int i = 0; i <= up; ++i) {
		if (i == 7) continue;
		node rhs = dfs(pos - 1, (sum + i) % 7, (val * 10 + i) % 7, limit && i == a[pos]); 
		if (rhs.cnt == 0) 
			continue;    
		now.cnt = add(now.cnt, rhs.cnt);
		ll A = mul(i, fib_10[pos]);
		now.sum = add(now.sum, add(rhs.sum, mul(rhs.cnt, A)));
		now.sqr = add(add(add(mul(rhs.cnt, mul(A, A)), mul(2 * A, rhs.sum)), rhs.sqr), now.sqr);
	}
	if (!limit)
		dp[pos][sum][val] = now;
	return now;
}      
ll solve(ll x) {
	p = 0;
	while (x) {
		a[p++] = x % 10;
		x /= 10;
	}
	return dfs(p - 1, 0, 0, true).sqr;
}

int main()
{
	fib_10[0] = 1;
	for (int i = 1; i <= 20; ++i)
		fib_10[i] = mul(fib_10[i - 1], 10);
	for (int i = 0; i <= 20; ++i)
		for (int j = 0; j <= 9; ++j)
			for (int k = 0; k <= 9; ++k)
				dp[i][j][k].cnt = -1;
	int t; scanf("%d", &t);
	while (t--) {
		ll a, b; scanf("%lld%lld", &a, &b);
		printf("%lld\n", (solve(b) - solve(a - 1) + mod) % mod);
	}
}