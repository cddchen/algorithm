#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> e[maxn];
int fa[maxn], sz[maxn];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
map<int, int> rd;
int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		fa[i] = i, sz[i] = 1;
	bool flg = false, able = true;
	for (int i = 0; i < m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		if (find(u) == find(v)) {
			if (flg) able = false;
			else flg = true;
			continue;
		}
		sz[find(v)] += sz[find(u)];
		fa[find(u)] = find(v);
	}
	if (!able)
		printf("-1\n");
	else {
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (rd.count(find(i)) > 0)
				continue;
			rd[find(i)] = sz[find(i)];
			ans = max(sz[find(i)], ans);
		}
		printf("%d\n", ans);
	}
}