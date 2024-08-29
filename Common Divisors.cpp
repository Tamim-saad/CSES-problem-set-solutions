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

#define srt(arr, n) sort(ara, ara + n);
#define srtvc(v) sort(v.begin(), v.end());
#define rev(v) reverse(v.begin(), v.end());
// #define find(v,x) find(v.begin(), v.end(),x);

// const
int N = 1e6 + 1;

int main() {
  fast
  //    init
  {
    // count++;
    ll i, j, x, y, z, d, p, q, g, m = 0, n = 0, rest = 0, k, ans = 1, flag = 1,
                                  sum = 0;
    ll piv = 0, piv1 = 21, piv2 = 21, rem = 0, change = 0, prev = -1, l = 0,
       r = 0, l1, l2, r1, r2, lval, rval, now = 0, mid;
    ll mini = lmax, maxi = -1, dif = 0, total = 0, same = 0, plus = 0,
       minus = 0, zero = 0;

    // string s, s1 = "", s2 = "", res1 = "", res2 = "", chk1 = "", chk2 = "",
    // chk3 = "", chk4 = ""; string pivs = "", rems = "";

    cin >> n;
    // n = s.size;

    // ll arr[n+1];
    //  ll number[n], cost[n], forsum[n], backsum[n];
    //  vector<vec> vdarr(n, vec(10, 0));

    // vector<ll> v, v1, v2, vans, vpos, vlen, vsum, vdif;
    // vector<pair<ll, ll>> vpr;

    // pair<ll, ll> pr, pr1, pr2;
    // set<ll> st, st1, st2, ms, ldiff, rdiff;
    // priority_queue<ll> pq, pq1, pq2;
    // stack<ll> stck, stck1, stck2;
    // map<int, int> mp;//, mp1, mp2, sizearr;
    // queue<ll> vq[10], vq1, vq2;
    // deque<ll> dq, dq1, dq2;

    // Point pa,pb,pt[n];
    // Node pa,pb,pt[n];

    vector<int> mp(N, 0);

    // cout<<"-----------------yess"<<endl;

    // cout<<LONG_MAX<<endl;
    //  cout<<(n|(n>>1))<<endl;
    //  return 0;

    forr(i, 0, n) {
      cin >> x;
      // arr[i]=x;

      maxi = max(maxi, x);

      mp[x]++;

      if (mp[x] > 1) {
        piv = max(x, piv);
      }
    }

    // maxi=100;
    N = maxi + 1;

    for (i = 2; i < N; i++) {
      for (j = i * 2; j < N; j += i) {
        if (mp[j] != 0) {
          mp[i] += mp[j];
          if (mp[i] > 1) {
            ans = i;
            j = N;
            // goto here;
          }
        }
      }
      // here:;
    }

    // forr(i,1,maxi+1)
    // {
    //     if(mp[i]>1)
    //     {
    //         ans=i;
    //     }
    // }

    // cin>>q;
    // while (q--)
    // {
    //     cin>>n;
    //     cout<<v[n]+1<<endl;
    // }

    // for(auto x:mp[])
    // {
    //     cout<<x<<endl;
    // }

    cout << max(ans, piv) << endl;
  }
}