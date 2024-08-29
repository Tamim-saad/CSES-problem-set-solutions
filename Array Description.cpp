/// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define ll int
#define init                                                                   \
  ll count = 0, zz, t;                                                         \
  cin >> t;                                                                    \
  while (t--)
#define ld long double
#define ed "\n"
#define eb emplace_back
#define con continue
#define bre break
#define pl "  "
#define pll " --- "
#define size size()
#define mpr make_pair
#define vec vector<ll>
#define lmax LONG_LONG_MAX
#define lmin LONG_LONG_MIN
#define forr(i, a, b) for (ll i = a; i < b; i++)
#define forrev(i, a, b) for (ll i = a; i >= b; i--)
const ll mod = 1e9 + 7;

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
#define find(v, x) find(v.begin(), v.end(), x);

int main() {
  fast
  // init
  {
    // count++;
    ll i, j, k, x, y, z, p, q, m, n, l, r, l1, l2, r1, r2, ans, flag, sum;
    ll mini = lmax, maxi = -1, piv, piv1, piv2, low, high, rem, now, prev;
    ll dif = 0, change = 0, total = 0, same = 0, plus = 0, minus = 0, zero = 0;

    // char ch, ch1, ch2, ch3, ch4;
    // string sarr[n];
    // string s, s1 = "", s2 = "";
    // string res1 = "", res2 = "", chk1 = "", chk2 = "", chk3 = "", chk4 = "",
    // pivs = "", rems = "";

    cin >> n >> x;
    // n = s.size;

    // ll arr[n];
    // number[n], cost[n], forsum[n], backsum[n];

    // vector<ll> v, v1, v2, vans, vpos, vlen, vsum, vdif;

    vector<ll> v(n);
    vector<vec> dp(n + 1, vec(x + 1, 0));

    // vector<tuple<ll,ll,ll>> vtup, vtup1, vtup2, vtup3;
    // vector <string> vstr(n);
    // vector<pair<ll, ll>> vpr, vpr1, vpr2, vpr3;
    // vector<vec> vdarr(n, vec(10, 0));
    // deque<ll> dq, dq1, dq2;

    // pair<ll, ll> pr, pr1, pr2;
    // set<ll> st, st1, st2, ms, ldiff, rdiff;
    // multiset <ll> mst, mst1, mst2;
    // multiset<ll, greater<ll>> mst, mst1, mst2;
    // multiset <pair<ll,ll>> mst, mst1, mstans;
    // priority_queue<ll> pq, pq1, pq2;
    // stack<ll> stck, stck1, stck2;
    // map<int, ll> mp, mp1, mp2;
    // map<pair<ll,ll>,ll> mpair, mpair1, mpair2;
    // vector<pair<ll,ll>> vpr, vpr1, vpr2;
    // queue<ll> vq[10],vq1,vq2;

    // Point pa,pb,pt[n];
    // Node pa,pb,pt[n];

    // cout<<"-----------------yess"<<endl;

    ans = 0;
    // maxi = 0;

    forr(i, 0, n) {
      cin >> v[i];
      if (v[i] == 0)
        piv = i + 1;
    }

    forr(i, 1, n + 1) {
      if (i == 1) {
        if (v[i - 1] == 0)
          forr(j, 1, x + 1) dp[i][j] = 1;
        else
          dp[i][v[i - 1]] = 1;
      }

      else if (v[i - 1] == 0) {
        forr(j, 1, x + 1) {
          dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
          if (j != x)
            dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
        }
      } else {
        // dp[i][v[i-1]]+=dp[i-1][v[i-1]-1]+dp[i-1][v[i-1]];
        // dp[i][v[i-1]]+= (v[i-1]==x) ? 0 : dp[i-1][v[i-1]+1];
        dp[i][v[i - 1]] =
            (dp[i][v[i - 1]] + dp[i - 1][v[i - 1] - 1] + dp[i - 1][v[i - 1]]) %
            mod;
        if (v[i - 1] != x)
          dp[i][v[i - 1]] = (dp[i][v[i - 1]] + dp[i - 1][v[i - 1] + 1]) % mod;
      }
    }

    // cout<<dp[n][piv]<<endl;

    forr(i, 0, x + 1) { ans = (ans + dp[n][i]) % mod; }

    cout << ans << ed;
  }
}
