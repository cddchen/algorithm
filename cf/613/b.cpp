#include <bits/stdc++.h>
typedef long long ll;
const int maxn = 1e5 + 5;
const ll inf = 1e16;
int a[maxn];
ll val[maxn << 2];
ll mx[maxn << 2];
void build(int rt, int l, int r) {
	if (l == r) {
		mx[rt] = val[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	mx[rt] = std::max(mx[rt << 1], mx[rt << 1 | 1]);
}
ll query(int rt, int l, int r, int L, int R) {
	if (L <= l && r <= R)
		return mx[rt];
	int mid = (l + r) >> 1;
	ll rhs = -inf;
	if (L <= mid)
		rhs = std::max(rhs, query(rt << 1, l, mid, L, R));
	if (mid < R)
		rhs = std::max(rhs, query(rt << 1 | 1, mid + 1, r, L, R));
	return rhs;
}
int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		ll sum = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			sum += a[i];
			val[i] = sum;
		}
		build(1, 1, n);
		bool flg = true;
		for (int i = 1; i <= n && flg; ++i) {
			ll rhs;
			if (i == 1)
				rhs = query(1, 1, n, 1, n - 1);
			else 
				rhs = query(1, 1, n, i, n) - val[i - 1];
			if (rhs >= sum)
				flg = false;
		}
		printf("%s\n", flg ? "YES" : "NO");
	}
}