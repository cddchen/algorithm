#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int cnt[maxn << 2], lzy[maxn << 2];
void build() {
	memset(lzy, -1, sizeof(lzy));
}
void pushdown(int rt) {
	if (lzy[rt] == -1) return;
	cnt[rt << 1] = cnt[rt << 1 | 1] = lzy[rt];
	lzy[rt << 1] = lzy[rt << 1 | 1] = lzy[rt];
	lzy[rt] = -1;
}
void update(int rt, int l, int r, int L, int R, int val) {
	if (L <= l && r <= R) {
		cnt[rt] += val;
		return;
	}
	pushdown(rt);
	int mid = (l + r) >> 1;
	if (L <= mid) update(rt << 1, l, mid, L, R, val);
	if (mid < R) update(rt << 1 | 1, mid + 1, r, L, R, val);
	cnt[rt] = cnt[rt << 1] + cnt[rt << 1 | 1];
}
int query(int rt, int l, int r, int L, int R) {
	if (L > R) return 0;
	if (L <= l && r <= R) {
		int res = cnt[rt];
		cnt[rt] = lzy[rt] = 0;
		return res;
	}
	pushdown(rt);
	int mid = (l + r) >> 1, res = 0;
	if (L <= mid) res += query(rt << 1, l, mid, L, R);
	if (mid < R) res += query(rt << 1 | 1, mid + 1, r, L, R);
	cnt[rt] = cnt[rt << 1] + cnt[rt << 1 | 1];
	return res;
}
int query(int rt, int l, int r, int k) {
	if (l == r) return l;
	int mid = (l + r) >> 1;
	pushdown(rt);
	int res;
	if (cnt[rt << 1] >= k) 
		res = query(rt << 1, l, mid, k);
	else 
		res = query(rt << 1 | 1, mid + 1, r, k - cnt[rt << 1]);
	cnt[rt] = cnt[rt << 1] + cnt[rt << 1 | 1];
	return res;
}
int main()
{
	freopen("in.txt", "r", stdin);
	int n, Min; scanf("%d%d", &n, &Min);
	int lef = 0;
	ll add = 0;
	build();
	for (int i = 0; i < n; ++i) {
		char op[5]; int k; scanf("%s%d", op, &k);
		if (op[0] == 'I') {
			if (k >= Min)
				update(1, 0, maxn, k, k, 1);
		}
		else if (op[0] == 'A') {
			add += k;
		}
		else if (op[0] == 'S') {
			if (add <= 0 || add < k) {
				int tmp = query(1, 0, maxn, Min, Min + k - add - 1);
				lef += tmp;
				printf("Lef = %d\n", tmp);
			}
			add = 0;
		}
		else if (op[0] == 'F') {
			if (k > cnt[1]) printf("-1\n");
			else {
				printf("%lld\n", query(1, 0, maxn, cnt[1] - k) + add);
			}
		}
	}
}