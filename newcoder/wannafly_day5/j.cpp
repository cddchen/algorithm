#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 5;
bitset<maxn> p[maxn];
int a[maxn][maxn];
char s[maxn][maxn];
int n, k;

void solve(int x, int y) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (s[i][j] == '1')
				a[(x + i) % n][(y + j) % n] = 1;
			else
				a[(x + i) % n][(y + j) % n] = 0;
		}
	}
	bitset<maxn> v; v.reset();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			v[i * n + j] = a[i][j];
		}
	}
	for (int i = 0; i < n * n; ++i) {
		if (v[i] && p[i].count())
			v = v ^ p[i];
		else if (v[i]) {
			p[i] = v;
			break;
		}
	}
}
const ll mod = 1e9 + 7;
ll qpow(ll a, ll b) {
	ll rhs = 1;
	while (b) {
		if (b & 1)
			rhs = rhs * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return rhs;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int k; cin >> k; int n = 1 << k;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			solve(i, j);

	ll ans = 0;
	for (int i = 0; i < n * n; ++i)
		if (p[i][i])
			ans++;

	ans = qpow(2, ans);
	cout << ans << '\n';
}