#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
int powmod(int a, int b, int p) {
	int res = 1;
	while (b) {
		if (b & 1)
			res = res * a % p;
		b >>= 1;
		a = a * a % p;
	}
	return res;
}
//找原根
int generator(int p) {
	vector<int> fact;
	int phi = p - 1, n = phi;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			fact.push_back(i);
			while (n % i == 0)
				n /= i;
		}
	}
	if (n > 1)
		fact.push_back(n);
	for (int res = 2; res <= p; ++res) {
		bool ok = true;
		for (int factor : fact) {
			if (powmod(res, phi / factor, p) == 1) {
				ok = false;
				break;
			}
		}
		if (ok)
			return res;
	}
	return -1;
}