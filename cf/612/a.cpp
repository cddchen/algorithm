#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
char str[maxn];
int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d%s", &n, &str);
		int ans = 0, mx = 0, flg = false;
		for (int i = 0; i < n; ++i) {
			if (str[i] == 'A') {
				flg = true;
				ans = max(ans, mx);
				mx = 0;
			}
			else if (flg) 
				mx++;
		}
		printf("%d\n", max(ans, mx));
	}
}