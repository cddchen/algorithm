#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
typedef long long ll;
ll a1, a2, b1, b2;
int main()
{
    scanf("%lld%lld", &a1, &a2);
    int n; scanf("%d", &n);
    ll ans = 1e8;
    for (int i = 0; i < n; ++i) {
    	scanf("%lld%lld", &b1, &b2);

        ll l = 1, r = 1e8;
    	while (l < r) {
    		ll mid = (l + r) / 2;

    		if (mid * (mid + 1) >= 2 * (max(b1 - mid * a1, 0ll) + max(b2 - mid * a2, 0ll)))
    			r = mid;
    		else
    			l = mid + 1;
    	}
    	ans = min(ans, l);
    }
    printf("%lld\n", ans);
}