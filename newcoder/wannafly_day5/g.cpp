#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
stack<pair<int, int>> ans, ans_;
int inv[maxn], mod;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t; inv[0] = inv[1] = 1;
	while (t--) {
		while (ans.size()) ans.pop();
		cin >> mod;
		if (mod == 3) {
			cout << "1\n2 2" << '\n';
			continue;
		}
		int limit = 1e9;
		for (int i = 2; i < mod; ++i) {
			if (i >= limit)
				break;
			inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
			limit = min(limit, inv[i]);
			if (!ans.size())
				ans.push(make_pair(inv[i], i));
			else if (ans.top().first > inv[i])
				ans.push(make_pair(inv[i], i));

			if (!ans_.size())
				ans_.push(make_pair(i, inv[i]));
			else if (ans_.top().second > inv[i])
				ans_.push(make_pair(i, inv[i]));
		}

		cout << ans_.size() + ans.size() << '\n';
		while (ans_.size()) ans.push(ans_.top()), ans_.pop();
		while (ans.size()) {
			cout << ans.top().first << ' ' << ans.top().second << '\n';
			ans.pop();
		}
	}
}