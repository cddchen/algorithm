#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 5;
const int maxm = 10 + 5;
const int mod = 1e9 + 7;
int up[maxm][maxn], down[maxm][maxn];
int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		up[1][i] = down[1][i] = 1;
	for (int i = 2; i <= m; ++i) {
		//枚举当前位
		for (int j1 = 1; j1 <= n; ++j1) {
			//枚举原来位
			for (int j2 = 1; j2 <= j1; ++j2) {
				up[i][j1] = (1ll * up[i][j1] + 1ll * up[i - 1][j2]) % mod;
			}
		}
	}
	for (int i = 2; i <= m; ++i) {
		for (int j1 = 1; j1 <= n; ++j1) {
			for (int j2 = j1; j2 <= n; ++j2) {
				down[i][j1] = (1ll * down[i][j1] + 1ll * down[i - 1][j2]) % mod;
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			ans = (ans + 1ll * up[m][i] * down[m][j] % mod) % mod;
		}
	}
	printf("%lld\n", ans);
}