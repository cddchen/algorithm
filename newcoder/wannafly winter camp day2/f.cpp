#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;

vector<pair<int, int>>e[maxn];
int fa[maxn], sz[maxn], son[maxn], dep[maxn];
int top[maxn], id[maxn], rk[maxn];
int tot;
void dfs1(int u, int father) {
	dep[u] = dep[father] + 1; fa[u] = father; sz[u] = 1;
	for (auto &i : e[u]) {
		int v = i.first; 
		if (v == father) continue;
		dfs1(v, u);
		sz[u] += sz[v];
		if (sz[son[u]] < sz[v])
			son[u] = v;
	}
}
void dfs2(int u, int root) {
	top[u] = root; id[u] = ++tot; rk[tot] = u;
	if (son[u])
		dfs2(son[u], u);
	for (auto i : e[u]) {
		int v = i.first;
		if (v == fa[u] || v == son[u])
			continue;
		dfs2(v, u);
	}
}
int lca(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]])
			swap(x, y);
		x = fa[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}

ll t[maxn << 2];
void pushup(int rt) {
	t[rt] = t[rt << 1] + t[rt << 1 | 1];
}
void update(int rt, int l, int r, int pos, int val) {
	if (l == r) {
		t[rt] += val;
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid)
		update(rt << 1, l, mid, pos, val);
	else
		update(rt << 1 | 1, mid + 1, r, pos, val);
	pushup(rt);
}
ll query(int rt, int l, int r, int L, int R) {
	if (L <= l && r <= R)
		return t[rt];
	int mid = (l + r) >> 1;
	ll rhs = 0;
	if (L <= mid)
		rhs += query(rt << 1, l, mid, L, R);
	if (mid < R)
		rhs += query(rt << 1 | 1, mid + 1, r, L, R);
	return rhs;
}
int main()
{
	int n; scanf("%d", &n);
	int s = 1;
	for (int i = 1; i < n; ++i) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		e[u].push_back(make_pair(v, w));
		e[v].push_back(make_pair(u, w));
	}
	dfs1(1, 0);
	dfs2(1, 0);
	int m; scanf("%d", &m);
	while (m--) {
		int op, v, x; scanf("%d%d", &op, &v);
		if (op == 1) {
			scanf("%d", &x);
			update(1, 1, n, id[v], x);
		}
		else s = v;
		ll rhs = 0;
		for (auto i : e[s]) {
			int v = i.first, w = i.second;
			if (v == fa[s])
				rhs += 1ll * w * (t[1] - query(1, 1, n, id[s], id[s] + sz[s] - 1));
			else
				rhs += 1ll * w * query(1, 1, n, id[v], id[v] + sz[v] - 1);
		}
		printf("%lld\n", rhs);
	}
}