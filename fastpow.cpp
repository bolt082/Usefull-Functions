template <typename T>
T modpow(T base, T exp) {
  base %= MOD;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return result;
}
