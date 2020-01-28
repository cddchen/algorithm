#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
const ll inf = 1e18;
struct Aho
{
	int ch[maxn][26], fail[maxn], val[maxn], cnt[maxn], len[maxn], tot = 0;
	void insert(char* s, int value) {
		int u = 0;
		for (int i = 0; s[i]; ++i) {
			int id = s[i] - 'a';
			if (!ch[u][id])
				ch[u][id] = ++tot;
			u = ch[u][id];
			len[u] = i + 1;
		}
		val[u] = val[u] == 0 ? value : min(val[u], value);
		cnt[u]++;
	}
	void build() {
		queue<int> q;
		for (int i = 0; i < 26; ++i) {
			if (ch[0][i]) {
				fail[ch[0][i]] = 0;
				q.push(ch[0][i]);
			}
		}

		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int i = 0; i < 26; ++i) {
				if (ch[u][i]) {
					fail[ch[u][i]] = ch[fail[u]][i];
					q.push(ch[u][i]);
				}
				else
					ch[u][i] = ch[fail[u]][i];
			}
		}
	}
	int query(char* s) {
		int now = 0, ans = 0;
		for (int i = 0; s[i]; ++i) {
			now = ch[now][s[i] - 'a'];
			for (int j = now; j && cnt[j] != -1; j = fail[j]) {
				ans += cnt[j];
				cnt[j] = -1;
			}
		}
		return ans;
	}
} aho;

char s[maxn];
ll dp[maxn];
int main()
{
	int n, m; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x; scanf("%s%d", s, &x);
		aho.insert(s, x);
	}
	aho.build();
	scanf("%s", s + 1); m = strlen(s + 1);
	for (int i = 1; i <= m; ++i)
		dp[i] = inf;
	for (int i = 1, now = 0; i <= m; ++i) {
		now = aho.ch[now][s[i] - 'a'];
		int u = now;
		while (u) {
			if (aho.cnt[u])
				dp[i] = min(dp[i], dp[i - aho.len[u]] + aho.val[u]);
			u = aho.fail[u];
		}
	}
	if (dp[m] >= inf)
		printf("-1\n");
	else
		printf("%lld\n", dp[m]);
}