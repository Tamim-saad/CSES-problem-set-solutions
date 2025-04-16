// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eb emplace_back

#define forr(i, a, b) for (ll i = a; i < b; i++)
#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);

const ll mod = 1e9 + 7;

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
    adj_list[x].eb(y);
  }

  dfs(1);

  if (vis[n] == 0) {
    cout << "0\n";
    return 0;
  }

  reverse(topoPath.begin(), topoPath.end());

  dist[topoPath[0]] = 1;

  for (auto i : topoPath) {
    for (auto x : adj_list[i]) {
      dist[x] = (dist[x] + dist[i]) % mod;
    }
  }

  cout << dist[n];
}