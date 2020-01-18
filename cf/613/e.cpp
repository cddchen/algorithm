#include <bits/stdc++.h>
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
vector<pair<int, int>> a;
int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		a.resize(n);
		for (auto &i : a)
			scanf("%d%d", &i.first, &i.second);
		sort(a.begin(), a.end(), less<pair<int, int>>());
		//r维护前i-1端线段的最后端点，mx维护次后端点
		int r = a[0].second, ans = 0, mx = -inf, cnt = 0, gap = 0;
		for (int i = 1; i < n; ++i) {
			//形成新的线段
			if (a[i].first > r) {
				++gap;
				r = a[i].second;
				mx = -inf;
				ans = max(ans, cnt);
				cnt = 0;
			}
			else if (mx == -inf) {
				mx = min(r, a[i].second);
				r = max(r, a[i].second);
			}
			else {
				if (a[i].first > mx)
					++cnt;
				if (a[i].second >= r) {
					ans = max(ans, cnt);
					cnt = 0;
				}
				mx = max(mx, min(r, a[i].second));
				r = max(r, a[i].second);
			}
		}
		ans = max(ans, cnt);
		ans = ans + gap + 1;
		if (gap + 1 == n)
			ans = n - 1;
		printf("%d\n", ans);
	}
}