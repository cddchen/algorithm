#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <ctype.h>
using namespace std;
typedef long long ll;
inline void read(ll &x){
    ll data = 0, w = 1;
    char ch = getchar();
    while(ch != '-' && !isdigit(ch))
        ch = getchar();
    if(ch == '-')
        w = -1, ch = getchar();
    while(isdigit(ch))
        data = 10 * data + ch - '0', ch = getchar();
    x = data * w;
}
void write(ll x){
    if(x < 0)
        putchar('-'), x = -x;
    if(x > 9)
        write(x / 10);
    putchar('0' + x % 10);
}

int main()
{
    ll n, m;
    while (~scanf("%lld%lld", &n, &m)) {
        if (n == 0 && m == 0) break;
        if (n > m) swap(n, m);
        double den = 1, mol = 1;
        for (ll i = m + 1; i <= n + m; ++i) {
            den *= 1.0 * i;
            mol *= 1.0 * (i - m);
        }
        printf("%.0f\n", (den + 0.5) / mol);
    }
}