#include <bits/stdc++.h>
using namespace std;
const int maxn = 12 + 2;
typedef long long ll;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
struct node {
	ll val; int x, y, k;
	node() {}
	node(ll _val, int _x, int _y, int _k) {
		val = _val;
		x = _x;
		y = _y;
		k = _k;
	}
	bool operator <(const node& rhs) const {
		if (val != rhs.val)
			return val < rhs.val;
		return k > rhs.k;
	}
};
int a[maxn][maxn];
int n, m, s, t; ll k, K; 
ll solve(int x, int y, ll kk) {
	if (kk == K)
		return a[x][y];
	ll rhs = 0; int tmp = a[x][y];
	a[x][y] = 0;
	for (int i = 0; i < 4; ++i) {
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if (xx <= 0 || xx > n)
			continue;
		if (yy <= 0 || yy > m)
			continue;
		rhs = max(rhs, solve(xx, yy, kk + 1));
	}
	a[x][y] = tmp;
	return tmp + rhs;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m >> s >> t >> k;
	K = min(k, 1ll * n * m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];
	}
	
	ll ans = solve(s, t, 1) + K * (K - 1) / 2 + n * m * (k - K);
	cout << ans << endl;
}