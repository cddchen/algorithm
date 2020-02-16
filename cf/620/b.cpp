#include <bits/stdc++.h>
using namespace std;
map<string, int> vis;
string ans, tmp, incre = "";
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		reverse(tmp.begin(), tmp.end());
		if (vis.count(tmp) <= 0 || vis[tmp] <= 0) {
			reverse(tmp.begin(), tmp.end());
			vis[tmp]++;
		}
		else {
			ans += tmp;
			vis[tmp]--;
		}
	}
	for (map<string, int>::iterator res = vis.begin(); res != vis.end(); ++res) {
		if (res->second > 0) {
			bool flg = true;
			tmp = res->first;
			for (int i = 0; i < m / 2; ++i) {
				if (tmp[i] != tmp[m - i - 1]) {
					flg = false;
					break;
				}
			}
			if (flg) {
				incre = tmp;
				break;
			}
		}
	}
	cout << ans.size() * 2 + incre.size() << '\n';
	cout << ans + incre; reverse(ans.begin(), ans.end());
	cout << ans << '\n';
}