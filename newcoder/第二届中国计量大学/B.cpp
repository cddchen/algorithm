#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		ll cnt = m / n;
		cnt = (1 + cnt) * cnt;
		cnt /= 2; cnt *= n;
		ll sum = 1ll * m * (m + 1) / 2;
		cout << sum - 2 * cnt << endl;
	}
}