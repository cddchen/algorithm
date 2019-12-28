#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
map<int, int> vis;

int main()
{
	 int t; scanf("%d", &t);
	 while (t--) {
	 	int n; scanf("%d", &n);
	 	int base = 0; vis.clear();
	 	for (int i = 1; i <= n; ++i) {
	 		scanf("%d", &a[i]);
	 		if (a[i] == 1)
	 			base++;
	 		else
	 			base--;
	 		vis[base] = i;
	 	}
	 	base = 0;
	 	int ans = 0;
	 	if (vis.count(0) > 0)
	 		ans = vis[0];
	 	for (int i = 1; i <= n; ++i) {
	 		scanf("%d", &a[i]);
	 	}
	 	for (int i = n; i >= 1; --i) {
	 		if (a[i] == 1)
	 			base--;
	 		else 
	 			base++;
	 		if (base == 0 && vis.count(0) == 0)
	 			ans = max(ans, n - i + 1);
	 		if (vis.count(base) > 0)
	 			ans = max(ans, vis[base] + n - i + 1);
	 	}
	 	printf("%d\n", n + n - ans);
	 }
}