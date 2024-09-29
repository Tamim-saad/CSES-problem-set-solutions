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
  cin >> n >> k;

  indexed_multiset ms;

  vector<ll> v, nums;
  for (ll i = 1; i <= n; i++) {
    int x;
    cin >> x;
    nums.emplace_back(x);
    if (i <= k) {
      ms.insert({x, ind++});
    }
  }

  vector<ll> vans(n - k + 1);

  vans[0] = ms.find_by_order((k - 1) / 2)->first;
  for (ll i = k; i < n; i++) {
    ms.erase({nums[i - k], i - k});
    ms.insert({nums[i], ind++});

    // for (auto x : ms) {
    // cout << x.first << " ";
    // }
    // cout << endl;

    vans[i - k + 1] = ms.find_by_order((k - 1) / 2)->first;
  }

  // cout << " ---- " << endl;

  for (auto x : vans)
    cout << x << " ";

  return 0;
}
