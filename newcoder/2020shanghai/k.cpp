#include <bits/stdc++.h>
using namespace std;
const int maxn = 16 + 3;
const int maxm = maxn * maxn / 2;
vector< pair<int, int> > E;

int main()
{
	int t; scanf("%d", &t);
	for (int cas = 1; cas <= t; ++cas) {
		int n, m; scanf("%d%d", &n, &m);
		E.clear();
		for (int i = 1; i <= m; ++i) {
			int u, v; scanf("%d%d", &u, &v);
			E.push_back(make_pair(u, v));
		}
		int limit = 1 << n;
		int ans = 0;
		for (int i = 0; i < limit; ++i) {
			int vis[maxn] = {0}, res = 0;
			for (int j = 0; j < n; ++j) {
				if ((i >> j) & 1) {
					vis[j + 1] = 1;
				}
			}
			for (auto e : E) {
				if (vis[e.first] != vis[e.second]) {
					res++;
				}
			}
			ans = max(ans, res);
		}
		printf("Case #%d: %d\n", cas, ans);
	}
}