#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 5;
int n, a[maxn][maxn];
void solve(int elem1) {
	cout << elem1 << ' ';
	for (int i = 2; i <= n - 1; ++i) {
		cout << a[1][i] - elem1 << ' ';
	}
	cout << a[1][n] - elem1 << '\n';
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	int line1 = 0;
	for (int i = 1; i <= n; ++i) {
		if (i == 1) {
			for (int j = 1; j <= n; ++j) {
				cin >> a[i][j];
				line1 += a[i][j];
			}
		}
		else
			for (int j = 1; j <= n; ++j)
				cin >> a[i][j];
	}
	for (int i = 2; i + 1 <= n; i += 2) {
		line1 -= a[i][i + 1];
	}
	if (n == 2)
		solve(line1 / 2);
	else if (n & 1)
		solve(line1 / (n - 1));
	else
		solve((line1 - a[1][n]) / (n - 2));
}