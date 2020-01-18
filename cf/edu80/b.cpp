#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll qpow(ll a, ll b) {
	ll rhs = 1;
	while (b) {
		if (b & 1)
			rhs = rhs * a;
		b >>= 1;
		a = a * a;
	}
	return rhs;
}
int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		ll a, b; scanf("%lld%lld", &a, &b);
		ll rhs = 0;
		ll digit = 0, tmp = b;
		while (tmp) {
			digit++;
			tmp /= 10;
		}
		rhs += 1ll * a * (digit - 1);
		if (b >= qpow(10ll, digit) - 1)
			rhs += a;
		printf("%lld\n", rhs);
	}
}