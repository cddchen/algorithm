#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e7 + 5;
bool is_prime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
int main()
{
    for (int i = 4; i <= 100; ++i) {
        printf("i = %d:\n", i);
        int cnt = 0;
        for (int j = 2; j <= i / 2; ++j) {
            if (is_prime(j) && is_prime(i - j)) {
                printf("%d - %d\n", j, i - j);
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    int t; scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas) {
        int n; scanf("%d", &n);
        printf("Case #%d: ", cas);
        if (!(n & 1) || is_prime(n - 2)) printf("1\n");
        else printf("0\n");
    }
}