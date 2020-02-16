#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5000 + 5;
vector<int> a[105][12];
int ac_cnt[12], peo_vis[12][105];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, W; cin >> n >> m >> W;
	for (int i = 0; i < W; ++i) {
		int x, y, c; cin >> x >> y >> c;
		a[x][y].push_back(c);
		if (c == 1 && peo_vis[y][x] == 0) {
			peo_vis[y][x] = 1;
			ac_cnt[y]++;
		}
	}
	for (int i = 1; i <= n; ++i) {
		bool no_submit_flg = true;
		int this_ac_cnt = 0;
		ll ans = 0;
		for (int j = 1; j <= 10; ++j) {
			if (a[i][j].size())
				no_submit_flg = false;
			bool is_ac = false;
			int longest_noac = 0, tmp = 0;
			for (int k = 0; k < a[i][j].size(); ++k) {
				if (a[i][j][k] == 0)
					tmp++;
				else {
					is_ac = true;
					longest_noac = max(longest_noac, tmp);
					tmp = 0;
				}
			}
			longest_noac = max(longest_noac, tmp);

			this_ac_cnt += is_ac;
			if (!is_ac && ac_cnt[j])
				ans += 20;
			if (!is_ac && ac_cnt[j] >= n / 2)
				ans += 10;
			ans += 1ll * longest_noac * longest_noac;
			if (!is_ac)
				ans += 1ll * longest_noac * longest_noac;
		}

		if (no_submit_flg)
			cout << 998244353 << '\n';
		else if (this_ac_cnt == m)
			cout << 0 << '\n';
		else if (this_ac_cnt == 0)
			cout << 1000000 << '\n';
		else
			cout << ans << '\n';
	}
}