#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
const int digit = 60 + 2;
vector<ll> v;
int tr[maxn << 1][digit];
int lowbit(int x) {
	return x & -x;
}
9
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	v.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
		add(i, n, v[i]);
	}
	ll xor_val = 0;
	for (int i = 1; i <= n; ++i) {
		xor_val ^= v[i];
		int k = -1;
		for (int j = digit; j >= 0; --j) {
			if ((xor_val >> j) & 1) {
				k = j;
				break;
			}
		}
		if (k == -1)
			cout << 0 << (i == n ? '\n' : ' ');
		else
			cout << sum(i, k) << (i == n ? '\n' : ' ');
	}
}