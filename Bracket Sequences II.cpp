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

  ll n, ans, len;
  string s;
  cin >> n >> s;
  len = n - s.length();

  if (n % 2 == 1) {
    cout << 0;
    return 0;
  }
  int l = 0, r = 0;

  for (ll i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      l++;
    } else {
      r++;
    }
    if (r > l) {
      cout << 0;
      return 0;
    }
  }
  if (l == r && l + r == n || r == 0 && l == n / 2) {
    cout << 1;
    return 0;
  }

  n /= 2;

  ll left_div_factor1 = n - l;
  ll left_div_factor2 = n - r;
  ll right_div_factor1 = n - l - 1;
  ll right_div_factor2 = n - r - 1;

  if (left_div_factor1 < 0 || right_div_factor1 < 0 || left_div_factor2 < 0 ||
      right_div_factor2 < 0) {
    cout << 0;
    return 0;
  }

  ll a1, a2;

  a1 = factorials[len];
  a1 = a1 * factorials_mod_inv[n - l] % mod;
  a1 = a1 * factorials_mod_inv[n - r] % mod;
  a2 = factorials[len];
  a2 = a2 * factorials_mod_inv[n - l - 1] % mod;
  a2 = a2 * factorials_mod_inv[n - r + 1] % mod;

  ans = (a1 - a2 + mod) % mod;

  cout << ans << endl;
  return 0;
}
