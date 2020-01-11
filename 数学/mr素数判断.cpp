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
ll mod_exp(ll a, ll b, ll c) {
	ll rhs = 1;
	while (b) {
		if (b & 1)
			rhs = rhs * a % c;
		b >>= 1;
		a = a * a % c;
	}
	return rhs;
}

bool Miller_Rabin(ll n, int respat) {
	if (n == 2ll || n == 3ll || n == 5ll || n == 7ll || n == 11ll)
		return true;
	if (n == 1 || !(n % 2) || !(n % 3) || !(n % 5) || !(n % 7) || !(n % 11))
		return false;

	int k = 0;
	ll d = n - 1;
	while (!(d & 1ll)) {
		k++; d >>= 1ll;
	}
	srand((ll)time(0));
	for (int i = 0; i < respat; ++i) {
		ll a = rand() % (n - 2) + 2;
		ll x = mod_exp(a, d, n);
		ll y = 0ll;
		//二次探测，利用x^2≡1(modn)时只有x=1或x=n-1两个解
		for (int j = 0; j < k; ++j) {
			y = mod_mul(x, x, n);
			if (1ll == y && 1ll != x && n - 1ll != x)
				return false;
			x = y;
		}
		if (1ll != y)
			return false;
	}
	return true;
}

int main() {
	ll x; scanf("%lld", &x);
	if (Miller_Rabin(x, 6))
		printf("Yes\n");
	else
		printf("No\n");
}