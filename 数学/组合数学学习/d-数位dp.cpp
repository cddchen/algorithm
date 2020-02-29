#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <ctype.h>
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
char str[12];
ll dp[12][30];
ll f(int pos, int ch, bool limit, bool lead) {
    //printf("pos = %d, ch = %d, limit = %d\n", pos, ch, limit);
    if (pos == -1) return ch > 0;
    if (!limit && dp[pos][ch] != -1) return dp[pos][ch];
    int up = limit ? str[pos] - 'a' + 1 : 26; ll sum = 0;
    //printf("%d-%d\n", limit, up);
    for (int i = lead ? 0 : ch + 1; i <= up; ++i) {
        sum += f(pos - 1, i, limit && i == up, lead && i == 0);
    }
    if (!limit) dp[pos][ch] = sum;
    return sum;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    while (~scanf("%s", &str)) {
        int n = strlen(str);
        bool flg = true;
        for (int i = 1; i < n; ++i) {
            if (str[i] <= str[i - 1]) {
                flg = false;
                break;
            }
        }
        if (!flg) { printf("0\n"); continue; }
        reverse(str, str + n);
        printf("%lld\n", f(n - 1, 0, true, true));
    }
}