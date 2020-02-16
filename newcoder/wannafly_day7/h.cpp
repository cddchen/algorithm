#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5000 + 5;
vector<int> prime;
int vis[maxn], phi[maxn];
typedef long long ll;
void get() {
	phi[1] = 1;
	for (int i = 2; i < maxn; ++i) {
		if (!vis[i]) {
			prime.push_back(i);
			phi[i] = i - 1;
		}
		for (int j = 0; j < prime.size() && i * prime[j] < maxn; ++j) {
			if (i % prime[j] == 0) {
				vis[i * prime[j]] = 1;
				phi[i * prime[j]] = phi[i] * prime[j];
			}
			else {
				vis[i * prime[j]] = 1;
				phi[i * prime[j]] = phi[i] * (prime[j] - 1);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	get();
	int n; cin >> n;
	if (n == 1) {
		cout << "0/1" << endl;
		return 0;
	}
	ll ans = 0, rot = 0;
	for (int i = 2; i <= n; ++i)
		ans += phi[i];
	rot = 1ll * n * (n - 1);
	ans *= 2ll * (n / 2);
	ll gcd = __gcd(ans, rot);
	cout << ans	/ gcd << '/' << rot / gcd << endl;
}