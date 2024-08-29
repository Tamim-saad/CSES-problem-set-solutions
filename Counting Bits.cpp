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

#define sortArr(arr, n) sort(arr, arr + n);
#define sortvc(v) sort(v.begin(), v.end());
#define rev(v) reverse(v.begin(), v.end());
// #define find(v, x) find(v.begin(), v.end(), x);

ll binaryLength(ll n) {
  if (n == 0)
    return 0;
  return 64 - __builtin_clzll(n);
}

ll countAllSetBits(ll n) {
  ll total = 0;
  while (n >= 1) {
    ll len = binaryLength(n) - 1;

    ll piv = 1ll << len;
    total += len * (piv) / 2;
    n -= piv;
    total += n + 1;
  }
  return total;
}

int main() {
  fast
  // init
  {
    // count++;
    ll i, j, k, x, y, z, p, q, m, n, l, r, l1, l2, r1, r2, ans, pos, flag, sum;
    ll mini = lmax, maxi = -1, piv, low, high, rem, now, mid, bit;
    ll dif = 0, change = 0, total = 0, same = 0, plus = 0, minus = 0, zero = 0;

    // char ch, ch1, ch2, ch3, ch4;
    // string s, s1 = "", s2 = "";
    // string res1 = "", res2 = "", chk1 = "", chk2 = "", chk3 = "", chk4 = "",
    // pivs = "", rems = "";

    cin >> n;
    // n = s.size;

    // ll arr[k];
    // number[n], cost[n], forsum[n+1], backsum[n];

    // vector<ll> v, v1, v2, vans, vpos, vlen, vsum, vdif;
    // vector<pair<ll, ll>> vpr;
    // vector<vec> vdarr(n, vec(10, 0));

    // pair<ll, ll> pr, pr1, pr2,pr3, pr4;
    // set <ll> v, st, st1, st2, ms, ldiff, rdiff;
    // multiset <ll> v, st, st1, st2, ms, ldiff, rdiff;
    // priority_queue<ll> pq, pq1, pq2;
    // stack<ll> stck, stck1, stck2;
    // map<ll, ll> mp, mp1, mp2;
    // map<pair<ll,ll>,ll> mpair, mpair1, mpair2;
    // vector<pair<ll,ll>> vpr, vpr1, vpr2;
    // queue<ll> vq[10],vq1,vq2;

    // multiset<ll>::iterator itr, itr1, itr2;

    // Point pa,pb,pc,pd;//,pt[1001];
    // Node pa,pb,pt[n];

    // cout<<"-----------------yess"<<endl;

    ans = 0;
    // piv=0;
    // flag=0;
    // sum=0;
    // bit=1;

    // func(n);
    cout << countAllSetBits(n) << endl;

    // cout<<ans<<endl;
  }
}