#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int vis[20];
int res[100], tot;

int main()
{
	freopen("in.txt", "r", stdin);
	int t; cin >> t;
	while (t--) {
		queue<int> a, b;
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= 26; ++i) {
			int x; cin >> x;
			a.push(x);
		}
		for (int i = 1; i <= 26; ++i) {
			int x; cin >> x;
			b.push(x);
		}
		tot = 0;
		while (true) {
			int x = a.front(); a.pop();
			while (vis[x] != 0) {
				a.push(x);
				for (int i = tot; i >= vis[x]; --i) 
					a.push(res[i]);
				tot = vis[x] - 1; vis[x] = 0;
				x = a.front(); a.pop();
			}
			res[++tot] = x; vis[x] = tot;

			x = b.front(); b.pop();
			while (vis[x] != 0) {
				b.push(x);
				for (int i = tot; i >= vis[x]; --i) 
					b.push(res[i]);
				tot = vis[x] - 1; vis[x] = 0;
				x = b.front(); b.pop();
			}
			res[++tot] = x; vis[x] = tot;

			if (a.empty() || b.empty()) break;
		}
		if (a.empty()) cout << "B" << endl;
		else cout << "A" << endl;
	}
}