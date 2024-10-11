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
  ll n, ans, k, ind = 0;
  cin >> n;
  ll x;

  indexed_multiset ms;

  for (ll i = 1; i <= n; i++) {
    cin >> x;
    ms.insert({ind++, x});
  }

  vector<ll> vans;

  for (ll i = 1; i <= n; i++) {
    cin >> x;
    auto it = ms.find_by_order(x - 1);
    vans.push_back(it->second);
    ms.erase(it);
  }

  for (auto x : vans)
    cout << x << " ";

  return 0;
}
