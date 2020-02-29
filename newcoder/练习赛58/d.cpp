#include <bits/stdc++.h>
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
void print(ll x){
    if(x < 0)
        putchar('-'), x = -x;
    if(x > 9)
        print(x / 10);
    putchar('0' + x % 10);
}
void println(int x) {
    if(x < 0)
        putchar('-'), x *= - 1;
    if(x == 0)
        putchar('0');
    int ans[1 << 5], top = 0;
    while(x)
        ans[top ++] = x % 10, x /= 10;
    for(; top; top --)
        putchar(ans[top - 1] + '0');
    putchar('\n');
}
const int maxn = 1e3 + 5;
char a[maxn][maxn];
int dp[maxn][maxn];
int main()
{
    int n, m; read(n), read(m);
    for (int i = 1; i <= n; ++i) 
        scanf("%s", a[i] + 1);
    memset(dp, 1, sizeof(dp));
    dp[1][1] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == '1') continue;
            if (j < m && a[i][j + 1] == '0')
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
            if (i < n && a[i + 1][j] == '0') {
                if (j == m || a[i][j + 1] == '1')
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
                else dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            }
        }
    }
    println(dp[n][m] == dp[0][0] ? -1 : dp[n][m]);
}