/// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

#define fast                                                                   \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);
// cout.tie(0);
#define ll long long
// #define init             \
//     ll count = 0, zz, t; \
//     cin >> t;            \
//     while (t--)
#define ld long double
#define ed "\n"
#define eb emplace_back
#define con continue
#define bre break
#define pl " "
#define pll " --- "
// #define size size()
#define mpr make_pair
#define vec vector<ll>
#define lmax LONG_LONG_MAX
#define lmin LONG_LONG_MIN
#define forr(i, a, b) for (ll i = a; i < b; i++)
#define forrev(i, a, b) for (ll i = a; i >= b; i--)

// #define v.all v.begin(), v.end()

#define printArrWhole(arr, n)                                                  \
  for (ll i = 0; i < n; i++)                                                   \
    cout << arr[i] << " ";                                                     \
  cout << endl;

#define printArrLim(arr, in, n)                                                \
  for (ll i = in; i <= n; i++)                                                 \
    cout << arr[i] << " ";                                                     \
  cout << endl;

#define printYesNo(flag)                                                       \
  if (flag == 0)                                                               \
    cout << "NO";                                                              \
  else                                                                         \
    cout << "YES";                                                             \
  cout << endl;

#define printvcWhole(vc)                                                       \
  for (auto x : vc)                                                            \
    cout << x << " ";                                                          \
  cout << endl;

#define printvcLim(vc, in, n)                                                  \
  for (ll i = in; i <= n; i++)                                                 \
    cout << vc[i] << " ";                                                      \
  cout << endl;

#define printdqWhole(dq)                                                       \
  for (auto x : dq)                                                            \
    cout << x << " ";                                                          \
  cout << endl;

#define printdqLim(dq, in, n)                                                  \
  for (ll i = in; i <= n; i++)                                                 \
    cout << dq[i] << " ";                                                      \
  cout << endl;

#define sortArr(arr, n) sort(arr, arr + n);
#define sortvc(v) sort(v.begin(), v.end());
#define rev(v) reverse(v.begin(), v.end());
// #define find(v, x) find(v.begin(), v.end(), x);

int main() {
  ll n, ans, k, x;
  cin >> n >> k;

  vector<ll> v;
  for (ll i = 1; i <= n; i++) {
    cin >> x;
    v.eb(x);
  }

  map<ll, pair<ll, ll>> mp;

  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      auto it = mp.find(k - v[i] - v[j]);
      if (it != mp.end()) {
        if (it->second.first != i && it->second.second != i &&
            it->second.first != j && it->second.second != j && i != j &&
            it->second.first != it->second.second) {

          cout << i + 1 << " " << j + 1 << " " << it->second.first + 1 << "  "
               << it->second.second + 1 << endl;
          return 0;
        }
      }
      mp[v[i] + v[j]] = make_pair(i, j);
    }
  }
  cout << "IMPOSSIBLE\n ";

  return 0;
}