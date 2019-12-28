#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 4;
vector< pair<int, int> > e[maxn];
int dp[maxn][2], nxt[maxn][2];
//0->max 1->second max
void dfs(int u, int pre) {
    for(auto& x : e[u]) {
        int v = x.first, w = x.second;
        if(v == pre) continue;
        dfs(v, u);
        if(dp[v][0] + w > dp[u][0]) {
            dp[u][1] = dp[u][0];
            nxt[u][1] = nxt[u][0];
            dp[u][0] = dp[v][0] + w;
            nxt[u][0] = v;
        }
        else if(dp[v][0] + w > dp[u][1]) {
            dp[u][1] = dp[v][0] + w;
            nxt[u][1] = v;
        }
    }
}
void dfs2(int u, int pre, int len) {
    if(u != 1) {
        if(nxt[pre][0] == u) {
            if(dp[u][0] < dp[pre][1] + len) {
                dp[u][1] = dp[u][0];
                nxt[u][1] = nxt[u][0];
                dp[u][0] = dp[pre][1] + len;
                nxt[u][0] = pre;
            }
            else if(dp[u][1] < dp[pre][1] + len) {
                dp[u][1] = dp[pre][1] + len;
                nxt[u][1] = pre;
            }
        }
        else {
            if(dp[u][0] < dp[pre][0] + len) {
                dp[u][1] = dp[u][0];
                nxt[u][1] = nxt[u][0];
                dp[u][0] = dp[pre][0] + len;
                nxt[u][0] = pre;
            }
            else if(dp[u][1] < dp[pre][0] + len) {
                dp[u][1] = dp[pre][0] + len;
                nxt[u][1] = pre;
            }
        }
    }
    for(auto& x : e[u]) {
        int v = x.first, w = x.second;
        if(v == pre) continue;
        dfs2(v, u, w);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n) {
        for(int i = 1; i <= n; i++) e[i].clear(), dp[i][0] = dp[i][1] = nxt[i][0] = nxt[i][1] = 0;
        for(int i = 2; i <= n; i++) {
            int p, x;
            cin >> p >> x;
            e[p].emplace_back(make_pair(i, x));
            e[i].emplace_back(make_pair(p, x));
        }
        dfs(1, 0);
        dfs2(1, 0, 0);
        for(int i = 1; i <= n; i++)
            printf("%d\n", max(dp[i][0], dp[i][1]));
    }
}

