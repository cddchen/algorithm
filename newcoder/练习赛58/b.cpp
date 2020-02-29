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
const int maxn = 1e5 + 5;
char str[maxn];
int main() 
{
    scanf("%s", &str);
    int n = strlen(str), ans = 0;
    bool zero = false, one = false;
    for (int i = 0; i < n; ++i) {
        if (str[i] == '0') zero = true;
        else one = true;

        if (one && zero) {
            ans++;
            one = zero = false;
        }
    }
    println(ans);
}