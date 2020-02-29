#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <ctype.h>
#include <stack>
using namespace std;
typedef long long ll;
inline void read(int &x){
    int data = 0, w = 1;
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
ll fib[12];
ll solve(ll x) {
    if (x < 0) return -1;
    ll res = 0;
    for (int i = 1; i <= 12; ++i) {
        ll l = x / fib[i - 1];
        ll r = x - l * fib[i - 1];
        int rt = l % 10; l /= 10;
        if (!l) break;
        res += (l - 1) * fib[i - 1];
        if (rt) res += fib[i - 1];
        else res += r + 1;
    }
    return res;
}
int main()
{
    fib[0] = 1; for (int i = 1; i <= 12; ++i) fib[i] = fib[i - 1] * 10;
    ll a, b;
    while (~scanf("%lld%lld", &a, &b)) {
        if (a == -1 && b == -1) break;
        if (a == 0 && b == 0) printf("1\n");
        else printf("%lld\n", solve(b) - solve(a - 1));
    }
}