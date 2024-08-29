// /// say Alhamdulillah

// #include <bits/stdc++.h>
// using namespace std;

// #define fast                      \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(0);
//     // cout.tie(0);
// #define ll long long
// // #define init             \
// //     ll count = 0, zz, t; \
// //     cin >> t;            \
// //     while (t--)
// #define ld long double
// #define ed "\n"
// #define eb emplace_back
// #define con continue
// #define bre break
// #define pl " "
// #define pll " --- "
// // #define size size()
// #define mpr make_pair
// #define vec vector<ll>
// #define lmax LONG_LONG_MAX
// #define lmin LONG_LONG_MIN
// #define forr(i, a, b) for (ll i = a; i < b; i++)
// #define forrev(i, a, b) for (ll i = a; i >= b; i--)

// // #define v.all v.begin(), v.end()

// #define printArrWhole(arr, n) \
//     for (ll i = 0; i < n; i++) \
//             cout << arr[i] << " ";   \
//     cout << endl;

// #define printArrLim(arr, in, n)  \
//     for (ll i = in; i <= n; i++) \
//         cout << arr[i] << " ";   \
//     cout << endl;

// #define printYesNo(flag) \
//     if (flag == 0)       \
//         cout << "NO";    \
//     else                 \
//         cout << "YES";   \
//     cout << endl;

// #define printvcWhole(vc)  \
//     for (auto x : vc)     \
//         cout << x << " "; \
//     cout << endl;

// #define printvcLim(vc, in, n)    \
//     for (ll i = in; i <= n; i++) \
//         cout << vc[i] << " ";    \
//     cout << endl;

// #define printdqWhole(dq)  \
//     for (auto x : dq)     \
//         cout << x << " "; \
//     cout << endl;

// #define printdqLim(dq, in, n)    \
//     for (ll i = in; i <= n; i++) \
//         cout << dq[i] << " ";    \
//     cout << endl;

// #define sortArr(arr, n) sort(arr, arr + n);
// #define sortvc(v) sort(v.begin(), v.end());
// #define rev(v) reverse(v.begin(), v.end());
// // #define find(v, x) find(v.begin(), v.end(), x);

// const ll N=200000+5;
// vector <vec> adj_list(N);
// map <ll,ll> vis;
// map<ll,ll> inDegree;
// // priority queue<ll> gpq;
// priority_queue<ll, vector<ll>, greater<ll> >gpq;
// vec gvans;

// void topologicalSort_KahnAlgo(ll n,ll m)
// {
//     forr(i,1,n+1)
//     {
//         if(inDegree[i]==0)
//         {
//             gpq.push(i);
//         }
//     }

//     while(!gpq.empty())
//     {
//         ll curr = gpq.top();
//         gpq.pop();
//         gvans.eb(curr);

//         for(auto &neighbour : adj_list[curr])
//         {
//             inDegree[neighbour]--;
//             if(inDegree[neighbour] == 0)   gpq.push(neighbour);
//         }
//     }

//     printvcWhole(gvans);
// }

// int main()
// {
//     fast
//     // init
//     {
//         // count++;
//         ll i, j, k, x, y, z, p, q, m, n, l, r,  l1, l2, r1, r2, ans, pos,
//         flag, sum ; ll mini = lmax, maxi = -1, piv, low, high, rem, now, mid,
//         bit; ll  dif = 0, change = 0, total = 0, same = 0, plus = 0, minus =
//         0, zero = 0;

//         cin>>n>>m;

//         // char ch, ch1, ch2, ch3, ch4;
//         // string sarr[n];
//         //string s, s1 = "", s2 = "";
//         // string res1 = "", res2 = "", chk1 = "", chk2 = "", chk3 = "", chk4
//         = "", pivs = "", rems = "";

//         // n = s.size;

//         // ll arr[n];
//         // number[n], cost[n], forsum[n+1], backsum[n];

//         // vector<ll> v, v1, v2, vans, vpos, vlen, vsum, vdif;
//         // vector <string> vstr(n);
//         // vector<pair<ll, ll>> vpr;
//         // vector<vec> vdarr(n, vec(10, 0));
//         // deque<ll> dq, dq1, dq2;

//         // pair<ll, ll> pr, pr1, pr2,pr3, pr4;
//         // set <ll> v, st, st1, st2, ms, ldiff, rdiff;
//         // multiset <ll> mst, mst1, mst2;
//         // priority_queue<ll> pq, pq1, pq2;
//         // stack<ll> stck, stck1, stck2;
//         // map<ll, ll> mp, mp1, mp2;
//         // map<pair<ll,ll>,ll> mpair, mpair1, mpair2;
//         // vector<pair<ll,ll>> vpr, vpr1, vpr2;
//         // queue<ll> vq[10],vq1,vq2;

//         // multiset<ll>::iterator itr, itr1, itr2;

//         // Point pa,pb,pc,pd;//,pt[1001];
//         // Node pa,pb,pt[n];

//         // cout<<"-----------------yess"<<endl;

//         ans=0;
//         // piv=0;
//         // flag=0;
//         // sum=0;
//         // bit=1;

//         // func(n);

//         forr(i,1,m+1)
//         {
//             cin>>x>>y;
//             // par[y]=x;

//             adj_list[x].eb(y);
//             inDegree[y]++;
//         }

//         topologicalSort_KahnAlgo(n,m);

//     }

// }

// ///////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi topo_sort(const vector<vi> &gr) {
  vi indeg(sz(gr)), ret;
  trav(li, gr) trav(x, li) indeg[x]++;
  priority_queue<int> q;
  rep(i, 0, sz(gr)) if (indeg[i] == 0) q.push(i);
  while (!q.empty()) {
    int i = q.top();
    ret.push_back(i);
    q.pop();
    trav(x, gr[i]) if (--indeg[x] == 0) q.push(x);
  }
  return ret;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);

  int n, m;
  cin >> n >> m;
  vector<vi> g(n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    g[b - 1].push_back(a - 1);
  }
  vi r = topo_sort(g);
  rep(i, 0, n) cout << r[n - 1 - i] + 1 << " \n"[i == n - 1];
  return 0;
}