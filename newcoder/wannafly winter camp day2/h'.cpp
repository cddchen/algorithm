#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 5;
const int maxm = maxn << 1;
ll cal(ll m) {
    if (m == 2)
        return 2;
    ll rhs = m * (m - 1) / 2;
    if (m % 2 == 0)
        rhs += m / 2;
    else
        rhs++;
    return rhs;
}
ll solve(ll n) {
    ll st = 1, ed = 2e9;
    while (st != ed) {
        ll md = (st + ed + 1) >> 1;
        if (cal(md) <= n)
            st = md;
        else
            ed = md - 1;
    }
    return st;
}
vector<int> pr;
int head[maxn], tot = 2;
struct enode {
    int to, nxt, vis;
} e[maxm];
void addedge(int u, int v) {
    e[tot] = {v, head[u], 0};
    head[u] = tot++;
}
void euler(int u) {
    int i = head[u];
    while (i != -1 && e[i].vis)
        i = e[i].nxt;
    if (i != -1)
        head[u] = e[i].nxt;
    for (int i = head[u]; i; i = e[i].nxt) {
        if (e[i].vis)
            continue;
        e[i].vis = e[i ^ 1].vis = 1;
        euler(e[i].to);
    }
    pr.push_back(u);
}
 
int main()
{
    ll n; scanf("%lld", &n);
    ll m; printf("%lld\n", m = solve(n));
    if (n > 2e6)
        return 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = i + 1; j <= m; ++j) {
            addedge(i, j);
            addedge(j, i);
        }
    }
    if (m % 2 == 0) {
        for (int i = 3; i <= m; i += 2) {
            addedge(i, i + 1);
            addedge(i + 1, i);
        }
    }
    euler(1);
    while (pr.size() < n)
        pr.push_back(1);
    for (int i = 0; i < pr.size(); ++i) {
        if (i == 0)
            printf("%d", pr[i]);
        else
            printf(" %d", pr[i]);
    }
    printf("\n");
}