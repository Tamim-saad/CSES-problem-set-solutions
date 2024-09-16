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

  ll t;
  cin >> t;

  ll mod = 1e9 + 7;
  vector<ll> factorials(1000001);
  vector<ll> factorials_mod_inv(1000001);
  compute_factorial(mod, factorials, factorials_mod_inv);

  while (t--) {

    ll x, y;
    cin >> x >> y;

    ll ans = factorials[x];
    ans = (ans * factorials_mod_inv[y] % mod);
    ans = (ans * factorials_mod_inv[x - y] % mod);

    cout << ans << endl;
  }
  return 0;
}
