/*
x = a1(mod m1)
x = a2(mod m2)
.
x = an(mod mn)
其中m1到mn两两互质的整数
*/
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
ll CRT(int n, int a[], int m[]) {
    ll M = 1, x = 0, xx, yy;
    for(int i = 0; i < n; i++) M *= m[i];
    for(int i = 0; i < n; i++) {
        ll w = M / m[i];
        exgcd(m[i], w, xx, yy);
        x = (x + yy * w * a[i]) % M;
    }
    return (x + M) % M;
}
