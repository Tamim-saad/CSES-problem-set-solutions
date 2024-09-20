#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll countSumSetSumEqualX(vector<ll> nums, ll k) {
  ll n = nums.size();
  vector<ll> v1(nums.begin(), nums.begin() + n / 2);
  vector<ll> v2(nums.begin() + n / 2, nums.end());
  vector<ll> first;
  vector<ll> second;

  for (ll i = 0; i < (1 << v1.size()); i++) {
    ll sum = 0;
    for (ll j = 0; j < v1.size(); j++) {
      if (i & (1 << j)) {
        sum += v1[j];
      }
    }
    first.push_back(sum);
  }
  for (ll i = 0; i < (1 << v2.size()); i++) {
    ll sum = 0;
    for (ll j = 0; j < v2.size(); j++) {
      if (i & (1 << j)) {
        sum += v2[j];
      }
    }
    second.push_back(sum);
  }
  ll ans = 0;

  sort(first.begin(), first.end());
  sort(second.begin(), second.end());

  for (ll i = 0; i < first.size() && first[i] <= k; i++) {
    ll ind2 = upper_bound(second.begin(), second.end(), k - first[i]) -
              second.begin();
    ll ind1 = lower_bound(second.begin(), second.end(), k - first[i]) -
              second.begin();
    ans += ind2 - ind1;
  }
  return ans;
}

int main() {
  ll i, j, k, x, y, n;

  cin >> n >> k;
  vector<ll> v, v2;

  for (ll i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
  cout << countSumSetSumEqualX(v, k) << endl;
}