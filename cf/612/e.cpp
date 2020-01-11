#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
multiset<string> st;
string fn[maxn];
int vis[30];

int main() {
	int n; cin >> n;
	cout << "? 1 " << n << endl;
	for (int i = 0; i < (n + 1) * n / 2; ++i) {
		string str; cin >> str;
		sort(str.begin(), str.end());
		st.insert(str);
	}
	if (n == 1) {
		cout << "! " << *st.begin() << endl;
		return 0;
	}
	cout << "? 2 " << n << endl;
	for (int i = 0; i < n * (n - 1) / 2; ++i) {
		string str; cin >> str;
		sort(str.begin(), str.end());
		st.erase(st.find(str));
	}
	string ans;
	for (string str : st) {
		fn[str.size()] = str;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) 
			vis[fn[i][j] - 'a']++;
		for (int j = 0; j < i - 1; ++j) 
			vis[ans[j] - 'a']--;

		for (int j = 0; j < 26; ++j) {
			if (vis[j] != 0) {
				ans += (j + 'a');
				vis[j] = 0;
				break;
			}
		}
	}
	cout << "! " << ans << endl;
}