#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll qmul(ll a, ll b, ll c) {
    ll res = 0;
    while (b) {
        if (b & 1) res = (res + a) % c;
        b >>= 1;
        a = (a + a) % c;
    }
    return res;
}
ll qpow(ll a, ll b, ll c) {
    ll res = 1;
    while (b) {
        if (b & 1) res = qmul(res, a, c);
        b >>= 1;
        a = qmul(a, a, c);
    }
    return res;
}

int main() {
    ll n, p;
    while (~scanf("%lld%lld", &n, &p)) {
        if (n == 1) printf("%lld\n", 1 % p);
        else printf("%lld\n", (qpow(2, n, p) - 2 + p) % p);
    }
}