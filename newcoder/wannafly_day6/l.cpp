#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
int dir[8][2] = {1, 2, 2, 1, 2, -1, 1, -2, -1, -2, -2, -1, -2, 1, -1, 2};
int check_dir[8][2] = {0, 1, 1, 0, 1, 0, 0, -1, 0, -1, -1, 0, -1, 0, 0, 1};

char mp[maxn][maxn];
queue<pair<int, int>> q;
int ans[maxn][maxn];
int main()
{

	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", mp[i] + 1);
		for (int j = 1; j <= m; ++j) {
			ans[i][j] = -1;
			if (mp[i][j] == 'M') {
				ans[i][j] = 0;
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) {
		pair<int, int> p = q.front(); q.pop();
		for (int i = 0; i < 8; ++i) {
			int x = p.first + dir[i][0];
			int y = p.second + dir[i][1];
			if (x < 0 || x > n || y < 0 || y > m) continue;
			if (mp[x][y] != '.') continue;
			if (mp[p.first + check_dir[i][0]][p.second + check_dir[i][1]] == 'X') continue;
			if (ans[x][y] == -1 || ans[x][y] > ans[p.first][p.second] + 1) {
				ans[x][y] = ans[p.first][p.second] + 1;
				q.push(make_pair(x, y));
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (j == m)
				printf("%d\n", ans[i][j]);
			else
				printf("%d ", ans[i][j]);
		}
	}
}