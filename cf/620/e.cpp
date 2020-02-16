#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> E[maxn];
int fa[maxn], sz[maxn], son[maxn], dep[maxn], top[maxn];
void dfs(int u, int f) {
	sz[u] = 1, fa[u] = f; dep[u] = dep[f] + 1;
	for (auto v : E[u]) {
		if (v == f) continue;
		dfs(v, u);
		sz[u] += sz[v];
		if (sz[v] > sz[son[u]]) son[u] = v;
	}
}
void dfs1(int u, int tf) {
	top[u] = tf;
	if (!son[u]) return;
	dfs1(son[u], tf);
	for (auto v : E[u]) {
		if (v == fa[u] || v == son[u]) continue;
		dfs1(v, v);
	}
}
int get_lca(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	return x;
}
int get_dis(int x, int y) {
	if (x > y) swap(x, y);
	if (x == y) return 0;
	return dep[x] + dep[y] - 2 * dep[get_lca(x, y)];
}
int q, x, y, a, b, k;
bool solve() {
	cin >> x >> y >> a >> b >> k;
	int dis_xy = get_dis(x, y);
	int dis_ab = get_dis(a, b);
	int dis_ax = get_dis(a, x);
	int dis_ay = get_dis(a, y);
	int dis_xb = get_dis(x, b);
	int dis_yb = get_dis(y, b);
	//cout << "xy=" << dis_xy << ",ab=" << dis_ab << ",ax=" << dis_ax << ",ay=" << dis_ay << ",xb=" << dis_xb << ",yb=" << dis_yb << endl;
	if (k >= dis_ab && (k - dis_ab) % 2 == 0)
		return true;
	if (k >= dis_ax + dis_xy + dis_yb && (k - dis_ax - dis_xy - dis_yb) % 2 == 0)
		return true;
	if (k >= dis_ax + 1 + dis_yb && (k - dis_ax - 1 - dis_yb) % 2 == 0)
		return true;
	if (k >= dis_ay + dis_xy + dis_xb && (k - dis_ay - dis_xy - dis_xb) % 2 == 0)
		return true;
	if (k >= dis_ay + 1 + dis_xb && (k - dis_ay - 1 - dis_xb) % 2 == 0)
		return true;
	if (k >= dis_ax + dis_xb && (k - dis_ax - dis_xb) % 2 == 0)
		return true;
	if (k >= dis_ay + dis_yb && (k - dis_ay - dis_yb) % 2 ==0)
		return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs(1, 0); dfs1(1, 1);
	cin >> q;
	while (q--) {
		cout << (solve() ? "YES" : "NO") << '\n';
	}
}