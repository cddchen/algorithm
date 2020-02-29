#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <utility>
#include <ctype.h>
using namespace std;
typedef long long ll;
const int maxn = 20 + 3;
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    ll ret = a / gcd(a, b) * b;
    return ret ? ret : -ret;
}
struct fraction {
    ll a, b;
    fraction() {}
    fraction(ll x) { a = x; b = 1; }
    fraction(ll x, ll y) { a = x; b = y; }

    void deal() {
        if (b < 0) b = -b, a = -a;
        ll k = gcd(a, b);
        if (k < 0) k = -k;
        a /= k; b /= k;
    }
    fraction operator +(const fraction& rhs) const {
        fraction ans;
        ans.b = lcm(b, rhs.b);
        ans.a = ans.b / b * a + ans.b / rhs.b * rhs.a;
        ans.deal();
        return ans;
    }
    fraction operator -(const fraction& rhs) const {
        fraction ans;
        ans.b = lcm(b, rhs.b);
        ans.a = ans.b / b * a - ans.b / rhs.b * rhs.a;
        ans.deal();
        return ans;
    }
    fraction operator *(const fraction& rhs) const {
        fraction ans;
        ans.a = a * rhs.a;
        ans.b = b * rhs.b;
        ans.deal();
        return ans;
    }
    fraction operator /(const fraction& rhs) const {
        fraction ans;
        ans.a = a * rhs.b;
        ans.b = b * rhs.a;
        ans.deal();
        return ans;
    }
    void println() {
        printf("%lld/%lld\n", a, b);
    }
};
fraction B[maxn];
ll C[maxn][maxn];
void init() {
    for (int i = 1; i < maxn; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    B[0] = fraction(1);
    for (int i = 1; i <= 20; ++i) {
        B[i] = fraction(0);
        for (int j = 0; j < i; ++j)
            B[i] = B[i] - fraction(C[i + 1][j]) * B[j];
        B[i] = B[i] / fraction(C[i + 1][i]);
    }
}
int n; fraction a[maxn];
int main() {
    init();
    while (~scanf("%d", &n)) {
        ll Lcm = 1;
        for (int i = 0; i <= n; ++i) {
            a[i] = fraction(C[n + 1][i]) * B[i] * fraction(1, n + 1);
            Lcm = lcm(Lcm, a[i].b);
        }
        printf("%lld ", Lcm);
        a[1] = a[1] + fraction(1);
        for (int i = 0; i <= n; ++i)
            printf("%lld ", Lcm / a[i].b * a[i].a);
        puts("0");
    }
}