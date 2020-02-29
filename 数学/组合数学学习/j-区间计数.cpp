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
int ans[10];
ll fib[10];
int solve(int x, int y) {
    int res = 0;
    for (int i = 1; i <= 9; ++i) {
        int l = x / fib[i - 1];
        int r = x - l * fib[i - 1];
        int rt = l % 10; l /= 10;
        //printf("%d - %d - %d\n", l, rt, r);
        
        if (y == 0) {
            if (l) {
                res += (l - 1) * fib[i - 1];
                if (rt == 0) res += r + 1;
                else if (rt > y) res += fib[i - 1];
            }
        }
        else {
            res += l * fib[i - 1];
            if (rt > y) res += fib[i - 1];
            else if (rt == y) res += r + 1;
        }
        if (l <= 0) break;
    }
    return res; 
}
int main()
{
    fib[0] = 1; for (int i = 1; i <= 9; ++i) fib[i] = fib[i - 1] * 10;
    int a, b;
    while (~scanf("%d%d", &a, &b)) {
        if (a == 0 && b == 0) break;
        if (a > b) swap(a, b);
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i <= 9; ++i) {
            printf("%d%c", solve(b, i) - solve(a - 1, i), i == 9 ? '\n' : ' ');
        }
    }
}