pair<int, int> ->
void tarjan(int u, int eid) {
	dfn[u] = low[u] = ++dfs_clock;
	int sz = 0;
	for (int i = 0; i < e[u].size(); ++i) {
		int v = e[u][i].first, id = e[u][i].second;
		if (!dfn[v]) {
			sz++;
			tarjan(v, id);
			if (low[v] > dfn[u])
				isc[id] = 1;
			low[u] = min(low[u], low[v]);
		}
		else if (dfn[u] > dfn[v] && id != eid)
			low[u] = min(low[u], dfn[v]);
	}
}
void dfs(int u) {
	vis[u] = 1;
	d[cnt].push_back(u);
	for (int i = 0; i < e[u].size(); ++i) {
		int v = e[u][i].first, id = e[u][i].second;
		if (!isc[id]) 
			if (!vis[v]) 
				dfs(v);
	}
}
int main()
{
	for (int i = 1; i <= n; ++i)
		if (!vis[i])
			dfs(i);
}