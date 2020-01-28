#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 5;
namespace BitTree {
	int cnt[maxn << 1];
	int lowbit(int x) {
		return x & -x;
	}
	void updata(int pos, int tot, int val) {
		for (int i = pos; i <= tot; i += lowbit(i)) {
			cnt[i] += val;
		}
	}
	int sum(int pos) {
		int rhs = 0;
		while (pos) {
			rhs += cnt[pos];
			pos -= lowbit(pos);
		}
		return rhs;
	}
	int query(int l, int r) {
		if (l > r)
			return 0;
		return sum(r) - sum(l - 1);
	}
}
int pos[maxn][2];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<int> v(n + m + 5);
	for (int i = 1; i <= n; ++i) 
		v[i] = n - i + 1;
	for (int i = 1; i <= m; ++i) 
		cin >> v[i + n];
	vector<int> sign(n + m + 5);
	for (int i = 1; i <= n; ++i)
		pos[i][0] = pos[i][1] = i;
	for (int i = 1; i <= n + m; ++i) {
		if (sign[v[i]] == 0) {
			sign[v[i]] = i;
			BitTree::updata(i, n + m, 1);
		}
		else {
			int rhs = BitTree::query(sign[v[i]] + 1, i - 1) + 1;
			pos[v[i]][0] = 1;
			pos[v[i]][1] = max(pos[v[i]][1], rhs);
			BitTree::updata(sign[v[i]], n + m, -1);
			BitTree::updata(i, n + m, 1);
			sign[v[i]] = i;
		}
	}

	for (int i = 1; i <= n; ++i)
		pos[i][1] = max(pos[i][1], BitTree::query(sign[i] + 1, n + m) + 1);
	for (int i = 1; i <= n; ++i)
		cout << pos[i][0] << " " << pos[i][1] << '\n';
}