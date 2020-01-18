#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int MOD = 998244353;
class SegTree
{
private:
	struct El
	{
		int p[2][2];
		El() {
			memset(p, 0, sizeof(p));
		}
		static El id() {
			El res;
			res.p[0][0] = res.p[1][1] = 1;
			return res;
		}
	};
	static El combine(const El& le, const El& ri) {
		El res;
		for (int a = 0; a < 2; ++a) {
			for (int b = 0; b < 2; ++b) {
				for (int i = 0; i < 2; ++i) {
					res.p[a][b] = (res.p[a][b] + (ll)le.p[a][i] * ri.p[i][b]) % MOD;
				}
			}
		}
		return res;
	}
	void update(int i) {
		for (i >>= 1; i > 0; i >>= 1)
			seg[i] = combine(seg[i * 2], seg[i * 2 + 1]);
	}

	vector<El> seg;
	int h = 1;
public:
	SegTree(int n) {
		while (h < n) h <<= 1;
		seg.resize(h << 1, El::id());
	}
	int prob(int i, int a, int b) {
		i += h;
		El backup = seg[i];
		for (int x = 0; x < 2; ++x) {
			for (int y = 0; y < 2; ++y) {
				if (x != a || y != b)
					seg[i].p[x][y] = 0;
			}
		}
		update(i);

		ll res = (seg[1].p[0][0] + seg[1].p[0][1]) % MOD;

		seg[i] = backup;
		update(i);
		return res;
	}
	void setv(int i, int a, int b, int c, int d) {
		i += h;
		seg[i].p[0][0] = a;
		seg[i].p[0][1] = b;
		seg[i].p[1][0] = c;
		seg[i].p[1][1] = d;
		update(i);
	}
	void zero(int i, int a, int b) {
		i += h;
		seg[i].p[a][b] = 0;
		update(i);
	}
};
int main() {
	int n; cin >> n; 
	SegTree seg(n);
}