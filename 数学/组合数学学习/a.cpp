#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200 + 5;
int dp[maxn];
int main() {
    dp[2] = 1;
    for (int i = 4; i < maxn; i += 2) {
        for (int j = 2; i - j >= 2; j += 2) {
            dp[i] += dp[j] * dp[i - j];
        }
        dp[i] *= i / 2;
    }
    int n;
    while (~scanf("%d", &n) && n >= 0) {
        printf("%d\n", dp[n << 1]);
    }
}