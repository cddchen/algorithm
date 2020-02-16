#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int phi[maxn], mu[maxn], vis[maxn];
int sum_mu[maxn], sum_phi[maxn];
vector<int> prime;
unordered_map<long long, int> phi_mp;
unordered_map<int, int> mu_mp;
void get(int n) {
	phi[1] = mu[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (!vis[i]) {
			prime.push_back(i);
			phi[i] = i - 1; mu[i] = -1;
		}
		for (int j = 0; j < prime.size() && prime[j] * i <= n; ++j) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];
				mu[i * prime[j]] = 0;
				break;
			}
			else {
				mu[i * prime[j]] = -mu[i];
				phi[i * prime[j]] = phi[i] * (prime[j] - 1);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		sum_mu[i] = sum_mu[i - 1] + mu[i];
		sum_phi[i] = sum_phi[i - 1] + phi[i];
	}
}
int djs_mu(int x) {
	if (x <= 1e6)
		return sum_mu[x];
	if (mu_mp.count(x))
		return mu_mp[x];
	int ans = 1;
	for (int l = 2, r; l >= 0 && l <= x; l = r + 1) {
		r = x / (x / l);
		ans -= (r - l + 1) * djs_mu(x / l);
	}
	return mu_mp[x] = ans;
}
long long djs_phi(long long x) {
	if (x <= 1e6)
		return sum_phi[x];
	if (phi_mp.count(x))
		return phi_mp[x];

	long long ans = x * (x + 1) / 2;
	for (long long l = 2, r; l >= 0 && l <= x; l = r + 1) {
		r = x / (x / l);
		ans -= (r - l + 1) * djs_phi(x / l);
	}
	return phi_mp[x] = ans;
}

int main()
{

}