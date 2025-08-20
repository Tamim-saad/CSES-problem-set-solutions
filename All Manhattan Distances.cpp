/// Alhamdulillah

#include <algorithm>
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

// print __int128
auto print128 = [](__int128 x) {
  if (x == 0) {
    cout << 0;
    return;
  }
  string s;
  while (x) {
    s += char('0' + x % 10);
    x /= 10;
  }
  reverse(s.begin(), s.end());
  cout << s;
};

int main() {
  fast;

  ll n;
  __int128 ans = 0;
  cin >> n;

  vec vx(n), vy(n);
  forr(i, 0, n) { cin >> vx[i] >> vy[i]; }

  sort(vx.begin(), vx.end());
  sort(vy.begin(), vy.end());

  forr(i, 1, n) {
    ans += (__int128)(vx[i] - vx[i - 1]) * i * (n - i);
    ans += (__int128)(vy[i] - vy[i - 1]) * i * (n - i);
  }

  print128(ans);
}