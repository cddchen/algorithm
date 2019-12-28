#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
const int mod = 10007;
const int maxn = 1e7 + 5;
int dp[maxn];
int main()
{
	//freopen("in.txt", "r", stdin);
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	dp[0] = 1;
	for (int i = 0; i <= n; ++i) {
		if (i >= a) dp[i] = (dp[i] + dp[i - a]) % mod;
		if (i >= b) dp[i] = (dp[i] + dp[i - b]) % mod;
	}
	printf("%d\n", dp[n]);
}