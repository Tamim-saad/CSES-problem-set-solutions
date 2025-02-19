// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                    \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

ll timee = 0;
vector<ll> par, vis, low, explr;
vector<pair<ll, ll>> ans;
vector<vector<ll>> adj_list;

void dfs(ll curr, ll parnt) {
  if (vis[curr] == 1) return;
  low[curr] = explr[curr] = timee++;
  par[curr] = parnt;
  vis[curr] = 1;

  for (ll neigh : adj_list[curr]) {
    if (neigh == par[curr]) continue;
    if (!vis[neigh]) {
      dfs(neigh, curr);
      low[curr] = min(low[curr], low[neigh]);
      if (low[neigh] > explr[curr]) {
        ans.push_back({neigh, curr});
      }
    } else {
      low[curr] = min(low[curr], explr[neigh]);
    }
  }
}

int main() {
  fast;
  ll n, m, x, y, i;
  cin >> n >> m;

  low.resize(n + 1, LONG_LONG_MAX);
  par.resize(n + 1, -1);
  vis.resize(n + 1, 0);
  explr.resize(n + 1, 0);
  adj_list.resize(n + 1);

  for (i = 1; i <= m; i++) {
    cin >> x >> y;
    adj_list[x].emplace_back(y);
    adj_list[y].emplace_back(x);
  }

  dfs(1, 1);
  cout << ans.size() << endl;
  for (auto x : ans) {
    cout << x.first << " " << x.second << endl;
  }
}