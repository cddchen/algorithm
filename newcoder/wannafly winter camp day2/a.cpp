#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
char str[maxn];
int main()
{
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	vector<ll> sum(n + 1), f(n + 1);
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1];
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'y') 
			sum[i]++;
	}
	for (int i = 1; i <= n; ++i)
		f[i] = f[i - 1] + sum[n - i + 1] - sum[i - 1];

	long double ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += (1.0 * f[i] / i);
	ans *= 2;
	ans /= 1ll * n * (n + 1);
	printf("%.10Lf\n", ans);
}