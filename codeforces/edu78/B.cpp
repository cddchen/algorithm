#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
int pre[maxn], p;
int main()
{
	pre[0] = 0, pre[1] = 1; p = 2;
	for (int i = 2; ; ++i) {
		if (1ll * pre[i - 1] + 1ll * i > 1e9)
			break;
		pre[p++] = pre[i - 1] + i;
	}
	pre[p++] = inf;
	int t; cin >> t;
	while (t--) {
		ll a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		ll gp = b - a; ll ans = inf;
		for (int i = 0; i < p; ++i) {
			ans = min(ans, abs(pre[i] - gp) * 2 + i);
		}
		cout << ans << endl;
	}
}