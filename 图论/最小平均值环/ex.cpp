#define eps 1e-4
void dfs(int u, double mid) {
	vis[u] = 1;
	for (int i = 0; i < e[u].size(); ++i) {
		int v = e[u][i].first, w = e[u][i].second;
		if (d[u] + w - mid > d[v]) {
			d[v] = d[u] + w - mid;
			if (vis[v] || dfs(v, mid)) {
				vis[v] = 0;
				return 1;
			}
		}
	}
	vis[u] = 0;
	return 0;
}
bool judge(double mid) {
	memset(d, 0, sizeof(d));
	for (int i = 1; i <= n; ++i)
		if (dfs(i, mid)) 
			return 1;
	return 0;
}
int main()
{
	double l = 0, r = 1000;
	while (r - l >= eps) {
		double mid = (l + r) / 2;
		if (judge(mid))
			l = mid;
		else
			r = mid;
	}
	printf("%.2f\n", l);
}