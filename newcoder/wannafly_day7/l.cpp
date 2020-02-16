#include <bits/stdc++.h>
using namespace std;
const int maxn = 20 + 2;
const int maxm = 1 << maxn;
typedef long long ll;

int g[maxn], vis[maxm], b[maxm], cnt;
int c0[maxm][maxn], c1[maxm][maxn];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m, q; cin >> n >> m >> q;
    int s = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        s |= x << i;
    }
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v; u--, v--;
        g[v] |= 1 << u;
    }
    memset(vis, -1, sizeof(vis));
    vis[s] = 0; b[0] = s;
    int st, loop;
    while (true)
    {
        int ns = 0;
        for (int i = 0; i < n; ++i) {
            ns |= (__builtin_parity(g[i] & s) << i);
        }
        b[++cnt] = s = ns;
        if (~vis[s]) {
            st = vis[s];
            loop = cnt - st;
            break;
        }
        vis[s] = cnt;
    }

    for (int i = 0; i <= st; ++i)
        for (int j = 0; j < n; ++j)
            c0[i][j] = (b[i] >> j & 1);
    for (int i = 1; i <= st; ++i)
        for (int j = 0; j < n; ++j)
            c0[i][j] += c0[i - 1][j];
    for (int i = 1; i <= loop; ++i)
        for (int j = 0; j < n; ++j)
            c1[i][j] = c1[i - 1][j] + (b[i + st] >> j & 1);
    
    int x; ll l, r, mid, k;
    while (q--) {
        cin >> x >> k; x--;
        if (k <= c0[st][x]) {
            //cout << "case 1" << endl;
            l = 0, r = st;
            while (l != r) {
                mid = (l + r) >> 1;
                if (c0[mid][x] < k)
                    l = mid + 1;
                else
                    r = mid;
            }
            cout << l << endl;
        }
        else {
            //cout << "case 2 " << st << endl;
            k -= c0[st][x];
            ll ans = st;
            if (c1[loop][x] == 0)
                cout << -1 << endl;
            else {
                if (k >= c1[loop][x]) {
                    if (k % c1[loop][x]) {
                        ans += k / c1[loop][x] * loop;
                        k %= c1[loop][x];
                    }
                    else {
                        ans += (k / c1[loop][x] - 1) * loop;
                        k = c1[loop][x];
                    }
                }
                l = 1, r = loop;
                while (l != r) {
                    mid = (l + r) >> 1;
                    if (c1[mid][x] < k)
                        l = mid + 1;
                    else
                        r = mid;
                }
                cout << ans + l << endl;
            }
        }
    }
}