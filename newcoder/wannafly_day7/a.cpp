#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
const ll mod = 1e9 + 7;
ll sub(ll a, ll b) {
    return a - b < 0 ? a - b + mod : a - b;
}
ll add(ll a, ll b) {
    return a + b >= mod ? a + b - mod : a + b;
}
ll tr[maxn << 1];
int lowbit(int x) {
    return x & -x;
}
void update(int pos, int val, int n) {
    for (int i = pos; i <= n; i += lowbit(i)) {
        tr[i] = add(tr[i], val);
    }
}
ll sum(int pos) {
    ll rhs = 0;
    for (int i = pos; i; i -= lowbit(i))
        rhs = add(rhs, tr[i]);
    return rhs;
}
ll mul[maxn], delta[maxn];
int a[maxn];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    mul[0] = 1;
    for (int i = 1; i <= n; ++i) {
        mul[i] = mul[i - 1] * 2 % mod;
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        ll val = sum(a[i] - 1) *  mul[n - i] % mod;
        delta[a[i]] = sub(delta[a[i]], val);
        val = sub(sum(n), sum(a[i])) * mul[n - i] % mod;
        delta[a[i] + 1] = add(delta[a[i] + 1], val);
        update(a[i], mul[i - 1], n);
    }
    for (int i = 1; i <= (n << 1); ++i)
        tr[i] = 0;
    for (int i = n; i >= 1; --i) {
        ll val = sub(sum(n), sum(a[i])) * mul[i - 1] % mod;
        delta[a[i] + 1] = add(delta[a[i] + 1], val);
        val = sum(a[i] - 1) * mul[i - 1] % mod;
        delta[a[i]] = sub(delta[a[i]], val);
        update(a[i], mul[n - i], n);
    }
    for (int i = 1; i <= n; ++i) {
        delta[i] = add(delta[i - 1], delta[i]);
        cout << delta[i] << '\n';
    }
}