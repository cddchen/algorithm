#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 5;
int pre[maxn][maxn], nxt[maxn][maxn];
int a[maxn];
int main()
{
	freopen("in.txt", "r", stdin);
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		for (int j = 1; j <= m; ++j)
			pre[i][j] = 0, nxt[i][j] = n + 1;
	}
	nxt[0][a[1]] = 1;
	pre[n + 1][a[n]] = n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			pre[i][j] = pre[i - 1][j];
		pre[i][a[i - 1]] = i - 1;
	}
	for (int i = n; i >= 1; --i) {
		for (int j = 1; j <= m; ++j) 
			nxt[i][j] = nxt[i + 1][j];
		nxt[i][a[i + 1]] = i + 1;
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d\n", i);
		for (int j = 1; j <= m; ++j) {
			printf("%d %d\n", pre[i][j], nxt[i][j]);
		}
	}
	ll ans = 0;
	for (int j = 1; j <= m; ++j) {
		for (int i = 1; i <= n; ++i) { //mid
			int l = i, r = i;
			if (pre[l][j] != 0 && nxt[r][j] != n + 1) ans += 2;
			else ans++;
			while (pre[l][j] != 0 && nxt[r][j] != n + 1) {
				ans += (l - pre[l][j]) * (nxt[r][j] - r);
				l = pre[l][j]; r = nxt[r][j];
			}
		}
	}
	printf("%lld\n", ans);
}