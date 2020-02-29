#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <utility>
#include <ctype.h>
#include <iostream>
#include <iomanip>
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
const int maxn = 120 + 5;
int dp[maxn][maxn];
int solve(int n, int m) {
    if (n == 0) return 1;
    if (m > n) return 0;
    if (dp[n][m] != -1) return dp[n][m];
    int res = 0;
    for (int i = m; i <= n; ++i) {
        if (n - i >= i) {
            res += solve(n - i, i);
        }
        else if (i == n) 
            res += solve(0, i);
    }
    return dp[n][m] = res;
}
int a[] = {1, 3, 5, 7, 9, 11, 13, 15};
int main()
{
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            for (int k = 0; k < 8; ++k) {
                if (a[i] + a[j] + a[k] == 30) {
                    printf("%d %d %d\n", a[i], a[j], a[k]);
                }
            }
        }
    }
    printf("ok");
}