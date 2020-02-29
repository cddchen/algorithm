#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 45000 + 5;
int qpow(ll a, ll b, int mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int mod; scanf("%d", &mod);
        int n; scanf("%d", &n);
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            ll a, b; scanf("%lld%lld", &a, &b);
            sum += qpow(a, b, mod);
            sum %= mod;
        }
        printf("%lld\n", sum);
    }
}