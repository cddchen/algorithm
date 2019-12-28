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
#include <set>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
struct node {
	int val, rnk, lc, rc, sz, lzy;
} tre[maxn];
int tot, seed = 233, root = 0;
inline int rrand() {
	return seed = int(seed * 482711ll % 2147483647);
}
inline void update(int rt) {
	tre[rt].sz = tre[tre[rt].lc].sz + tre[tre[rt].rc].sz + 1;
}
int add_node(int val) {
	tre[++tot].sz = 1;
	tre[tot].val = val;
	tre[tot].lc = tre[tot].rc = 0;
	tre[tot].rnk = rrand();
	tre[tot].lzy = 0;
	return tot;
}
void pushdown(int rt) {
	if (tre[rt].lzy == 0) return;
	tre[tre[rt].lc].val += tre[rt].lzy;
	tre[tre[rt].rc].val += tre[rt].lzy;
	tre[tre[rt].lc].lzy += tre[rt].lzy;
	tre[tre[rt].rc].lzy += tre[rt].lzy;
	tre[rt].lzy = 0;
}
void splitV(int rt, int &a, int &b, int val) {
	if (rt == 0) {
		a = b = 0;
		return;
	}
	pushdown(rt);
	if (tre[rt].val <= val) {
		a = rt;
		splitV(tre[rt].rc, tre[a].rc, b, val);
	}
	else {
		b = rt;
		splitV(tre[rt].lc, a, tre[b].lc, val);
	}
	update(rt);
}
void splitK(int rt, int &a, int &b, int k) {
	if (rt == 0) {
		a = b = 0;
		return;
	}
	pushdown(rt);
	int sz = tre[tre[rt].lc].sz;
	if (sz < k) {
		a = rt;
		splitK(tre[rt].rc, tre[rt].rc, b, k - sz - 1);
	}
	else {
		b = rt;
		splitK(tre[rt].lc, a, tre[rt].lc, k);
	}
	update(rt);
}
int get_kth(int rt, int k) {
	while (tre[tre[rt].lc].sz + 1 != k) {
        pushdown(rt);
		if (tre[tre[rt].lc].sz >= k)
			rt = tre[rt].lc;
		else {
			k -= tre[tre[rt].lc].sz + 1;
			rt = tre[rt].rc;
		}
	}
	return tre[rt].val;
}
void merge(int &rt, int a, int b) {
	if (a == 0 || b == 0) {
		rt = a + b;
		return;
	}
    pushdown(rt);
	if (tre[a].rnk < tre[b].rnk) {
		rt = a;
		merge(tre[rt].rc, tre[a].rc, b);
	}
	else {
		rt = b;
		merge(tre[rt].lc, a, tre[b].lc);
	}
	update(rt);
}
int main()
{
	int n, min;
	scanf("%d%d", &n, &min);
	root = add_node(inf);
	int lef = 0;
	for (int i = 0; i < n; ++i) {
		char str[5]; int x; scanf("%s%d", &str, &x);
		if (str[0] == 'I') {
            if (x < min) continue;
			int a, b, c = add_node(x);
			splitV(root, a, b, x);
			merge(a, a, c);
			merge(root, a, b);
		}
		else if (str[0] == 'A') {
            tre[root].val += x;
            tre[root].lzy += x;
		}
		else if (str[0] == 'S') {
            tre[root].val -= x;
            tre[root].lzy -= x;
            int a, b;
            splitV(root, a, b, min - 1);
            lef += tre[a].sz; root = b;
		}
		else if (str[0] == 'F') {
            if (x > tre[root].sz - 1) printf("-1\n");
            else printf("%d\n", get_kth(root, tre[root].sz - 1 - x + 1));
		}
	}
	printf("%d\n", lef);
}