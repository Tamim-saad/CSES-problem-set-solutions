#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

  ll n, ans;
  cin >> n;

  for (ll i = 1; i <= n; i++) {
    ans = (i * i * i * i - i * i) / 2 - 4 * (i - 1) * (i - 2);
    cout << ans << endl;
  }
  return 0;
}
