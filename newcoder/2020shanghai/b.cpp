#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 5;
char str[maxn];
struct node
{
	int cnt, op[10];
	node() {}
} a[maxn * 10];
int tot;
int newnode() {
	a[++tot].cnt = 0;
	memset(a[tot].op, 0, sizeof(a[tot].op));
	return tot;
}

int main()
{
	int t; scanf("%d", &t);
	for (int cas = 1; cas <= t; ++cas) {
		int n; scanf("%d", &n);
		bool flg = true;
		a[0].cnt = tot = 0; memset(a[0].op, 0, sizeof(a[0].op));
		for (int i = 0; i < n; ++i) {
			scanf("%s", str);
			int m = strlen(str), p = 0;
			bool isall = true;
			for (int j = 0; j < m; ++j) {
				int id = str[j] - '0';
				if (a[p].op[id] == 0) {
					isall = false;
					a[p].op[id] = newnode();
				}
				else if (a[a[p].op[id]].cnt)
					flg = false;
				p = a[p].op[id];
				//cout << "p = " << p << ", cnt = " << a[p].cnt << endl;
			}
			if (a[p].cnt || isall)
				flg = false;
			a[p].cnt++;
		}
		printf("Case #%d: %s\n", cas, flg ? "Yes" : "No");
	}
}