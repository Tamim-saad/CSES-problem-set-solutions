#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define ll long long

void kmp_pattern_count_into_string(string s, string p) {
  vector<ll> v(p.size(), 0);
  ll i = 0, j = 1;
  while (j < p.size()) {
    if (p[i] == p[j]) {
      v[j] = i + 1;
      i++;
      j++;
    } else {
      if (i != 0)
        i = v[i - 1];
      else
        j++;
    }
  }

  ll ans = 0;
  i = 0;
  j = 0;
  while (j < s.size()) {
    if (s[j] == p[i]) {
      i++;
      j++;
      if (i == p.size()) {
        ans++;
        i = v[i - 1];
      }
    } else {
      if (i != 0)
        i = v[i - 1];
      else
        j++;
    }
  }
  cout << ans << endl;
}

int main() {
  ll n, ans, k, ind = 0;
  string s, p;
  cin >> s >> p;

  kmp_pattern_count_into_string(s, p);

  return 0;
}
