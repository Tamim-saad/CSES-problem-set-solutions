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

bool compare_pair(const std::pair<ll, ll> &a, const std::pair<ll, ll> &b) {
  if (a.first == b.first)
    return a.second > b.second; // For descending order of second element
  return a.first < b.first;     // For ascending order of first element
}

int main() {
  fast
  // init
  {
    // count++;
    ll i, j, k, x, y, z, p, q, m, n, l, r, l1, l2, r1, r2, ans, pos, flag, sum;
    ll mini = lmax, maxi = -1, piv, temp, part, low, high, rem, prev, now, mid,
       bit;
    ll dif = 0, change = 0, total = 0, same = 0, plus = 0, minus = 0, zero = 0;

    cin >> n >> k;

    // cout<<piv;

    // char ch, ch1, ch2, ch3, ch4;
    // string sarr[n];
    // string s, s1 = "", s2 = "";
    // string res1 = "", res2 = "", chk1 = "", chk2 = "", chk3 = "", chk4 = "",
    // pivs = "", rems = "";

    // n = s.size;

    // ll arr[n+1], number[n], cost[n], forsum[n+1], backsum[n];

    vector<ll> v, v1, v2, vans, vpos, vlen, vsum, vdif;
    // vector<tuple<ll,ll,ll>> vtup, vtup1, vtup2, vtup3;
    // vector <string> vstr(n);
    // vector<pair<ll, ll>> vpr, vpr1, vpr2, vpr3;
    // vector<vec> vdarr(n, vec(10, 0));
    // deque<ll> dq, dq1, dq2;

    // pair<ll, ll> pr, pr1, pr2,pr3, pr4;
    // set <ll> st, st1, st2, ms, ldiff, rdiff;
    // multiset <pair<ll,ll>> mst, mst1, mstans;
    // multiset<ll, greater<ll>> mst, mst1, mst2;
    // priority_queue<ll> pq, pq1, pq2;
    // stack<pair<ll,ll>> stck, stck1, stck2;
    // map<ll, ll> mp, mp1, mp2;
    // map<pair<ll,ll>,ll> mpair, mpair1, mpair2;
    // vector<pair<ll,ll>> vpr, vpr1, vpr2;
    // queue<ll> vq[10],vq1,vq2;

    // multiset<ll>::iterator itr, itr1, itr2;

    // Point pa,pb,pc,pd;//,pt[1001];
    // Node pa,pb,pt[n];

    // cout<<"-----------------yess"<<endl;

    ans = LONG_LONG_MAX;
    prev = -1;
    maxi = 0;
    // piv=0;
    // flag=0;
    // sum=0;
    // bit=1;

    forr(i, 0, n) {
      cin >> x;
      v.eb(x);
      maxi = max(maxi, x);
    }

    low = maxi;
    high = 1e15;
    sum = 0;

    while (low < high) {
      mid = (low + high) / 2;
      // cout<<low<<pll<<mid<<pll<<high<<endl;

      part = 1;
      sum = 0;

      forr(i, 0, n) {
        sum += v[i];
        if (sum > mid) {
          part++;
          sum = v[i];
        }
      }

      if (part <= k)
        high = mid;
      else
        low = mid + 1;
    }

    cout << low;
  }
}