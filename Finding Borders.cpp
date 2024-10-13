#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define ll long long

void kmp_pattern_count_into_string(string s) {
  vector<ll> v(s.size(), 0);
  ll i = 0, j = 1;
  while (j < s.size()) {
    if (s[i] == s[j]) {
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

  // for (auto x : v) {
  //   cout << x << " ";
  // }
  // cout << endl;

  i = s.size() - 1;
  vector<ll> len;
  while (v[i] > 0) {
    len.emplace_back(v[i]);
    i = v[i] - 1;
  }
  sort(len.begin(), len.end());

  for (auto x : len)
    cout << x << " ";
  cout << endl;
}

int main() {
  ll n, ans, k, ind = 0;
  string s;
  cin >> s;

  kmp_pattern_count_into_string(s);

  return 0;
}
