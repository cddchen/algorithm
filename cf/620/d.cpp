#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
char a[maxn];
int ans[maxn];
int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d%s", &n, a + 1);
		//min
		int cnt = 0, l, r, sum;
		for (int i = 1; i <= n - 1; ++i) {
			if (a[i] == '>')
				cnt++;
		}
		l = cnt, r = n, ans[1] = cnt + 1, sum = 0;
		for (int i = 1; i <= n - 1; ++i) {
			if (a[i] == '>') {
				if (sum) {
					for (int j = i; j >= i - sum + 1; --j)
						ans[j] = r--;
				}
				ans[i + 1] = l--;
				sum = 0;
			}
			else sum++;
		}
		if (sum) {
			for (int i = n; i >= n - sum + 1; --i)
				ans[i] = r--;
		}
		for (int i = 1; i <= n; ++i) {
			printf("%d%c", ans[i], i == n ? '\n' : ' ');
		}
		//max
		ans[1] = cnt + 1, l = cnt, r = cnt + 2, sum = 0;
		for (int i = 1; i <= n - 1; ++i) {
			if (a[i] == '>') {
				if (sum) {
					for (int j = i - sum + 1; j <= i; ++j)
						ans[j] = r++;
				}
				ans[i + 1] = l--;
				sum = 0;
			}
			else sum++;
		}
		if (sum) {
			for (int i = n - sum + 1; i <= n; ++i)
				ans[i] = r++;
		}
		for (int i = 1; i <= n; ++i)
			printf("%d%c", ans[i], i == n ? '\n' : ' ');
	}
}