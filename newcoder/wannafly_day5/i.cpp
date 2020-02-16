#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 * 2000 + 5;
typedef long long ll;
#define son1 (rt << 2) - 2
#define son2 (rt << 2) - 1
#define son3 (rt << 2)
#define son4 (rt << 2) | 1
ll val[maxn * 8];
ll a[2005][2005];
inline void pushup(int rt) {
	val[rt] = max(val[son1], max(val[son2], max(val[son3], val[son4])));
}
void build(int rt, int x1, int x2, int y1, int y2) {
	if (x1 > x2 || y1 > y2) return;
	if (x1 == x2 && y1 == y2) {
		val[rt] = a[x1][y1];
		return;
	}
	int midx = (x1 + x2) >> 1, midy = (y1 + y2) >> 1;
	build(son1, x1, midx, y1, midy);
	build(son2, midx + 1, x2, y1, midy);
	build(son3, x1, midx, midy + 1, y2);
	build(son4, midx + 1, x2, midy + 1, y2);
	pushup(rt);
}
ll ans;
void query(int rt, int x1, int x2, int y1, int y2, int X1, int X2, int Y1, int Y2) {
	if (x2 < X1 || x1 > X2)
		return;
	if (y2 < Y1 || y1 > Y2)
		return;
	if (val[rt] <= ans)
		return;
	if (X1 <= x1 && x2 <= X2 && Y1 <= y1 && y2 <= Y2) {
		ans = max(ans, t[rt].mx);
		return;
	}
	query(son1, x1, x2, y1, y2);
	query(son2, x1, x2, y1, y2);
	query(son3, x1, x2, y1, y2);
	query(son4, x1, x2, y1, y2);
}                           
int main()
{
	int n, m, q; scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < m; ++i) {
		int x1, x2, y1, y2, w; scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &w);
		a[x1][y1] += w;
		a[x2 + 1][y1] -= w;
		a[x1][y2 + 1] -= w;
		a[x2 + 1][y2 + 1] += w;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
	build(1, 1, n, 1, n);
	for (int i = 0; i < q; ++i) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2); ans = 0;
		query(1, x1, x2, y1, y2);
		printf("%lld\n", ans);
	}
}