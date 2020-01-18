#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
void solve() {
	ll n, d; scanf("%lld%lld", &n, &d);
	ll pre = -1;
	for (int x = 0; ; ++x) {
		ll rhs = d / (x + 1) + (d % (x + 1) == 0 ? 0 : 1) + x;
		if (rhs <= n) {
			printf("YES\n");
			return;
		}
		if (pre != -1 && rhs > pre) {
			printf("NO\n");
			return;
		}
		pre = rhs;
	}
	printf("NO\n");
	return;
}
int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		solve();
	}
}