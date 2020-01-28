#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
vector<int> e[maxn];
int fa[maxn], sz[maxn], son[maxn];

void dfs(int u) {
	sz[u] = 1;
	for (int v : e[u]) {
		fa[v] = u;
		dfs(v);
		sz[u] += sz[v];
		if (!son[u] || sz[son[u]] < sz[v])
			son[u] = v;
	}
}
set<ll> s;
ll res, ans[maxn];
int Son;
void calc(int u) {
	s.insert(u);
	auto it = s.find(u);
	if (s.size() == 1) {

	}
	else if (it == s.begin()) {
		ll x = *(++s.begin()) - u;
		res += x * x;
	}
	else if (it == (--s.end())) {
		ll x = (*(--it)) - u;
		res += x * x;
	}
	else {
		auto itt = it;
		ll a = *(--it), b = u, c = *(++itt);
		res -= (a - c) * (a - c);
		res += (a - b) * (a - b) + (b - c) * (b - c);
	}

	for (int v : e[u]) {
		if (v == Son)
			continue;
		calc(v);
	}
}
void solve(int u, int keep) {
	for (int v : e[u]) {
		if (v == son[u])
			continue;
		solve(v, false);
	}
	if (son[u]) {
		solve(son[u], true);
		Son = son[u];
	}
	
	calc(u);
	Son = 0;
	ans[u] = res;
	if (!keep) {
		s.clear();
		res = 0;
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	for (int i = 2; i <= n; ++i) {
		int x; cin >> x;
		e[x].push_back(i);
	}
	dfs(1);
	solve(1, true);
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << '\n';
}