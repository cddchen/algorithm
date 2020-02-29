#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <ctype.h>
using namespace std;
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
void write(int x){
    if(x < 0)
        putchar('-'), x = -x;
    if(x > 9)
        write(x / 10);
    putchar('0' + x % 10);
}
const int maxn = 32 + 5;
int dp[maxn][maxn << 1], a[maxn];
int f(int pos, int num, bool limit, bool lead) {
    if (pos == -1) return num >= 0;
    if (!limit && !lead && dp[pos][num + maxn] != -1) return dp[pos][num + maxn];
    int up = limit ? a[pos] : 1, sum = 0;
    for (int i = 0; i <= up; ++i) {
        if (lead && i == 0) sum += f(pos - 1, num, limit && i == a[pos], lead && i == 0);
        else sum += f(pos - 1, num + (i == 0 ? 1 : -1), limit && i == a[pos], lead && i == 0);
    }
    if (!limit && !lead) dp[pos][num + maxn] = sum;
    return sum;
}
int solve(int x) {
    int p = 0;
    while (x) {
        a[p++] = x % 2;
        x /= 2;
    }
    return f(p - 1, 0, true, true);
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int a, b; read(a), read(b);
    write(solve(b) - solve(a - 1));
}