#include <bits/stdc++.h>
using namespace std;

#define inf 1e5 + 7
vector<vector<int>> dp(501, vector<int>(501, -1));

int min_cut(int a, int b) {
  if (a == b)
    return 0;
  int min1, min2;
  min1 = min2 = inf;
  for (int k = 1; k <= max(a, b); k++) {
    if (a > k) {
      if (dp[a - k][b] == -1)
        dp[a - k][b] = min_cut(a - k, b);
      if (dp[k][b] == -1)
        dp[k][b] = min_cut(k, b);
      min1 = min(min1, 1 + dp[a - k][b] + dp[k][b]);
    }
    if (b > k) {
      if (dp[a][b - k] == -1)
        dp[a][b - k] = min_cut(a, b - k);
      if (dp[k][a] == -1)
        dp[k][a] = min_cut(k, a);
      min1 = min(min1, 1 + dp[a][b - k] + dp[k][a]);
    }
  }
  return min(min1, min2);
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << min_cut(a, b) << endl;
  return 0;
}
