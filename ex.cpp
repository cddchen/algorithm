#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod_mul(ll a, ll b, ll c) {
	ll rhs = 0;
	while (b) {
		if (b & 1)
			rhs = (rhs + a) % c;
		b >>= 1;
		a = (a + a) % c;
	}
	return rhs;
}
ll mod_pow(ll a, ll b, ll c) {
	ll rhs = 1;
	while (b) {
		if (b & 1)
			rhs = mod_mul(rhs, a, c);
		b >>= 1;
		a = mod_mul(a, a, c);
	}
	return rhs;
}
bool Miller_Rabin(ll n, int cnt) {
	if (n == 2ll || n == 3ll || n == 5ll || n == 7ll || n == 11ll)
		return true;
	if (n == 1 || !(n % 2) || !(n % 3) || !(n % 5) || !(n % 7) || !(n % 11))
		return false;

	int k = 0; ll d = n - 1;
	while (!(d & 1ll)) {
		k++; d >>= 1ll;
	}

	srand((ll)time(0));
	while (cnt--) {
		ll a = rand() % (n - 2) + 2;
		ll x = mod_pow(a, d, n);
		ll x_sqr = 0ll;
		for (int i = 0; i < k; ++i) {
			x_sqr = mod_mul(x, x, n);
			if (x_sqr == 1ll && x != 1ll && x != n - 1ll)
				return false;

			x = x_sqr;
		}
		if (x != 1ll)
			return false;
	}
	return true;
}


int main() {
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		if (Miller_Rabin(n, 5))
			printf("Yes\n");
		else 
			printf("No\n");
	}
}