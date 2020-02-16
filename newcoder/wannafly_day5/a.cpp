#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> a[3];
int vis[maxn];
int flg[maxn][3];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k; cin >> n >> k;
	for (int i = 0; i < k; ++i) {
		int x; cin >> x;
		for (int j = 0; j < x; ++j) {
			int y; cin >> y;
			a[i].push_back(y);
		}
	}
	if (k == 1)
		cout << (a[0].size() == 0 ? 1 : a[0].size()) << '\n';
	else if (k == 2) {
		int rhs = max(a[0].size(), a[1].size());
		cout << (rhs == 0 ? 1 : rhs) << '\n';
	}
	else if (k == 3) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < a[i].size(); ++j) {
				flg[a[i][j]][i] = 1;
			}
		}
		int cnt01 = 0, cnt12 = 0, cnt02 = 0, cnt123 = 0;
		int cnt0 = 0, cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= n; ++i) {
			if (flg[i][0] == 0 && flg[i][1] == 0 && flg[i][2] == 0)
				continue;
			if (flg[i][0] == 1 && flg[i][1] == 1 && flg[i][2] == 1)
				cnt123++;
			else if (flg[i][0] == 1 && flg[i][1] == 1)
				cnt01++;
			else if (flg[i][1] == 1 && flg[i][2] == 1)
				cnt12++;
			else if (flg[i][0] == 1 && flg[i][2] == 1)
				cnt02++;
			else if (flg[i][0] == 1)
				cnt0++;
			else if (flg[i][1] == 1)
				cnt1++;
			else if (flg[i][2] == 1)
				cnt2++;
		}
		cnt2 = cnt2 >= cnt01 ? cnt2 - cnt01 : 0;
		cnt0 = cnt0 >= cnt12 ? cnt0 - cnt12 : 0;
		cnt1 = cnt1 >= cnt02 ? cnt1 - cnt02 : 0;
		
		cout << cnt123 + cnt01 + cnt02 + cnt12 + max(cnt0, max(cnt1, cnt2)) << '\n';
	}
}