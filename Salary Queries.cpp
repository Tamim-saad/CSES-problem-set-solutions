#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

// template <typename Key, typename Mapped, typename Compare, typename Tag,
//           typename Policy>
// class tree;

#define ll long long
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_multiset;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, ans, k, ind = 0;
  cin >> n >> k;
  ll x, y;

  indexed_multiset ms;
  vector<ll> v(n);

  for (ll i = 0; i < n; i++) {
    cin >> x;
    v[i] = x;
    ms.insert({x, i});
  }

  vector<ll> vans;
  char ch;

  for (ll i = 1; i <= k; i++) {
    cin >> ch;
    cin >> x >> y;
    if (ch == '!') {
      x--;
      ms.erase(ms.find({v[x], x}));
      ms.insert({y, x});
      v[x] = y;
    }
    if (ch == '?') {
      auto h = ms.upper_bound({y, LONG_LONG_MAX});
      auto l = ms.lower_bound({x, -1});
      ll high = h == ms.end() ? n : ms.order_of_key(*h);
      ll low = l == ms.end() ? n : ms.order_of_key(*l);
      ll ans = high - low;
      cout << ans << endl;
    }
  }

  return 0;
}
