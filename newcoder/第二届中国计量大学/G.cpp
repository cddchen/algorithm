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
const int maxn = 1e6 + 5;
const int inf = 0x3f3f3f3f;
std::vector<int> v1, v2;
bool cmp(int x, int y) {
	return x > y;
}
int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] <= m) v1.push_back(a[i]);
		else v2.push_back(a[i]);
	}
	v1.push_back(-inf); v2.push_back(inf);
	sort(v1.begin(), v1.end(), cmp);
	sort(v2.begin(), v2.end());
	for (int i = 0; i < v1.size() - 1; ++i) {

	}
	for (int i = 0; i < v2.size() - 1; ++i) {
		
	}
	ll ans = 0;
	if (abs(v1.front() - m) <= abs(v2.front() - m)) {

	}
	else {

	}
}