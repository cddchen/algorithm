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
typedef long long ll;
const int maxn = 1e5 + 5;
const ll mod = 998244353;
ll qpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % mod2
			;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}
int f[maxn][10];
int sum[maxn];
vector<int> E[maxn];
int in[maxn];
int main()
{
	freopen("in.txt", "r", stdin);
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		E[u].push_back(v); E[v].push_back(u);
	}
}