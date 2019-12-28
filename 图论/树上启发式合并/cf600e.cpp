#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int n, c[maxn];
vector<int> e[maxn];
int fa[maxn], sz[maxn], son[maxn];
void dfs(int u, int f) {
    fa[u] = f; sz[u] = 1;
    for (int i = 0; i < e[u].size(); ++i) {
        int v = e[u][i];
        if (v == f) continue;
        dfs(v, u);
        sz[u] += sz[v];
        if (!son[u] || sz[son[u]] < sz[v]) 
            son[u] = v;
    }
}
int cnt[maxn], top;
ll sum[maxn], ans[maxn];
void Add(int u, int add) {
    sum[cnt[c[u]]] -= 1ll * c[u];
    cnt[c[u]] += add;
    sum[cnt[c[u]]] += 1ll * c[u];
    if (sum[top + 1]) 
        top++;
    if (!sum[top])
        top--;

    for (int i = 0; i < e[u].size(); ++i) {
        int v = e[u][i]; if (v == fa[u]) continue;
        Add(v, add);
    }
}
void solve(int u, int keep) {
    for (int i = 0; i < e[u].size(); ++i) {
        int v = e[u][i];
        if (v == fa[u] || v == son[u]) continue;
        solve(v, 0);
    }

    if (son[u])
        solve(son[u], 1);
    for (int i = 0; i < e[u].size(); ++i) {
        int v = e[u][i];
        if (v == fa[u] || v == son[u]) continue;
        Add(v, 1);
    }

    sum[cnt[c[u]]] -= 1ll * c[u];
    cnt[c[u]]++;
    sum[cnt[c[u]]] += 1ll * c[u];
    if (sum[top + 1])
        top++;
    if (!sum[top])
        top--;
    ans[u] = sum[top];

    if (!keep)
        Add(u, -1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) 
        scanf("%d", &c[i]);
    for (int i = 1; i < n; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }

    dfs(1, 0);
    solve(1, 1);
    for (int i = 1; i <= n; ++i) {
        printf("%lld ", ans[i]);
    }
}