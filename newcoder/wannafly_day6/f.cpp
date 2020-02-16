#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;
typedef long long ll;
int cnt[maxn][2];
int A, B, C, P, D;
bool cal(int i, int j) {
	ll rhs = 1ll * A * (i + j) * (i + j) + 1ll * B * (i - j) * (i - j) + C;
	rhs = rhs % P;
	return rhs > D;
}
struct node {
	int u, v, col;
	node() {}
	node(int _u, int _v, int _col) : u(_u), v(_v), col(_col) {}
};
vector<node> p;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	cin >> A >> B >> C >> P >> D;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			int k = cal(i, j);
			cnt[i][k]++;
			cnt[j][k]++;
			p.push_back(node(i, j, k));
		}
	}
	ll ans = 1ll * n * (n - 1) * (n - 2) / 6;
	ll rhs = 0;
	for (int i = 0; i < p.size(); ++i) {
		int u = p[i].u, v = p[i].v, k = p[i].col;
		rhs += cnt[u][k ^ 1] + cnt[v][k ^ 1];
	}
	cout << ans - rhs / 4 << '\n';
}