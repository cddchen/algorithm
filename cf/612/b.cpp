#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1500 + 5;
map<ll, int> cnt;
char str[maxn][35];
ll fib[35], in[maxn];
inline int cal(int i, int j) {
	if (str[i][j] == 'S')
		return 0;
	else if (str[i][j] == 'E')
		return 1;
	else
		return 2;
}
int main()
{
	//freopen("in", "r", stdin);
	fib[0] = 1;
	for (int i = 1; i <= 30; ++i)
		fib[i] = fib[i - 1] * 3;
	int n, K;
	while (~scanf("%d%d", &n, &K)) {
		cnt.clear();
		for (int i = 0; i < n; ++i) {
			in[i] = 0; scanf("%s", &str[i]);
			for (int j = 0; j < K; ++j) {
				in[i] += fib[j] * cal(i, j);
			}
			cnt[in[i]]++;
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			cnt[in[i]]--;
			for (int j = i + 1; j < n; ++j) {
				cnt[in[j]]--;
				ll tmp = 0;
				for (int k = 0; k < K; ++k) {
					if (str[i][k] == str[j][k]) 
						tmp += fib[k] * cal(i, k);
					else {
						int vis[3] = {0};
						vis[cal(i, k)] = vis[cal(j, k)] = 1;
						if (vis[1] == 0)
							tmp += fib[k];
						else if (vis[2] == 0)
							tmp += fib[k] * 2;
					}
				}
				ans += cnt[tmp];
				cnt[in[j]]++;
			}
			cnt[in[i]]++;
		}

		printf("%d\n", ans / 3);
	}
}