// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

int main() {
  int i, j, n;
  cin >> n;

  vector<int> v(n), ans;
  for (i = 0; i < n; i++)
    cin >> v[i];

  bitset<100007> dp;
  dp[0] = 1;

  for (int x : v)
    dp |= dp << x;

  for (i = 1; i < 100007; i++)
    if (dp[i])
      ans.emplace_back(i);
  cout << ans.size() << endl;
  for (auto x : ans)
    cout << x << " ";
}