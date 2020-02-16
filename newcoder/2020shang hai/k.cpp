#include <bits/stdc++.h>
using namespace std;
const int maxn = 16 + 3;
vector< pair<int, int> > E[maxn];
int ans = 0;
void dfs(int u) {
	
}
int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) E[i].clear();
		for (int i = 0; i < m; ++i) {
			int u, v; scanf("%d%d", &u, &v);
			E[u].push_back(make_pair(v, 0));
		}
	}
}