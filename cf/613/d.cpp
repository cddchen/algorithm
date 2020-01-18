#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
typedef long long LL;
std::vector<int> v;
int solve(std::vector<int> &c, int bit) {
	if (c.size() == 0 || bit < 0)
		return 0;
	std::vector<int> a, b;
	for (auto &i : c) {
		if ((i >> bit) & 1)
			b.push_back(i);
		else
			a.push_back(i);
	}
	if (a.size() == 0)
		return solve(b, bit - 1);
	if (b.size() == 0)
		return solve(a, bit - 1);
	return std::min(solve(a, bit - 1), solve(b, bit - 1)) + (1 << bit);
}
int main()
{
	int n; scanf("%d", &n);
	v.resize(n);
	for (auto &i : v)
		scanf("%d", &i);
	printf("%d\n", solve(v, 30));
}