#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const int P = 998244353;
const int sqr = 116195171;
inline int qpow(int d, ll z)
{
  int ans=1;
  for(; z; z >>= 1, d = 1ll * d * d % P)
    if(z & 1) ans = 1ll * ans * d % P;
  return ans;
}
int r[maxn << 2];
void ntt(int *x, int lim, int opt) {
    register int i, j, k, m, gn, g, tmp;
    for(i = 0; i < lim; i++)
        if(r[i] < i) swap(x[i], x[r[i]]);
    for(m = 2; m <= lim; m <<= 1) {
        k = m >> 1;
        gn = qpow(3, (P - 1) / m);
        for(i = 0; i < lim; i += m) {
            g = 1;
            for(j = 0; j < k; j++, g = 1ll * g * gn % P) {
                tmp = 1ll * x[i + j + k] * g % P;
                x[i + j + k] = (x[i + j] - tmp + P) % P;
                x[i + j] = (x[i + j] + tmp) % P;
            }
        }
    }
    if(opt == -1) {
        reverse(x + 1, x + lim);
        register int inv = qpow(lim, P - 2);
        for(i = 0; i < lim; i++) 
            x[i] = 1ll * x[i] * inv % P;
    }
}
int A[maxn << 2], B[maxn << 2], C[maxn << 2];
int f[1 << 17];
int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		f[x]++;
	}
	int lim = 1 << 18;
	for (int i = 0; i <= 1e5; ++i) {
        A[i] = 1ll * f[i] * qpow(sqr, 1ll * i * i) % P;
        B[i] = qpow(sqr, (-1ll * i * i % (P - 1) + P - 1));
	}
    for(int i = 0; i < lim; i++) r[i] = (i & 1) * (lim >> 1) + (r[i >> 1] >> 1);
    ntt(A, lim, 1); ntt(B, lim, 1);
    for (int i = 0; i < lim; ++i)
        B[i] = 1ll * A[i] * B[i] % P;
    ntt(B, lim, -1);
    ll ans = 0;
    for (int i = 0; i <= 1e5; ++i) {
        ans = (ans + 1ll * f[i] * qpow(sqr, 1ll * i * i) % P * B[i] % P) % P;
    }
    ans = ans * 2 % P;
    for (int i = 0; i <= 1e5; ++i)
        ans = (ans - 1ll * f[i] * f[i] % P * qpow(2, 1ll * i * i) % P + P) % P;
    printf("%lld\n", (ans % P + P) % P);
}
