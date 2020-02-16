#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
vector< pair<int, int> >E[maxn];
unordered_map<int, int> vis;
int a[maxn], dfn[maxn], tot, fa[maxn], topf[maxn], sz[maxn], son[maxn], deep[maxn];
void dfs1(int u, int f) {
	sz[u] = 1; fa[u] = f;
	for (auto e : E[u]) {
		int v = e.first, w = e.second;
		if (v == f) continue;
		deep[v] = deep[u] + 1;
		dfs1(v, u);
		sz[u] += sz[v];
		if (sz[v] > sz[son[u]]) son[u] = v;
	}
}
void dfs2(int u, int tf) {
	topf[u] = tf;
	dfn[u] = ++tot;
	if (!son[u]) return;
	dfs2(son[u], tf);
	for (auto e : E[u]) {
		int v = e.first, w = e.second;
		if (!topf[v])
			dfs2(v, v);
	}
}
int LCA(int x, int y) {
	while (topf[x] != topf[y]) {
		if (deep[topf[x]] < deep[topf[y]])
			swap(x, y);
		x = fa[topf[x]];
	}
	if (deep[x] < deep[y]) swap(x, y);
	return y;
}
int main()
{
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 1; i < n; ++i) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		E[u].push_back(make_pair(v, w));
		E[v].push_back(make_pair(u, w));
	}
	for (int i = 0; i < k; ++i) {
		int x; scanf("%d", &x);
		vis[x] = 1;
	}
}