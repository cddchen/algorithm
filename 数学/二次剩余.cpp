#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define random(a,b) (rand()%(b-a+1)+a)
ll quickmod(ll a, ll b, ll c) {
	ll ans = 1;
	while (b) {
		if (b & 1)
			ans = ans * a % c;
		b >>= 1;
		a = a * a % c;
	}
	return ans;
}

ll p, w;
struct QuadraticField
{
	ll x, y;
	QuadraticField operator *(QuadraticField T) {
		QuadraticField rhs;
		rhs.x = (this->x * T.x % p + this->y * T.y % p * w % p) % p;
		rhs.x = (rhs.x + p) % p;
		rhs.y = (this->x * T.y % p + this->y * T.x % p) % p;
		rhs.y = (rhs.y + p) % p;
		return rhs;
	}
	QuadraticField operator ^(ll b) {
		QuadraticField rhs;
		QuadraticField a = *this;
		rhs.x = 1; rhs.y = 0;
		while (b) {
			if (b & 1)
				rhs = rhs * a;
			b >>= 1;
			a = a * a;
		}
		return rhs;
	}
};
ll Legender(ll a) {
	ll rhs = quickmod(a, (p - 1) / 2, p);
	if (rhs + 1 == p)
		return -1;
	else
		return rhs;
}
ll get_w(ll n, ll a) {
	return ((a * a % p - n) % p + p) % p;
}
ll solve(ll n) {
	ll a;
	if (p == 2)
		return n;
	if (Legender(n) == -1)
		return -1;
	srand((unsigned)time(NULL));
	while (true) {
		a = random(0, p - 1);
		w = get_w(n, a);
		if (Legender(w) == -1)
			break;
	}
	QuadraticField ans, rhs;
	rhs.x = a; rhs.y = 1;
	ans = rhs ^ ((p + 1) / 2);
	return ans.x;
}
int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		ll n; scanf("%lld%lld", &n, &p);
		n %= p;
		if (n == 0)
			printf("0\n");
		else {
			ll ans1 = solve(n), ans2;
			if (ans1 == -1)
				printf("Hola!\n");
			else {
				ans2 = p - ans1;
				if (ans1 == ans2)
					printf("%lld\n", ans1);
				else
					printf("%lld %lld\n", min(ans1, ans2), max(ans1, ans2));
			}
		}
	}
}