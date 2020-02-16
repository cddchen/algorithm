#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int n, m;
void solve() {
	//质因子分解
	map<int, int> primes = primes_factor(n);
	//约数
	vector<int> divs = divsor(n);
	ll res = 0;
	for (int i = 0; i < divs.size(); ++i) {
		ll euler = divs[i];
		for (auto it = primes.begin(); it != primes.end(); ++it) {
			int p = it->first;
			if (divs[i] % p == 0) euler = euler / p * (p - 1);
		}

		res += euler * mod_pow(m, n / divs[i]) % mod;
		res %= mod;
	}

	printf("%lld\n", res * mod_pow(n, mod - 2) % mod);
}