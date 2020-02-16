#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 50 + 2;
const ll mod = 2008;
bitset<maxn> p[maxn];
char str[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		cin >> str;
		bitset<maxn> t; t.reset();
		for (int j = 0; j < n; ++j) {
			if (str[j] == 'O')
				t[j] = 1;
			else
				t[j] = 0;
		}
		for (int j = 0; j < n; ++j) {
			if (t[j] && p[j].count())
				t = t ^ p[j];
			else if (t[j]) {
				p[j] = t;
				ans++;
				break;
			}
		}
	}
	
	cout << (1ll << ans) % 2008 << '\n';
}