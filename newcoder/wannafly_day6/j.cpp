#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 55;
const int mod = 998244353;
/*
ll c[maxn][maxn];
ll inv[maxn], invf[maxn], f[maxn], fk[maxn][maxn];
void pre() {
    f[0] = f[1] = 1;
    inv[0] = inv[1] = 1;
    invf[0] = invf[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
        f[i] = 1ll * f[i - 1] * i % mod;
        invf[i] = 1ll * invf[i - 1] * inv[i] % mod;
    }
    for (int i = 1; i < maxn; ++i) {
        fk[i][0] = 1;
        for (int j = 1; j < maxn; ++j) {
            fk[i][j] = fk[i][j - 1] * inv[i] % mod;
        }
    }
    for (int i = 1; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            fk[i][j] = 1ll * fk[i][j] * invf[j] % mod;
        }
    }
}
*/

ll c[maxn][maxn], f[maxn], fac[maxn];

int main() {
    //pre();
    fac[0] = 1;
    for (int i = 1; i < maxn; ++i)
        fac[i] = fac[i - 1] * i % mod;
    for (int i = 0; i < maxn; ++i) c[i][0] = 1;
    for (int i = 1; i < maxn; ++i)
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;

    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; ll k; cin >> n >> k;
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                if (k % j) continue;
                f[i] = (f[i] + f[i - j] * c[i - 1][j - 1] % mod * fac[j - 1] % mod) % mod;
            }
        }
        cout << f[n] << endl;
    }
}