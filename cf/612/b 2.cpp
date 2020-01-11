#include <bits/stdc++.h>
using namespace std;
struct TrieNode
{
	int data, nxt[3];
	void init() {
		data = 0;
		memset(nxt, 0, sizeof(nxt));
	}
};
struct Trie
{
	static const int maxn = 45000 + 5;
	TrieNode tn[maxn];
	int root, tp;

	int newNode() {
		tn[++tp].init(); return tp;
	}
	void init() {
		tp = 0; root = newNode();
	}

	void insert(int *a, int len, int data) {
		int cur = root;
		for (int i = 0; i < len; ++i) {
			int &nxt = tn[cur].nxt[a[i]];
			if (!nxt)
				nxt = newNode();
			cur = nxt;
		}
		tn[cur].data += data;
	}
	int query(int *a, int len) {
		int cur = root;
		for (int i = 0; i < len; ++i) {
			int &nxt = tn[cur].nxt[a[i]];
			if (!nxt)
				return 0;
			cur = nxt;
		}
		return tn[cur].data;
	}
} trie;
const int maxn = 1500 + 5;
int fn(char x) {
	if (x == 'S')
		return 0;
	else if (x == 'E')
		return 1;
	return 2;
}
int a[maxn][35], rhs[35];
char str[35];
int main()
{
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%s", &str);
		for (int j = 0; j < k; ++j) 
			a[i][j] = fn(str[j]);
		trie.insert(a[i], k, 1);
	}
	int ans = 0;
	for (int i1 = 0; i1 < n; ++i1) {
		for (int i2 = i1 + 1; i2 < n; ++i2) {
			for (int j = 0; j < k; ++j) {
				if (a[i1][j] == a[i2][j]) 
					rhs[j] = a[i1][j];
				else {
					int vis[3] = {0};
					vis[a[i1][j]] = vis[a[i2][j]] = 1;
					for (int i = 0; i <= 3; ++i) {
						if (vis[i] == 0) {
							rhs[j] = i;
							break;
						}
					}
				}
			}
			ans += trie.query(rhs, k);
		}
	}
	printf("%d\n", ans / 3);
}