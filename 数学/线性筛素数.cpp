#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;
//任何合数都能表示成一系列素数的积
int prime[maxn], cnt;
int vis[maxn];
void solve(int n) {
	vis[0] = vis[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (!vis[i])
			prime[cnt++] = i;
		for (int j = 0; j < cnt && i * prime[j] <= n; ++j) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0)
				break;
		}
	}
}
int main()
{
	int n, m; scanf("%d%d", &n, &m);
	solve(n);
	for (int i = 0; i < m; ++i) {
		int x; scanf("%d", &x);
		printf("%s\n", !vis[x] ? "Yes" : "No");
	}
}