#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int pr[maxn], cnt;
inline int exgcd(int a, int b,int &x, int &y){
	if (!b) { x=1, y=0; return a; }
	else { int d = exgcd(b, a % b, y, x); y -= a / b * x; return d; }
}
inline int ksm(int a,int b,int p){
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%p) if(b&1) s=1ll*s*a%p;
	return s;
}
void getprime(int p){
	for (int i = 2; i * i <= p; i++) if(p % i == 0) {
		pr[++cnt] = i;
		while(p % i == 0) p /= i;
	}
	if (p > 1) pr[++cnt] = p;
}
int getrg(int p){
	if(p == 2) return 1;
	getprime(p - 1);
	for(int i = 2; i < p; i++) {
		for(int j = 1; j <= cnt; j++) if(ksm(i, (p - 1) / pr[j], p) == 1) goto he;
		return i; he:;
	}
}
//计算a^x=b(modp)
int BSGS(int a, int b, int p) {
	if (b == 1) return 0;
	int m = int(sqrt(p) + 1), base = b;
	map<int, int> has;
	for(int i = 0; i < m; i++) has[base] = i, base = 1ll * base * a % p;
	int now = 1; base = ksm(a, m, p);
	for(int i = 1;i <= m; i++)
		if(has.count(now = 1ll * now * base % p)) return i * m - has[now];
	return -1;
}
int ans[maxn], tot;
int main()
{
	int k,a,p;
	scanf("%d%d%d", &p, &k, &a);
	if(a == 0) return printf("1\n0"),0;
	int g = getrg(p);
	int A = BSGS(g, a, p), x, y;
	int d = exgcd(k, p - 1, x, y);
	if (A == -1 || A % d) return puts("0"), 0;
	int sp = (p - 1) / d; x = (1ll * x * A / d % sp + sp) % sp;
	if (!x) x = sp;//x->phi[p]=p-1
	for (int i = x; i < p; i += sp) ans[++tot] = ksm(g, i, p);
	sort(ans + 1, ans + 1 + tot);
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++) printf("%d%c", ans[i], i == tot ? 10 : 32);
}