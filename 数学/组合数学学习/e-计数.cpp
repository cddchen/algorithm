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
    int t; scanf("%d", &t);
    while (t--) {
        ll k; scanf("%lld", &k);
        int d = 0, a1 = 0, sz = 9;
        ll sum = 0;
        while (true) {
            d++; a1 += d;
            ll tmp = 1ll * a1 * sz + 1ll * sz * (sz - 1) / 2 * d;
            if (sum + tmp < k) {
                sum += tmp;
                a1 = a1 + (sz - 1) * d; sz *= 10;
                continue;
            }
            int l = 0, r = 1e6;
            while (l != r) {
                int n = (l + r) >> 1;
                if (1ll * a1 * n + 1ll * n * (n - 1) / 2 * d >= k - sum) r = n;
                else l = n + 1;
            }
            ll pre = 1ll * a1 * (l - 1) + 1ll * (l - 1) * (l - 2) / 2 * d;
            sum += pre;
            k = k - sum;
            int cnt = 0;
            for (int i = 1; ; ++i) {
                if (1 <= i && i <= 9) cnt++;
                else if (10 <= i && i <= 99) cnt += 2;
                else if (100 <= i && i <= 999) cnt += 3;
                else if (1000 <= i && i <= 9999) cnt += 4;
                else if (10000 <= i && i <= 99999) cnt += 5;
                if (cnt >= k) {
                    cnt -= k;
                    while (i) {
                        if (cnt == 0) {
                            write(i % 10); putchar('\n');
                            break;
                        }
                        cnt--;
                        i /= 10;
                    }
                    break;
                }
            }
            break;
        }
    }
    
}