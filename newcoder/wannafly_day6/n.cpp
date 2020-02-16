#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 5;
typedef long long ll;
int a[maxn];

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			ans += 1ll * a[i] * a[j];
		}
	}
	printf("%lld\n", ans);
}