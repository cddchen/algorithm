#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;
const double PI = acos(-1);
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while (c < '0' || c > '9') {if (c == '-')f = -1; c = getchar();}
    while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
    return x * f;
}
struct Complex {
    double r, i;
    Complex() {}
    Complex(double r, double i) : r(r), i(i) {}
    inline void real(const double& x) { r = x; }
    inline double real() { return r; }
    inline Complex operator +(const Complex& rhs) const {
        return Complex(r + rhs.r, i + rhs.i);
    }
    inline Complex operator -(const Complex& rhs) const {
        return Complex(r - rhs.r, i - rhs.i);
    }
    inline Complex operator *(const Complex& rhs) const {
        return Complex(r * rhs.r - i * rhs.i, r * rhs.i + i * rhs.r);
    }
    inline void operator /=(const double& x) {
        r /= x; i /= x;
    }
    inline void operator *=(const Complex& rhs) {
        *this = Complex(r * rhs.r - i * rhs.i, r * rhs.i + i * rhs.r);
    }
    inline void operator +=(const Complex& rhs) {
        r += rhs.r, i += rhs.i;
    }
    inline Complex conj() {
        return Complex(r, -i);
    }
};
struct FFT {
    Complex omega[maxn], omegaInverse[maxn];

    void init(const int& n) {
        for (int i = 0; i < n; ++i) {
            omega[i] = Complex(cos(2 * PI / n * i), sin(2 * PI / n * i));
            omegaInverse[i] = omega[i].conj();
        }
    }

    void transform(Complex* a, const int& n, const Complex* omega) {
        for (int i = 0, j = 0; i < n; ++i) {
            if (i > j) swap(a[i], a[j]);
            for (int l = n >> 1; (j ^= l) < l; l >>= 1);
        }

        for (int l = 2; l <= n; l <<= 1) {
            int m = l / 2;
            for (Complex* p = a; p != a + n; p += l) {
                for (int i = 0; i < m; ++i) {
                    Complex t = omega[n / l * i] * p[m + i];
                    p[m + i] = p[i] - t;
                    p[i] += t;
                }
            }
        }
    }

    void dft(Complex* a, const int& n) {
        transform(a, n, omega);
    }

    void idft(Complex* a, const int& n) {
        transform(a, n, omegaInverse);
        for (int i = 0; i < n; ++i)
            a[i] /= 1.0 * n;
    }
} fft;
int n, m;
Complex a[maxn], b[maxn], c[maxn];
int main()
{
    scanf("%d%d", &n, &m);
    int lim;
    for (lim = 1; lim <= n + m; lim <<= 1);

    for (int i = 0; i <= n; ++i) {
        a[i].r = read(); a[i].i = 0;
    }
    for (int i = 0; i <= m; ++i) {
        b[i].r = read(); b[i].i = 0;
    }
    fft.init(lim);
    fft.dft(a, lim);
    fft.dft(b, lim);
    for (int i = 0; i <= lim; ++i) {
        c[i] = a[i] * b[i];
    }
    fft.idft(c, lim);
    for (int i = 0; i <= n + m; ++i) {
        printf("%d ", int(c[i].real() + 0.5));
    }
    printf("\n");
}