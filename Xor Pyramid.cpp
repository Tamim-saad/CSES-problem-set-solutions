/// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define ll long long

// by lucas theorem
bool is_nCr_odd(ll n, ll r) {
  while (n > 0 || r > 0) {
    if ((r & 1) > (n & 1))
      return false;
    n >>= 1;
    r >>= 1;
  }
  return true;
}

void xorPyramid(vector<ll> v) {
  ll ans = 0;
  ll n = v.size() - 1;
  for (ll i = 0; i < v.size(); i++) {
    if (is_nCr_odd(n, i))
      ans ^= v[i];
  }
  cout << ans;
}

int main() {
  ll i, j, k, x, y, z, p, q, m, n, l, r, ans, flag, sum;
  cin >> n;
  vector<ll> v;

  for (ll i = 0; i < n; i++) {
    cin >> x;
    v.emplace_back(x);
  }
  xorPyramid(v);
}
