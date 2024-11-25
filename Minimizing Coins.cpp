#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll inf = 1e9;

ll minCoins(vector<ll> coin_value, ll n, long amt) {
  vector<ll> dp(amt + 1, inf);
  dp[0] = 0;

  for (ll i = 1; i <= amt; i++) {
    for (auto x : coin_value) {
      if (i >= x)
        dp[i] = min(dp[i], 1 + dp[i - x]);
    }
  }
  if (dp[amt] == inf)
    return -1;
  return dp[amt];
}

int main() {
  ll v, m;
  cin >> m >> v;

  vector<ll> coins;
  for (ll i = 0; i < m; i++) {
    ll x;
    cin >> x;
    coins.emplace_back(x);
  }

  cout << minCoins(coins, m, v) << "\n";
}
