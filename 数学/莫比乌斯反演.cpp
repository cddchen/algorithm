#include <bits/stdc++.h>
using namespace std;
const int mod = 10009;
int mod_pow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}
map<int, int> moebius(int n) {
	map<int, int> res;
	vector<int> primes;

	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			primes.push_back(i);
			while (n % i == 0) n /= i;
		}
	}
	if (n != 1) primes.push_back(n);

	int m = primes.size();
	for (int i = 0; i < (1 << m); ++i) {
		int mu = 1, d = 1;
		for (int j = 0; j < m; ++j) {
			if (i >> j & 1) {
				mu *= -1;
				d *= primes[j];
			}
		}
		res[d] = mu;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;

	int res = 0;
	map<int, int> mu = moebius(n);
	for (auto it = mu.begin(); it != mu.end(); ++it) {
		res += it->second * mod_pow(26, n / it->first);
		res = (res + mod) % mod;
	}
	cout << res << '\n';
}