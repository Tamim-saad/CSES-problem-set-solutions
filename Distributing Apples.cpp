#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll modular_exponent(ll base, ll pow, ll mod) {
  if (pow == 0)
    return 1;

  ll x = modular_exponent(base, pow / 2, mod);

  if (pow % 2 == 0)
    return (x * x) % mod;
  else
    return ((x * x) % mod * base) % mod;
}

void compute_factorial_with_modular_inverse(ll mod, vector<ll> &factorials,
                                            vector<ll> &factorials_mod_inv) {
  factorials[0] = 1;
  int n = factorials.size() - 1;
  for (int i = 1; i <= n; i++) {
    factorials[i] = factorials[i - 1] * i % mod;
  }
  factorials_mod_inv[n] = modular_exponent(factorials[n], mod - 2, mod);
  for (int i = n - 1; i >= 0; i--) {
    factorials_mod_inv[i] = factorials_mod_inv[i + 1] * (i + 1) % mod;
  }
}

int main() {

  ll mod = 1e9 + 7;
  vector<ll> factorials(2000001);
  vector<ll> factorials_mod_inv(2000001);
  compute_factorial_with_modular_inverse(mod, factorials, factorials_mod_inv);

  ll n, m;
  cin >> n >> m;

  ll ans = factorials[m+n-1];
  ans = (ans * factorials_mod_inv[n-1]) % mod;
  ans = (ans * factorials_mod_inv[m]) % mod;

  cout << ans << endl;
  return 0;
}