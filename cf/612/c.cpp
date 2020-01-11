#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lf tmp_p[i-1]
#define nw tmp_p[i]
#define rt tmp_p[i+1]
const int maxn = 100 + 5;
int n, p[maxn], vis[maxn], tmp_p[maxn];
int cnt[2], Cnt[2];
int ans = 0x3f3f3f3f;
void solve() {
	int tmp = 0;
	for (int i = 1; i <= n; ++i) 
		tmp_p[i] = p[i];
	cnt[0] = Cnt[0]; cnt[1] = Cnt[1];
	for (int i = 2; i <= n - 1; ++i) {
		if (nw == 0 && lf != 0 && rt != 0 && (lf & 1) == (rt & 1)) {
			if (cnt[lf & 1] > 0) {
				nw = lf;
				cnt[nw & 1]--;
			}
			else {
				nw = lf + 1;
				cnt[nw & 1]--;
			}
		}
	}
	for (int i = 2; i <= n; ++i) {
		if (nw == 0) {
			if (i == n || (i + 1 <= n && rt == 0)) {
				if (cnt[lf & 1] > 0) {
					nw = lf; cnt[nw & 1]--;
				}
				else {
					nw = lf + 1; cnt[nw & 1]--; tmp++;
				}
			}
			else if ((lf & 1) == (rt & 1)) {
				if (cnt[lf & 1] > 0) {
					nw = lf;
					cnt[nw & 1]--;
				}
				else {
					nw = lf + 1;
					cnt[nw & 1]--;
					tmp++;
				}
			}
			else {
				nw = lf;
			}
		}
		else if ((nw & 1) != (lf & 1)) {
			tmp++;
		}
	}
	ans = min(ans, tmp);
	/*
	cout << "tmp = " << tmp << endl;
	for (int i = 1; i <= n; ++i) {
		cout << tmp_p[i] << " ";
	}
	cout << endl;
	*/
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p[i]);
		vis[p[i]] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		if (vis[i] == 0) 
			Cnt[i & 1]++;
	}
	if (p[1] == 0) {
		for (int i = 0; i <= 1; ++i) {
			if (Cnt[i] > 0) {
				p[1] = i + 2; Cnt[i]--;
				solve();
				p[1] = 0; Cnt[i]++;
			}
		}
	}
	else 
		solve();
	printf("%d\n", ans == 0x3f3f3f3f ? 0 : ans);
}
