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
const int maxn = 15  + 5;
int a[maxn][maxn];

int main()
{
    int n, m, k; read(n), read(m), read(k);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            read(a[i][j]);
    if (k >= min(n, m)) k = min(n, m);
    int limit = 1 << n, ans = 0;
    vector<int> ret;
    for (int i = 0; i < limit; ++i) {
        int rt = __builtin_popcount(i);
        if (rt > k) continue;
        int res = 0; ret.clear();
        for (int j = 0; j < m; ++j) {
            int tmp = 0;
            for (int l = 0; l < n; ++l) {
                if ((i >> l) & 1) res += a[l][j];
                else tmp += a[l][j];
            }
            ret.push_back(tmp);
        }
        sort(ret.begin(), ret.end(), greater<int>());
        for (int i = 0; i < k - rt; ++i) {
            res += ret[i];
        }
        ans = max(ans, res);
    }
    println(ans);
}