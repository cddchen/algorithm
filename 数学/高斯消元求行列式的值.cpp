#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e2 + 5;
int a[maxn][maxn], n;
ll ans = 1, dv = 1;
ll solve() {
	for (int i = 1, j = 1; i <= n && j <= n; ++i, ++j) {
		int id = i;
		for (int k = i; k <= n; ++k)
			if (a[k][j] != 0) {
				id = k;
				break;
			}
		if (a[id][j] == 0) {
			--i; continue;
		}
		if (id != i) {
			ans *= -1;
			for (int k = j; k <= n; ++k)
				swap(a[id][k], a[i][k]);
		}
		for (int k = i + 1; k <= n; ++k) {
			if (a[k][j] != 0) {
				int tmp1 = __gcd(abs(a[i][j]), abs(a[k][j]));
				int tmp2 = a[i][j] / tmp1;
				tmp1 = a[k][j] / tmp1;
				dv = dv * tmp2 % mod;
				for (int p = j; p <= n; ++p)
					a[k][p] = (a[k][p] * tmp2 - a[i][p] * tmp1) % mod;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		ans = ans * a[i][i] % mod;
	return (ans + qpow(dv, mod - 2) + mod) % mod;
}