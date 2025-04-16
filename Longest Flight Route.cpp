// say Alhamdulillah

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eb emplace_back

#define forr(i, a, b) for (ll i = a; i < b; i++)
#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);

vector<vector<ll>> adj_list;
vector<ll> vis, topoPath;

void dfs(ll curr) {
  vis[curr] = 1;
  
  for (ll neigh : adj_list[curr]) {
    if (!vis[neigh]) {
      dfs(neigh);
    }
  }
  topoPath.emplace_back(curr);
}

int main() {
  fast;
  ll n, m, x, y, i;
  cin >> n >> m;

  vector<ll> par(n + 1), dist(n + 1), ans;
  adj_list.resize(n + 1);
  vis.resize(n + 1, 0);

  for (i = 1; i <= m; i++) {
    cin >> x >> y;
    adj_list[x].emplace_back(y);
  }

  dfs(1);

  if (vis[n] == 0) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  reverse(topoPath.begin(),topoPath.end());

  for (auto i : topoPath) {
    for (auto x : adj_list[i]) {
      if (dist[i] + 1 > dist[x]) {
        dist[x] = dist[i] + 1;
        par[x] = i;
      }
    }
  }

  x = n;
  while (x != 0) {
    ans.eb(x);
    x = par[x];
  }

  reverse(ans.begin(), ans.end());
  cout << ans.size() << endl;

  for (auto x : ans) {
    cout << x << " ";
  }
}