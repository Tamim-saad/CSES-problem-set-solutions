/// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define ll long long
#define init                                                                   \
  ll count = 0, zz, t;                                                         \
  cin >> t;                                                                    \
  while (t--)
#define ld long double
#define ed "\n"
#define eb emplace_back
#define con continue
#define bre break
#define pl " "
#define pll " --- "
#define size size()
#define mpr make_pair
#define vec vector<ll>
#define lmax LONG_LONG_MAX
#define lmin LONG_LONG_MIN
#define forr(i, a, b) for (ll i = a; i < b; i++)
#define forrev(i, a, b) for (ll i = a; i >= b; i--)

// #define v.all v.begin(), v.end()

#define printArrWhole(arr, n) for (ll i = 0; i < n; i++)

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
#define find(v, x) find(v.begin(), v.end(), x);

ll largest_subArray_sum(ll l, ll h, vec arr) {
  ll maxi = INT_MIN, sum = 0;
  ll n = h - l + 1;

  for (ll i = 0; i < n; i++) {
    sum += arr[i];
    maxi = max(maxi, sum);
    if (sum <= 0)
      sum = 0;
  }

  return maxi;
}

int main() {
  fast
  // init
  {
    // count++;
    ll i, j, k, x, y, z, p, q, m, n, l, r, l1, l2, r1, r2, ans, flag, sum;
    ll mini = lmax, maxi = -1, piv, piv1, piv2, rem, now, mid, bit;
    ll dif = 0, change = 0, total = 0, same = 0, plus = 0, minus = 0, zero = 0;

    // char ch, ch1, ch2, ch3, ch4;
    // string s, s1 = "", s2 = "";
    // string res1 = "", res2 = "", chk1 = "", chk2 = "", chk3 = "", chk4 = "",
    // pivs = "", rems = "";

    cin >> n;
    // n = s.size;

    // ll arr[n];
    // number[n], cost[n], forsum[n], backsum[n];

    vector<ll> v, v1, v2, vans, vpos, vlen, vsum, vdif;
    // vector<pair<ll, ll>> vpr;
    // vector<vec> vdarr(n, vec(10, 0));

    // pair<ll, ll> pr, pr1, pr2;
    // set<ll> st, st1, st2, ms, ldiff, rdiff;
    // priority_queue<ll> pq, pq1, pq2;
    // stack<ll> stck, stck1, stck2;
    map<ll, ll> mp, mp1, mp2;
    // queue<ll> vq[10],vq1,vq2;

    // Point pa,pb,pc,pd;//,pt[1001];
    // Node pa,pb,pt[n];

    // cout<<"-----------------yess"<<endl;

    ans = 0;
    // piv=0;
    flag = 0;
    sum = 0;
    // bit=1;

    forr(i, 0, n) {
      cin >> x;
      v.eb(x);

      // if(mp[k-x] && !flag)
      // {
      //     cout<<mp2[k-x]<<pl<<i+1<<endl;
      //     flag=1;
      // }

      // mp[x]=1;
      // mp2[x]=i+1;
    }

    cout << largest_subArray_sum(0, n - 1, v) << endl;

    // if(!flag) cout<<"IMPOSSIBLE"<<endl;

    // cout<<ans<<ed;
  }
}