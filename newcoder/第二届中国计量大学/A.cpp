#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <iostream>
using namespace std;
const int maxn = 1e4 + 5;
int cnt[maxn];
int main()
{
	freopen("in.txt", "r", stdin);
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			int x; scanf("%d", &x);
			cnt[x]++;
		}
		bool flg = true;
		for (int i = 1; i < maxn; ++i) {
			for (int j = 0; j < cnt[i]; ++j) {
				if (flg) flg = false, printf("%d", i);
				else printf(" %d", i);
			}
			cnt[i] = 0;
		}
		printf("\n");
	}
}