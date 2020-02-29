#include <bits/stdc++.h>
using namespace std;
const int maxn = 12 + 2;
typedef long long ll;


int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
struct node {
	ll val; int x, y;
	bool operator <(const node& rhs) const {
		return val < rhs.val;
	}
}
int a[maxn][maxn], t[maxn][maxn];
ll dp[maxn * maxn][maxn][maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, s, t; ll k; cin >> n >> m >> s >> t >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];
	}
	
}