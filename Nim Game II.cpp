#include <bits/stdc++.h>
using namespace std;

#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
using ll = long long;

int main() {
  fast;
  ll t;
  cin >> t;
  for (ll i = 0; i < t; i++) {
    ll n, x, xr = 0;
    cin >> n;
    for (ll j = 0; j < n; j++) {
      cin >> x;
      x %= 4;
      xr ^= x;
    }
    if (xr)
      cout << "first\n";
    else
      cout << "second\n";
  }

  return 0;
}
