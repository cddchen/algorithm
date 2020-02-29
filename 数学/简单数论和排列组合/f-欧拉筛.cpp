#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e6 + 5;
/*
int phi[maxn], vis[maxn], prime[maxn], tot;
void euler(int limit) {
    vis[0] = vis[1] = phi[1] = 1;
    for (int i = 2; i <= limit; ++i) {
        if (!vis[i]) { prime[tot++] = i; phi[i] = i - 1; }
        for (int j = 0; j < tot && i * prime[j] <= limit; ++j) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}
*/
ll euler[maxn];
void get_euler(int limit) {
    euler[1] = 1;
    for (int i = 2; i <= limit; ++i) {
        if (euler[i]) continue;
        for (int j = i; j <= limit; j += i) {
            if (!euler[j]) euler[j] = j;
            euler[j] = euler[j] / i * (i - 1);
        }
    }
}
int main()
{
}