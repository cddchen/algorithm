#include <bits/stdc++.h>
const int maxn = 1e5 + 5;

char str[maxn];
int main()
{
	int n; scanf("%d", &n);
	scanf("%s", &str);
	int lef = 0, rig = 0;
	for (int i = 0; i < n; ++i) {
		if (str[i] == 'L')
			lef++;
		else
			rig++;
	}
	printf("%d\n", rig + lef + 1);
}