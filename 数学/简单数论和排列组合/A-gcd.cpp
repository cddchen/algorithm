#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 5;
int a[maxn];
map<int, int> p[maxn];
int main()
{
    int t; scanf("%d", &t);
    while (getchar() != '\n');
    while (t--) {
        int n = 0; char buf;
        while ((buf = getchar()) != '\n') {
            if (buf >= '0' && buf <= '9') {
                ungetc(buf, stdin);
                scanf("%d", &a[n++]);
            }
        }
        for (int i = 0; i < n; ++i) p[i].clear();
        for (int i = 0; i < n; ++i) {
            int x = a[i];
            for (int j = 2; j * j <= x; ++j) {
                if (x % j == 0) {
                    int res = 1;
                    while (x % j == 0) { x /= j; res = res * j; }
                    p[i][j] = res;
                }
            }
            if (x) p[i][x] = x;
        }
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int tmp = 1;
                for (auto x : p[i]) {
                    if (p[j].count(x.first)) {
                        tmp *= min(x.second, p[j][x.first]);
                    }
                }
                ans = max(ans, tmp);
            }
        }
        printf("%d\n", ans);
    }
}