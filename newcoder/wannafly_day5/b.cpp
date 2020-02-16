#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int op[maxn], ans[maxn], in[maxn];
pair<int, int> a[maxn];
int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) ans[i] = 1, in[i] = 0;
	for (int i = 1; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	for (int i = 1; i <= m; ++i) 
		cin >> op[i];
	for (int i = m; i >= 1; --i) {
		int id = op[i];
		int u = a[id].first, v = a[id].second;
		int tmp = ans[u] + ans[v] - in[id];
		ans[u] = ans[v] = in[id] = tmp;
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
}