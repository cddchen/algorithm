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
int vis[20], ans[20];
ll c[20][10], fib[10];

int main()
{
    for (int i = 1; i <= 16; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    fib[0] = 1; for (int i = 1; i <= 7; ++i) fib[i] = fib[i - 1] * i;
    ll k;
    while (~scanf("%lld", &k)) {
        int cnt = 0;
        bool lead = true;
        for (int i = 8, j; i > 0; --i) {
            for (j = 15; j >= 1; --j) {
                if (vis[j]) continue;
                ll tmp = c[16 - cnt - 1][i - 1] * fib[i - 1];
                if (tmp < k) k -= tmp;
                else { vis[j] = true; break; }
            }
            if (!lead || j != 0) cnt++;
            if (j != 0)  lead = false;
            if (j == 0 && lead) continue;
            printf("%c", j >= 10 ? j - 10 + 'A' : j + '0');
        }
        putchar('\n');
    }
}