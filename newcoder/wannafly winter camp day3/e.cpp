#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 500 + 5;
int n, m;
char a[maxn][maxn];
bool solve(int st) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == '1') {
				for (int i1 = 1; i1 <= i; ++i1) {
					for (int j1 = 1; j1 <= j; ++j1) {
						a[i1][j1] = '0' + ((a[i1][j1] - '0') ^ 1);
					}
				}
				if (!solve(st ^ 1)) {
					for (int i1 = 1; i1 <= i; ++i1) {
						for (int j1 = 1; j1 <= j; ++j1) {
							a[i1][j1] = '0' + ((a[i1][j1] - '0') ^ 1);
						}
					}
					return true;
				}
				for (int i1 = 1; i1 <= i; ++i1) {
					for (int j1 = 1; j1 <= j; ++j1) {
						a[i1][j1] = '0' + ((a[i1][j1] - '0') ^ 1);
					}
				}
			}
		}
	}
	return false;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%s", a[i] + 1);
		}
		cout << (a[1][1] == '1' ? "call" : "aoligei") << '\n';
	}
}