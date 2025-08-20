/// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);

#define ll long long
#define eb emplace_back
#define vec vector<ll>
#define forr(i, a, b) for (ll i = a; i < b; i++)

const int MAX = (1 << 20);

int main() {
  fast;

  ll i, j, x, n;
  cin >> n;

  vec v(n);
  forr(i, 0, n) cin >> v[i];

  vec sub = v;

  // SOS DP
  forr(idx, 0, 20) {
    forr(i, 0, sub.size()) {
      if (i & (1 << idx)) {
        sub[i] ^= sub[i ^ (1 << idx)];
      }
    }
  }

  for (auto x : sub)
    cout << x << " ";
}
