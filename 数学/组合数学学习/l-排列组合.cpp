#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <utility>
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
//求出2的因子数
int getfactor(int x) {
    int ret = 0;
    for (int i = 2; i <= x; i <<= 1) {
        ret += x / i;
    }
    return ret;
}
bool solve(int n, int m) {
    return getfactor(n) - getfactor(m) - getfactor(n - m) == 0;
    return (n & m) - m == 0; //C_n^m为奇数当且仅当m&n=m
}
int main() 
{
    int t; read(t);
    while (t--) {
        int n, m; read(n); read(m);
        int decre = n - m, k = (m + 1) / 2;
        println(solve(decre + k - 1, k - 1));
    }
}