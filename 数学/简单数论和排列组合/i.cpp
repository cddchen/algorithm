#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1007;
const int maxn = 2000 + 5;
int c[maxn][maxn];
void C_init(int limit) {
    for (int i = 0; i < limit; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
}
int main()
{
    C_init(maxn);
    int t; scanf("%d", &t);
    while (t--) {
        int m, n; scanf("%d%d", &m, &n);
        printf("%d\n", c[n][m]);
    }
}