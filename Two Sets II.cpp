#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll mod = 1e9 + 7;

ll minCoins(ll n) {
  ll sum = (n * (n + 1)) / 2;
  if (sum % 2)
    return 0;
  vector<ll> dp(sum + 1, 0);
  dp[0] = 1;

  for (ll j = 1; j < n; j++)
    for (ll i = sum; i >= j; i--)
      dp[i] = (dp[i] + dp[i - j]) % mod;
  return dp[sum / 2];
}

int main() {
  ll n;
  cin >> n;
  cout << minCoins(n);
}
