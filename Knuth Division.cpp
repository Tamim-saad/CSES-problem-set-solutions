/// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
using ll = long long;

int main() {
  fast;
  ll n, x, i, sum = 0;
  cin >> n;
  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
  vector<vector<ll>> opt(n + 1, vector<ll>(n + 1));
  vector<ll> v(n + 1), ps(n + 1, 0);

  for (i = 1; i <= n; i++) {
    cin >> x;
    v[i] = x;
    sum += x;
    ps[i] = sum;
  }

  for (ll i = 0; i <= n; i++)
    opt[i][i] = i;

  for (ll i = 2; i <= n; i++) {
    for (ll l = 1; l + i - 1 <= n; l++) {
      ll h = l + i - 1;
      ll t = ps[h] - ps[l - 1];
      ll cost, optL, optH, mini = LLONG_MAX;

      optL = max(l, opt[l][h - 1]);
      optH = min(h - 1, opt[l + 1][h]);

      for (ll k = optL; k <= optH; k++) {
        cost = dp[l][k] + dp[k + 1][h];
        if (cost < mini) {
          opt[l][h] = k;
          mini = cost;
        }
      }
      dp[l][h] = mini + t;
    }
  }

  cout << dp[1][n];
}