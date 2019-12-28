#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
typedef double db;
typedef long long ll;
const int maxn = 300005 + 5;
namespace Poly {
const db pi = acos(-1.0);
class Complex {
public:
    db a, b;
    Complex(db _a = 0, db _b = 0) : a(_a), b(_b) {}
    Complex operator+(const Complex &o) const { return Complex(a + o.a, b + o.b); }
    Complex operator-(const Complex &o) const { return Complex(a - o.a, b - o.b); }
    Complex operator*(const Complex &o) const { return Complex(a * o.a - b * o.b, a * o.b + b * o.a); }
} A[maxn], B[maxn];
void fft(Complex *x, int sz, int tp) {
    for (int i = sz >> 1, j = 1; j < sz; j++) {
        if (i < j)
            swap(x[i], x[j]);
        int k;
        for (k = sz >> 1; i & k; i ^= k, k >>= 1)
            ;
        i ^= k;
    }
    for (int m = 2; m <= sz; m <<= 1) {
        Complex w(cos(2.0 * pi * tp / m), sin(2.0 * pi * tp / m));
        for (int i = 0; i < sz; i += m) {
            Complex cur(1.0, 0.0);
            for (int j = i; j < i + (m >> 1); j++) {
                Complex u = x[j], v = x[j + (m >> 1)] * cur;
                x[j] = u + v;
                x[j + (m >> 1)] = u - v;
                cur = cur * w;
            }
        }
    }
}
void fft_mul(int *a, int lena, int *b, int lenb) {
    int sz = 1;
    for (; sz < lena + lenb; sz <<= 1)
        ;
    for (int i = 0; i < sz; ++i) {
        if (i < lena)
            A[i] = Complex(a[i], 0.0);
        else
            A[i] = Complex();
        if (i < lenb)
            B[i] = Complex(b[i], 0.0);
        else
            B[i] = Complex();
    }
    fft(A, sz, 1);
    fft(B, sz, 1);
    for (int i = 0; i < sz; ++i) A[i] = A[i] * B[i];
    fft(A, sz, -1);
    for (int i = 0; i < lena + lenb; ++i) a[i] = int(A[i].a / db(sz) + 0.5);
}
}
int x[maxn], y[maxn];
int main()
{
	//freopen("gift15.in", "in", stdin);
	int n, m; scanf("%d%d", &n, &m);
	int sum_a = 0, sum_b = 0, sum_sqr = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x[i]);
		sum_a += x[i];
		sum_sqr += x[i] * x[i];
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &y[i]);
		sum_b += y[i];
		sum_sqr += y[i] * y[i];
	}
	reverse(y, y + n);
	for (int i = 0; i < n; ++i) y[n + i] = y[i];
	Poly::fft_mul(x, n, y, 2 * n);
	int mx = 0;
	for (int i = 0; i < n; ++i) mx = max(mx, x[2 * n - i - 1]);
	int ans = 0x7fffffff;
	for (int k = -100; k <= 100; ++k) {
		int tmp = n * k * k + sum_sqr + 2 * k * sum_b - 2 * k * sum_a - 2 * mx;
		ans = min(ans, tmp);
	}
	printf("%d\n", ans);
}