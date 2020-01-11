#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2000 + 5;
vector<int> e[maxn];
int c[maxn], sz[maxn];
int arr[maxn], p;
bool flg = true;
void dfs(int u) {
	if (!flg) return;
	int l = p, r;
	for (int v : e[u]) 
		dfs(v);
	r = p; p++;
	if (r - l < c[u]) {
		flg = false;
		return;
	}
	for (int i = r; i > l + c[u]; --i) 
		arr[i] = arr[i - 1];
	arr[l + c[u]] = u;
}
int rk[maxn];
int main()
{
 	int n; scanf("%d", &n);
	int root;
	for (int i = 1, fa; i <= n; ++i) {
		scanf("%d%d", &fa, &c[i]);
		if (fa == 0)
			root = i;
		else 
			e[fa].push_back(i);
	}
	dfs(root);
	if (!flg) {
		printf("NO\n");
		return 0;
	}
	for (int i = 0; i < p; ++i) {
		rk[arr[i]] = i + 1;
	}
	printf("YES\n");
	for (int i = 1; i <= n; ++i) 
		printf("%d ", rk[i]);
}