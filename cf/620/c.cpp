#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 5;
ll t[maxn], l[maxn], h[maxn];
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int q; cin >> q;
	for (int i = 0; i < q; ++i) {
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; ++i)
			cin >> t[i] >> l[i] >> h[i];
		ll L = m, R = m; bool flg = false;
		for(int i = 1; i <= n; i++)
		{
			L = L - (t[i] - t[i - 1]);
			R = R + (t[i] - t[i - 1]);
			if (R < l[i] || L > h[i]) {
				flg = 1;
				break;
			}
			else {
				L = max(L, l[i]);
				R = min(R, h[i]);
			}
		}
		cout << (flg ? "NO" : "YES") << '\n';
	}
	return 0;
 }