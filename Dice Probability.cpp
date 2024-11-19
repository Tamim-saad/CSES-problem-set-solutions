// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  vector<vector<double>> v(101, vector<double>(601, 0));
  v[0][0] = 1.0;
  for (ll i = 1; i <= 100; i++) {
    for (ll j = 1; j <= 600; j++) {
      for (ll k = 1; k <= 6; k++) {
        if (j - k >= 0) {
          v[i][j] += v[i - 1][j - k] / 6;
        }
      }
    }
  }
  double d = 0.0;
  for (ll i = a; i <= b; i++) {
    d += v[n][i];
  }
  cout << fixed << setprecision(6) << d << endl;
  return 0;
}
