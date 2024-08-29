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
#define endl "\n"
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
map<ll, ll> par;
ll gflag = 1;

vec gans;

ll gv[N];
int timee = 0;

stack<ll> gst;

void bfs(ll curr) {
  queue<ll> que;
  que.push(curr);

  while (que.empty() == false) {
    curr = que.front();
    que.pop();

    forr(i, 0, adj_list[curr].size) {
      if (!vis[adj_list[curr][i]]) {
        vis[adj_list[curr][i]] = 1;
        par[adj_list[curr][i]] = curr;
        que.push(adj_list[curr][i]);
      }

      // if(adj_list[curr][i]==n)
    }
  }
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
    // ll arr[n+1],arr1[n],arr2[n],forsum[n],backsum[n];

    string s = "", s1 = "", s2 = "", res1 = "", res2 = "", chk1 = "", chk2 = "",
           chk3 = "", chk4 = "";
    string pivs = "", rems = "";

    vector<ll> v;

    // Point pa,pb,pt[n];

    // cout<<"---------------------------------------------yess"<<ed;

    forr(i, 1, m + 1) {
      cin >> x >> y;
      // arr[i]=x;

      // par[i]=x;

      adj_list[x].eb(y);
      adj_list[y].eb(x);
    }

    bfs(1);

    // cout<<"--------yess"<<ed;

    if (!vis[n]) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      ll child = n;
      ans = 0;

      // ans++;
      // s=to_string(child);

      while (child != 1) {
        ans++;
        v.push_back(child);
        // s=to_string(child)+" "+s;
        // cout<<child<<endl;
        child = par[child];
      }
      ans++;
      v.push_back(child);
      // s=to_string(child)+" "+s;

      cout << ans << endl; //<<s<<endl;

      for (i = v.size - 1; i >= 0; i--) {
        cout << v[i] << " ";
      }
    }

    //    forr(i,1,n+1)
    //    {
    //        //sort(adj_list[i].begin(),adj_list[i].end());
    //        //srtvc(adj_list[i]);
    //        cout<<i<<" --- "<<par[i]<<ed;
    //    }
  }
}