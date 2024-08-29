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
#define size size()
#define mpr make_pair
#define vec vector<ll>
#define lmax LONG_LONG_MAX
#define lmin LONG_LONG_MIN
#define forr(i, a, b) for (ll i = a; i < b; i++)
#define forrev(i, a, b) for (ll i = a; i >= b; i--)

// #define v.all v.begin(),v.end()
// #define printarr(arr,in,n) cout<<ed;for(ll i=in;i<n;i++)cout<<arr[i]<<"
// ";cout<<ed;
#define print(arr, n)                                                          \
  cout << ed;                                                                  \
  for (ll i = 0; i < n; i++)                                                   \
    cout << arr[i] << " ";                                                     \
  cout << ed;
// #define printvc(vc)  cout<<ed;for(auto x:vc)cout<<x<<" ";cout<<ed;
#define printvc(vc)                                                            \
  for (auto x : vc)                                                            \
    cout << x << ".";
// #define printvc(vc,in,n)  cout<<ed;for(ll i=in;i<n;i++)cout<<arr[i]<<"
// ";cout<<ed;

#define srt(arr, n) sort(ara, ara + n);
#define srtvc(v) sort(v.begin(), v.end());
#define rev(v) reverse(v.begin(), v.end());
#define find(v, x) find(v.begin(), v.end(), x);

/// solve starts here--------------------------------

const ll N = 2e5 + 5;
vector<vec> adj_list(N);
map<ll, ll> color;
map<ll, ll> vis;
ll flag = 1;

void dfs(ll curr) {
  // if(!flag) return;
  vis[curr] = 1;

  forr(i, 0, adj_list[curr].size) {
    if (!vis[adj_list[curr][i]]) {
      color[adj_list[curr][i]] = color[curr] ^ 1;
      dfs(adj_list[curr][i]);
    } else if (color[adj_list[curr][i]] == color[curr]) {
      flag = 0;
      // return;
    }
  }
  return;
}

int main() {
  fast
  // init
  {
    // cout<<"-----------------yess"<<ed;
    ll count = 0;
    ll i, j, x, y, d, p, q, n = 0, m = 0, rest = 0, k, ans = 0, sum = 0,
                            even = 0, odd = 0;
    ll mini = lmax, maxi = -1, dif = 0, total = 0, same = 0, plus = 0,
       minus = 0, zero = 0;
    ll piv = 1, rem = 0, fix = 0, flex = 0, change = 0, prev = -1, l = 0, r = 0,
       lval, rval, now = 0, mid;

    cin >> n >> m;
    // n=s.size();
    ll arr[n + 1], arr1[n], arr2[n], forsum[n], backsum[n];

    string s, s1 = "", s2 = "", res1 = "", res2 = "", chk1 = "", chk2 = "",
              chk3 = "", chk4 = "";
    string pivs = "", rems = "";

    vec v, v1, v2, vans, vpos, vlen, vsum, vdif;
    vector<pair<ll, ll>> vp;

    pair<ll, ll> pr, pr1, pr2;
    set<ll> st, st1, st2, ms, ldiff, rdiff;
    priority_queue<ll> pq, pq1, pq2;
    stack<ll> stck, stck1, stck2;
    map<ll, ll> mp, mplen, mp2, mppos;

    // Point pa,pb,pt[n];

    // cout<<"---------------------------------------------yess"<<ed;

    forr(i, 1, m + 1) {
      cin >> x >> y;
      // arr[i]=x;

      // par[i]=x;

      adj_list[x].eb(y);
      adj_list[y].eb(x);
    }

    forr(i, 1, n + 1) {
      if (!vis[i])
        dfs(i);
    }

    if (flag == 0) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    } else {
      forr(i, 1, n + 1) { cout << color[i] + 1 << pl; }
      cout << endl;
    }

    ////        forr(i,1,n+1)
    ////        {
    ////            sort(adj_list[i].begin(),adj_list[i].end());
    ////            //srtvc(adj_list[i]);
    ////        }
  }
}