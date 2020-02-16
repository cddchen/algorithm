#include <bits/stdc++.h>
using namespace std;
const int maxn = 300 + 5;
typedef long long ll;
int nxt[maxn][maxn];
int a[maxn], cnt[maxn][maxn], b[5];

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i)
		nxt[n][i] = -1, cnt[n][i] = 0;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 1; j <= n; ++j){
			nxt[i][j] = nxt[i + 1][j];
			cnt[i][j] = cnt[i + 1][j];
		}
		nxt[i][a[i + 1]] = i + 1;
		cnt[i][a[i + 1]]++;
	}
	for (int i = 0; i < 4; ++i)
		cin >> b[i];
	ll ans = 0;
	int i, j, k, l, pos_i, pos_j, pos_k;
	for (i = 1; i <= n; ++i) {
		//cout << "i = " << i << endl;
		pos_i = nxt[0][i];
		while (pos_i != -1) {
			//cout << "pos_i = " << pos_i << endl;
			for (j = (b[0] == b[1] ? i : 1); j <= (b[0] == b[1] ? i : n); ++j) {
				if ((i == j) != (b[0] == b[1]))
					continue;
				pos_j = nxt[pos_i][j];
				while (pos_j != -1) {
					//cout << "pos_j = " << pos_j << endl;
					for (k = (b[1] == b[2] ? j : 1); k <= (b[1] == b[2] ? j : n); ++k) {
						if ((i == k) != (b[0] == b[2]) || (j == k) != (b[1] == b[2]))
							continue;
						pos_k = nxt[pos_j][k];
						while (pos_k != -1) {
							//cout << "pos_k = " << pos_k << endl;
							if (b[3] == b[0]) {
								ans += cnt[pos_k][i];
								//cout << cnt[pos_k][i] << endl;
							}
							else if (b[3] == b[1]) {
								ans += cnt[pos_k][j];
								//cout << cnt[pos_k][j] << endl;
							}
							else if (b[3] == b[2]) {
								ans += cnt[pos_k][k];
								//cout << cnt[pos_k][k] << endl;
							}
							else {
								ans += (n - pos_k) - cnt[pos_k][i] - cnt[pos_k][j] - cnt[pos_k][k];
								if (b[0] == b[1] && b[1] == b[2])
									ans += cnt[pos_k][i] + cnt[pos_k][i];
								else if (b[0] == b[1])
									ans += cnt[pos_k][i];
								else if (b[0] == b[2])
									ans += cnt[pos_k][i];
								else if (b[1] == b[2])
									ans += cnt[pos_k][j];
							}
							pos_k = nxt[pos_k][k];
						}
					}
					pos_j = nxt[pos_j][j];
				}
			}
			pos_i = nxt[pos_i][i];
		}
	}
	cout << ans << '\n';
}