#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
const ll mod = 998244353;
ll qpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}
ll a[maxn], b[maxn];
ll p[maxn], q[maxn];
int main()
{
	freopen("in.txt", "r", stdin);
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &p[i]); 
		q[i] = (100 - p[i]) * qpow(100, mod - 2) % mod;
		p[i] = p[i] * qpow(100, mod - 2) % mod;
	}
	for (int i = n; i >= 1; --i) {
		a[i] = (q[i] + p[i] * a[i + 1] % mod) % mod;
		b[i] = p[i] * b[i + 1] % mod + 1;
	}
	printf("%lld\n", b[1] * qpow((1 - a[1] + mod) % mod, mod - 2) % mod);
}