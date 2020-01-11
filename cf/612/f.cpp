#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &a[i].x, &a[i].v, &a[i].p);
		hsh.push_back(a[i].x);
	}
	sort(hsh.begin(), hsh.end());
	hsh.erase(unique(hsh.begin(), hsh.end()), hsh.end());
	for (int i = 0; i < n; ++i) {

	}
}