#include <bits/stdc++.h>
using namespace std;
const int maxn = 50 + 5;
int f[maxn][maxn];
int a[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) {
            int maxx = 0;
            for (int j = i; j >= 1; --j) {
                maxx = max(maxx, a[j]);
                int p = (i - j + 1) / 2;
                for (int k = p; k <= n; ++k)
                    f[i][k] = max(f[i][k], f[j - 1][k - p] + maxx * (i - j + 1));
            }
        }
        for (int i = 1; i <= n; ++i)
            cout << f[n][i] << (i == n ? '\n' : ' ');
    }
}