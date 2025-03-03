/// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll countNumbers(ll k) {
  if (k == 0) return 1;
  if (k < 0) return 0;
  ll n = log10(k) + 1;

  ll x, ans = 0;
  vector<ll> dp(n), v;

  x = 1;
  for (ll i = 0; i < n; i++) {
    dp[i] = x;
    x *= 9;

    v.emplace_back(k % 10);
    k /= 10;

    ans += dp[i];
  }
  reverse(v.begin(), v.end());

  int last = 0;
  for (ll i = 0; i < n; i++) {
    x = (v[i] > last) ? v[i] - 1 : v[i];

    ans += v[i] == 0 ? 0 : x * (dp[n - i - 1]);
    if (v[i] == last) return ans;
    last = v[i];
  }

  return ans + 1;
}

int main() {
  ll a, b;
  cin >> a >> b;
  cout << countNumbers(b) - countNumbers(a - 1);
}

// https://www.youtube.com/watch?v=TN0qGN0YqDQ&list=PLC6tU0n3mgCL-WyIIxzNt5BEgPpquufeB&index=19