#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < (n + 1) / 2; ++i) {
		a[i] = 2 * i + 1;
	}
	for (int i = 1, j = 0; j < n / 2; ++j, ++i) {
		a[n - 1 - j] = 2 * i;
	}
	for (int i = 0; i < n; ++i)
		cout << a[i] << ' ';

}