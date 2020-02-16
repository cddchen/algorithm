int inv[maxn];
inv[1] = inv[2] = 1;
inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;