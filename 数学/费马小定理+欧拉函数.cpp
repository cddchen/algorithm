#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	return a % b == 0 ? b : gcd(b, a % b);
}
ll cal(ll x) {
	ll rhs = x;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			rhs -= rhs / i;
			while (x % i == 0)
				x /= i;
		}
	}
	if (x > 1)
		rhs -= rhs / x;
	return rhs;
}
ll mul(ll a, ll b, ll c) {
	ll rhs = 0;
	while (b) {
		if (b & 1)
			rhs = (rhs + a) % c;
		b >>= 1;
		a = (a + a) % c;
	}
	return rhs;
}
ll qpow(ll a, ll b, ll c) {
	ll rhs = 1;
	while (b) {
		if (b & 1)
			rhs = mul(rhs, a, c);
		b >>= 1;
		a = mul(a, a, c);
	}
	return rhs;
}
int main() {
	ll n; 
	for (int cas = 1; ; ++cas) {
		scanf("%lld", &n); if (n == 0) break;
		printf("Case %d: ", cas);
		ll mod = 9 * n / gcd(n, 8);
		ll rhs = cal(mod);
		ll ans = 0x3f3f3f3f3f3f;
		for (ll i = 1; i * i <= rhs; ++i) {
			if (rhs % i == 0) {
				if (qpow(10, i, mod) == 1)
					ans = min(ans, i);
				if (qpow(10, rhs / i, mod) == 1)
					ans = min(ans, rhs / i);
			}
		}
		printf("%lld\n", ans == 0x3f3f3f3f3f3f ? 0 : ans);
	}
}