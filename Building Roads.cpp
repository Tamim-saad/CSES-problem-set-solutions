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

const ll N = 1e5 + 7;
const ll INF = 2e5 + 5;

vector<vector<ll>> adj_list(N);
deque<ll> gdeq;

map<ll, bool> vis;

ll gans = 0;

void dfs_On_Grid(ll curr) {
  vis[curr] = true;

  forr(i, 0, adj_list[curr].size) {
    if (!vis[adj_list[curr][i]] && curr != adj_list[curr][i]) {
      dfs_On_Grid(adj_list[curr][i]);
    }
  }
  return;
}

void connected_Components_On_Grid(ll n) {
  forr(i, 1, n + 1) {
    // forr(j,0,adj_list[i].size)
    // {
    if (!vis[i]) {
      gdeq.eb(i);
      dfs_On_Grid(i);
      // gans++;
    }
    // }
  }
}

int main() {
  // fast
  // init
  {
    // count++;
    ll i, j, k, x, y, z, p, q, r, m, n, l, l1, l2, r1, r2, ans, flag, sum;
    ll mini = lmax, maxi = -1, piv, piv1, piv2, rem, now, mid;
    // ll  dif = 0, change = 0, total = 0, same = 0, plus = 0, minus = 0, zero =
    // 0;

    // string s[1001], s1 = "", s2 = "";
    // string res1 = "", res2 = "", chk1 = "", chk2 = "", chk3 = "", chk4 = "",
    // pivs = "", rems = "";

    cin >> n >> m;
    // n = s.size;

    // ll arr[n];
    // number[n], cost[n], forsum[n], backsum[n];

    // vector<ll> v, v1, v2, vans, vpos, vlen, vsum, vdif;
    // vector<pair<ll, ll>> vpr;
    // vector<vec> vdarr(n, vec(10, 0));

    // pair<ll, ll> pr, pr1, pr2;
    // set<ll> st, st1, st2, ms, ldiff, rdiff;
    // priority_queue<ll> pq, pq1, pq2;
    // stack<ll> stck, stck1, stck2;
    // map<int, ll> mp, mp1, mp2;
    // queue<ll> vq[10],vq1,vq2;

    // Point pa,pb,pt[n];
    // Node pa,pb,pt[n];

    // cout<<"-----------------yess"<<endl;

    ans = 0;
    piv = 0;
    flag = 0;
    sum = 0;

    // vis.resize(n);

    // forr(i,0,n)
    // {
    //     vis[i].resize(m);
    // }

    forr(i, 0, m) {
      ll u, v;
      cin >> u >> v;

      adj_list[u].eb(v);
      adj_list[v].eb(u);
    }

    // cout<<LONG_MAX<<endl;
    //  cout<<(n|(n>>1))<<endl;
    //  return 0;

    // forr(i,0,n)
    // {
    //     cin>>s[i];
    // }

    connected_Components_On_Grid(n);

    cout << gdeq.size - 1 << endl;

    // cout<<gdeq.front()<<pl;
    // gdeq.pop_front();
    while (gdeq.size > 1) {
      cout << gdeq.front() << pl;
      gdeq.pop_front();
      cout << gdeq.front() << pl;
      // gdeq.pop_front();
    }
    // ans = 0;
  }
}