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
const int maxn = 1024 + 5;
int n, m, a[maxn];

int main()
{
    int t; read(t);
    while (t--) {
        read(n), read(m);
        for (int i = 1; i <= n; ++i) read(a[i]);
        while (m) { next_permutation(a + 1, a + n + 1); m--; }
        for (int i = 1; i <= n; ++i) {
            write(a[i]);
            putchar(i == n ? '\n' : ' ');
        }
    }
}