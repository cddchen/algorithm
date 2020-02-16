#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
char in[maxn];
int n, a, b, c, d, mx_ans, mn_ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> n >> a >> b >> c >> d;
		mx_ans = mn_ans = 0;
		cin >> in;
		int aa = a, bb = b, cc = c, dd = d;
		for (int i = 0; in[i]; ++i) {
			if (in[i] == '1') {
				if (cc != 0) {
					cc--; mx_ans++;
				}
				else if (dd != 0) {
					dd--; cc++;
				}
				else if (aa != 0) {
					aa--; mx_ans++;
				}
				else if (bb != 0) {
					bb--; aa++;
				}
			}
			else {
				if (dd != 0) {
					dd--; cc++;
				}
				else if (cc == 0 && bb != 0) {
					bb--; aa++;
				}
			}
		}
		aa = a, bb = b, cc = c, dd = d;
		for (int i = 0; in[i]; ++i) {
			if (in[i] == '1') {
				if (dd != 0) {
					dd--; cc++;
				}
				else if (cc != 0) {
					cc--; mn_ans++;
				}
				else if (bb != 0) {
					bb--; aa++;
				}
				else if (aa != 0) {
					aa--; mn_ans++;
				}
			}
			else {
				if (cc != 0) {

				}
				else if (dd != 0) {
					dd--; cc++;
				}
				else if (aa != 0) {

				}
				else if (bb != 0) {
					bb--; aa++;
				}
			}
		}
		cout << mx_ans << ' ' << mn_ans << '\n';
	}
}