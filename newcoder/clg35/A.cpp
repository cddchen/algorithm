#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
int a[maxn], b[maxn];
bool cmp(int x, int y) {
	return x > y;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) 
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	sort(a, a + n); sort(b, b + n, cmp);
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] >= b[i]) break;
		ans += b[i] - a[i];
	}
	cout << ans << endl;
}