ll ex_gcd(ll a, ll b, ll& x, ll& y) {
  if (a == 0 && b == 0) return -1;  // 无最大公因数
  ll d = a;
  if (b != 0)
    d = ex_gcd(b, a % b, y, x), y -= x * (a / b);
  else
    x = 1, y = 0;
  return d;
}

// mod不满足两两互质
// 通解为 re + k*M
// 返回最小非负整数解
bool excrt(ll r[], ll m[], int n, ll& re, ll& M) {
  ll x, y;
  M = m[0], re = r[0];
  for (int i = 1; i < n; i++) {
    ll d = ex_gcd(M, m[i], x, y);
    if ((r[i] - re) % d != 0) return 0;
    x = (r[i] - re) / d * x % (m[i] / d);
    re += x * M;
    M = M / d * m[i];
    re = re % M;
  }
  re = (re + M) % M;
  return 1;
}

const int maxn = 105;
ll re[maxn], mod[maxn];

int main() {
  int n;
  ll m;
  cin >> n >> m;
  for (int i = 0, a, b; i < n; i++) {
    cin >> mod[i] >> re[i];
  }
  ll R, M;
  bool ok = excrt(re, mod, n, R, M);
  if (ok == false) {
    cout << "he was definitely lying\n";
    return 0;
  }
  if (R > m)
    cout << "he was probably lying\n";
  else
    cout << R << '\n';
}
