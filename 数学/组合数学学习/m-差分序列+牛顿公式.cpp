#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <utility>
#include <ctype.h>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long ll;
const int BASE = 100000000, WIDTH = 8;
struct BigInt {
    bool neg;
    vector<int> s;
    BigInt operator =(string &str) {
        s.clear();
        neg = false;
        if (str[0] == '-') {
            neg = true;
            str[0] = '0';
        }
        int x, len = (str.length() - 1) / WIDTH + 1;
        for (int i = 0; i < len; i++) {
            int end = str.length() - i * WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start, end - start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    }
    BigInt operator =(int n) {
        s.clear();
        if (n < 0){
            neg = true;
            s.push_back(-n);
        } else {
            neg = false;
            s.push_back(n);
        }
        return *this;
    }
    void print() {
        if (neg) cout << '-';
        cout << s.back();
        for (int i = s.size() - 2; i >= 0; i--) {
            cout << setw(8) << setfill('0') << s[i];
        }
        cout << endl;
    }
};
bool operator ==(const BigInt &a, const BigInt &b) {
    if (a.neg != b.neg) return false;
    if (a.s.size() == b.s.size()) {
        for (int i = 0; i < a.s.size(); i++)
            if (a.s[i] != b.s[i]) return false;
        return true;
    }
    return false;
}
bool operator <(BigInt &a, BigInt &b) {
    if (a.neg && !b.neg) return true;
    if (!a.neg && b.neg) return false;
    if (a.neg && b.neg) {
        a.neg = b.neg = false;
        bool ans = a < b || a == b;
        a.neg = b.neg = true;
        return !ans;
    }
    if (a.s.size() < b.s.size()) return true;
    else if (a.s.size() > b.s.size()) return false;
    for (int i = a.s.size() - 1; i >= 0; i--) {
        if (a.s[i] == b.s[i]) continue;
        if (a.s[i] < b.s[i]) return true;
        return false;
    }
    return false;
}
bool operator >(BigInt &a, BigInt &b) { return !(a == b && a < b); }
bool operator <=(BigInt &a, BigInt &b) { return (a == b || a < b); }
bool operator >=(BigInt &a, BigInt &b){ return !(a < b); }
bool operator !=(BigInt &a, BigInt &b){ return !(a == b); }
BigInt operator -(BigInt &a, BigInt &b);
BigInt operator +(BigInt &a, BigInt &b){
    BigInt ans;
    if (a.neg && !b.neg) {
        a.neg = false;
        ans = b - a;
        a.neg = true;
        return ans;
    }
    if (!a.neg && b.neg) {
        b.neg = false;
        ans = a - b;
        b.neg = true;
        return ans;
    }
    ans.neg = a.neg;
    int k = 0, i = 0;
    while (i < a.s.size() || i < b.s.size()) {
        if (i < a.s.size()) k += a.s[i];
        if (i < b.s.size()) k += b.s[i];
        ans.s.push_back(k % BASE);
        k /= BASE;
        i++;
    }
    if(k) ans.s.push_back(k);
    return ans;
}
BigInt operator -(BigInt &a, BigInt &b) {
    BigInt ans;
    if (!a.neg && b.neg){
        b.neg = false;
        ans = a + b;
        b.neg = true;
        return ans;
    }
    if (a.neg && !b.neg) {
        a.neg = false;
        ans = a + b;
        a.neg = true;
        ans.neg = true;
        return ans;
    }
    if (a.neg && b.neg && a > b) {
        b.neg = a.neg = false;
        ans = b - a;
        b.neg = a.neg = true;
        return ans;
    }
    if (!a.neg && !b.neg && a < b) {
        ans = b - a;
        ans.neg = true;
        return ans;
    }
    ans.neg = false;
    int k = 0, i = 0;
    while (i < a.s.size() || i < b.s.size()) {
        if (i < a.s.size()) k += a.s[i];
        if (i < b.s.size()) k -= b.s[i];
        if (k < 0) {
            ans.s.push_back(k + BASE);
            k = -1;
        } else {
            ans.s.push_back(k);
            k = 0;
        }
        i++;
    }
    while (ans.s.size() > 1 && i >= 0 && ans.s[--i] == 0) ans.s.pop_back();
    return ans;
}
BigInt operator *(BigInt &a, BigInt &b) {
    if (a.s.size() < b.s.size()) return b * a;
    BigInt ans;
    ll k = 0;
    for (int l = 0; l < a.s.size() + b.s.size() - 1; l++) {
        for (int i = min(l, int(a.s.size() - 1)); i >= 0 && l - i < b.s.size(); i--) {
            k += (ll)a.s[i] * b.s[l - i];
        }
        ans.s.push_back(k % BASE);
        k /= BASE;
    }
    if (k) ans.s.push_back(k);
    ans.neg = a.neg ^ b.neg;
    return ans;
}
BigInt operator *(BigInt &a, int b){
    BigInt ans;
    ll k = 0;
    for(int l = 0; l < a.s.size(); l++) {
        k += a.s[l] * b;
        ans.s.push_back(k % BASE);
        k /= BASE;
    }
    if (k) ans.s.push_back(k);
    if ((b < 0 && a.neg) || (b > 0 && !a.neg)) ans.neg = false;
    else ans.neg = true;
    return ans;
}
inline void devide_2(BigInt &a) {
    int k = 0;
   // a.print();
    for(int i = a.s.size() - 1; i >= 0; i--) {
        int k0 = k;
        k = a.s[i] % 2 == 0 ? 0 : BASE / 2;
        //cout<<a.s[i]<<endl;
        a.s[i] = k0 + a.s[i] / 2;
        //cout<<a.s[i]<<endl;
    }
    if(a.s.back() == 0) a.s.pop_back();
}
inline BigInt devide(BigInt &a, BigInt &b, BigInt &r) {
    BigInt L, R, m, t;
    L = 1; R = a;
    if (a < b) {
        r = a;
        return m = 0;
    }
    while (R > L) {
        //L.print();
        //R.print();
        t = (R + L);
        devide_2(t);
        if(t == L){
            m = t * b;
            r = a - m; return L;
        }
        m = t * b;
        //m.print();
        if(m == a) {
            r = 0; return t;
        } else if (m < a) {
            L = t;
        } else {
            R = t;
        }
    }
    m = t * b;
    r = a - m;
    return L;
}
inline BigInt operator %(BigInt &a, BigInt &b) {
    BigInt r;
    devide(a, b, r);
    return r;
}
inline bool Is_even(const BigInt &a) {
    if (a.s[0] % 2 == 0) return true;
    return false;
}
const int maxn = 100 + 5;
BigInt C[maxn];
BigInt h[maxn][maxn];
string str;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int m; cin >> str >> m;
        BigInt n; n = str; C[1] = n;
        BigInt I, _I; I = 2; _I = 1;
        for (int i = 2; i <= m + 1; ++i) {
            BigInt decre = n - _I;
            C[i] = C[i - 1] * decre; C[i] /
        }  
    }
}