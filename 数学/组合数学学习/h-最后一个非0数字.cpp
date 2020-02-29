#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <ctype.h>
using namespace std;
typedef long long ll;
int get_prime_factor(int n, int x) {
    if (!n) return 0;
    return n / x + get_prime_factor(n / x, x);
}
int g(int n, int x) {
    if (!n) return 0;
    return n / 10 + (n % 10 >= x) + g(n / 5, x);
}
int f(int n, int x) {
    if (!n) return 0;
    return f(n / 2, x) + g(n, x);
}
//2,3,7,9的循环节，其中注意若2的个数为0的话循环节第一位应该为1
int cyclic_section[][4] = {{6, 2, 4, 8}, {1, 3, 9, 7}, {1, 7, 9, 3}, {1, 9, 1, 9}};
int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        int cnt2 = get_prime_factor(n, 2) - get_prime_factor(n - m, 2);
        int cnt5 = get_prime_factor(n, 5) - get_prime_factor(n - m, 5);
        int cnt3 = f(n, 3) - f(n - m, 3);
        int cnt7 = f(n, 7) - f(n - m, 7);
        int cnt9 = f(n, 9) - f(n - m, 9);
        int ans = 1;
        if (cnt5 > cnt2) {
            printf("5\n"); continue;
        }
        if (cnt2 != cnt5) {
            ans *= cyclic_section[0][(cnt2 - cnt5) % 4];
            ans %= 10;
        }
        ans *= cyclic_section[1][cnt3 % 4]; ans %= 10;
        ans *= cyclic_section[2][cnt7 % 4]; ans %= 10;
        ans *= cyclic_section[3][cnt9 % 4]; ans %= 10;
        printf("%d\n", ans);
    }
}