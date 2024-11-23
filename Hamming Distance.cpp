// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, x, ans;
  string s;
  cin >> n >> ans;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    v.emplace_back(stoi(s, nullptr, 2));
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++)
      ans = min(ans, __builtin_popcount(v[i] ^ v[j]));
  }
  cout << ans;
  return 0;
}