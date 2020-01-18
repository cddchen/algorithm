#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll exgcd(ll a, ll b, ll &x, ll &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll r = exgcd(b, a % b, x, y);
	ll tmp = x;
	x = y;
	y = tmp - a / b * y;
	return r;
}
//ax = b(mod n) -> ax - ny = b
vector<ll> line_mod_quation(ll a, ll b, ll n) {
    ll x, y;
    ll d = exgcd(a, n, x, y);
    vector<ll> ans;
    ans.clear();
    if(b % d == 0) {
        x %= n; x += n; x %= n;
        ans.push_back(x * (b / d) % (n / d));
        for(int i = 1; i <= d; i++) ans.push_back((ans[0] + i *  n / d) % n);
    }
    return ans;
}
