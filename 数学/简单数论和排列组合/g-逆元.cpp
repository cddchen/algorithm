#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 9973;
int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1ll * res * a % mod;
        b >>= 1;
        a = 1ll * a * a % mod;
    }
    return res;
}
int main()
{
    int n = 5;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j )
    }
}