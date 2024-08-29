/// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

const int gMOD = 1e9 + 7;

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
#define pl "  "
#define size size()
#define mpr make_pair
#define vec vector<ll>
#define lmax LONG_LONG_MAX
#define lmin LONG_LONG_MIN
#define forr(i, a, b) for (ll i = a; i < b; i++)
#define forrev(i, a, b) for (ll i = a; i >= b; i--)

// #define v.all v.begin(),v.end()
#define printarr(arr, in, n)                                                   \
  cout << ed;                                                                  \
  for (ll i = in; i < n; i++)                                                  \
    cout << arr[i] << " ";                                                     \
  cout << ed;
#define print(arr, n)                                                          \
  cout << ed;                                                                  \
  for (ll i = 0; i < n; i++)                                                   \
    cout << arr[i] << " ";                                                     \
  cout << ed;
#define printyn(flag)                                                          \
  if (flag == 0)                                                               \
    cout << "NO\n";                                                            \
  else                                                                         \
    cout << "YES\n";

#define printvc(vc)                                                            \
  cout << ed;                                                                  \
  for (auto x : vc)                                                            \
    cout << x << " ";                                                          \
  cout << ed;
// #define printvc(vc)  for(auto x:vc)cout<<x<<".";
// #define printvc(vc,in,n)  cout<<ed;for(ll i=in;i<n;i++)cout<<arr[i]<<"
// ";cout<<ed;

#define sortt(arr, n) sort(arr, arr + n);
#define sorttvc(v) sort(v.begin(), v.end());
#define rev(v) reverse(v.begin(), v.end());
// #define find(v,x) find(v.begin(), v.end(),x);

// string binary = bitset<32>(n).to_string();
//  unsigned long decimal =bitset<8>(binary).to_ulong();

ll recurr(ll a, ll b, ll MOD) {
  if (b == 1)
    return a % MOD;
  else if (b == 0)
    return 1;
  else {
    if (b % 2 == 0) {
      ll x = recurr(a, b / 2, MOD);
      return (x * x) % MOD;
    } else {
      ll x = recurr(a, b / 2, MOD);
      return ((x * x) % MOD * a) % MOD;
    }
  }
}

int main() {
  //    fast
  init {
    count++;
    ll i, j, x, y, z, d, p, q, g, m = 0, n = 0, rest = 0, k, ans = 0, flag = 1,
                                  sum = 0, bef_even_pos = 0, bef_odd_pos = 0;
    ll mini = lmax, maxi = -1, dif = 0, total = 0, same = 0, plus = 0,
       minus = 0, zero = 0;
    ll piv = 0, piv1 = 21, piv2 = 21, rem = 0, fix = 0, flex = 0, change = 0,
       prev = -1, l = 0, r = 0, l1, l2, r1, r2, lval, rval, now = 0, mid;

    // string s, s1 = "", s2 = "", res1 = "", res2 = "", chk1 = "", chk2 = "",
    // chk3 = "", chk4 = ""; string pivs = "", rems = "";

    // cin >> n ;
    // n = s.size;

    ll arr[n];
    // ll number[n], cost[n], forsum[n], backsum[n];
    // vector<vec> vdarr(n, vec(10, 0));

    vector<ll> v, v1, v2, vans, vpos, vlen, vsum, vdif;
    vector<pair<ll, ll>> vpr;

    pair<ll, ll> pr, pr1, pr2;
    set<ll> st, st1, st2, ms, ldiff, rdiff;
    priority_queue<ll> pq, pq1, pq2;
    stack<ll> stck, stck1, stck2;
    map<ll, ll> mp, mp1, mp2, sizearr;
    queue<ll> vq[10], vq1, vq2;
    deque<ll> dq, dq1, dq2;

    // Point pa,pb,pt[n];
    // Node pa,pb,pt[n];

    // cout<<"-----------------yess"<<endl;

    // string binary = bitset<>(n).to_string();
    // reverse(binary.begin(), binary.end());

    // cout<<binary<<endl;

    // cout<<LONG_MAX<<endl;
    //  cout<<(n|(n>>1))<<endl;
    //  return 0;

    // forr(i,0,n)
    {
      cin >> x >> y >> z;
      y = recurr(y, z, gMOD - 1);
      cout << recurr(x, y, gMOD) << endl;
    }
  }

  // cout<<ans<<endl;
  // ans = 0;
}