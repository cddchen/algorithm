#include <bits/stdc++.h>
const int maxn = 1e7 + 5;
typedef long long LL;

std::vector<LL> p;
std::vector<int> pri;
int vis[maxn];
void getPri() {
	for (int i = 2; i < maxn; ++i) {
		if (!vis[i])
			pri.push_back(i);
		for (int j = 0; i * pri[j] < maxn && j < pri.size(); ++j) {
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0)
				break;
		}
	}
}
int main() {
	getPri();
	LL x; scanf("%lld", &x);
	LL y = x;
	for (int i = 0; i < pri.size(); ++i) {
		if (x % pri[i] == 0) {
			LL rhs = 1;
			while (x % pri[i] == 0) {
				x /= pri[i];
				rhs *= pri[i];
			}
			p.push_back(rhs);
		}
		if (x == 1)
			break;
	}
	if (x > 1)
		p.push_back(x);
	sort(p.begin(), p.end());
	int sz = (1 << p.size()), len = p.size();
	LL a = -1;
	for (int i = 1; i < sz; ++i) {
		LL rhs = 1;
		for (int j = 0; j < len; ++j) {
			if (i & (1 << j)) {
				rhs *= p[j];
			}
		}
		if (a == -1)
			a = std::max(rhs, y / rhs);
		else
			a = std::min(a, std::max(rhs, y / rhs));
	}
	if (a == -1)
		printf("1 %lld\n", y);
	else
		printf("%lld %lld\n", a, y / a);
}