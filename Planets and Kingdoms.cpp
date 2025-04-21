// Alhamdulillah

#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
using namespace std;
#define ll long long
#define eb emplace_back

#define forr(i, a, b) for (ll i = a; i < b; i++)
#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);

vector<vector<ll>> adj_list, adj_list2;
vector<ll> vis, topoPath, ans;

void dfs(ll curr, ll x = 0) {
  vis[curr] = 1;
  if (x) {
    ans[curr] = x;
  }

  for (ll neigh : adj_list[curr]) {
    if (!vis[neigh]) {
      dfs(neigh, x);
    }
  }
  if (!x)
    topoPath.emplace_back(curr);
}

int main() {
  fast;
  ll n, m, x, y, i;
  cin >> n >> m;

  vector<ll> par(n + 1), dist(n + 1), rooms(n + 1);
  adj_list.resize(n + 1);
  adj_list2.resize(n + 1);
  vis.resize(n + 1, 0);
  ans.resize(n + 1);

  for (i = 1; i <= m; i++) {
    cin >> x >> y;
    adj_list[x].emplace_back(y);
    adj_list2[y].emplace_back(x);
  }

  forr(i, 1, n + 1) {
    if (!vis[i])
      dfs(i);
  }

  reverse(topoPath.begin(), topoPath.end());
  fill(vis.begin(), vis.end(), 0);
  swap(adj_list, adj_list2);

  x = 0;
  for (auto i : topoPath) {
    if (!vis[i]) {
      x++;
      dfs(i, x);
    }
  }

  cout << x << endl;
  forr(i, 1, n + 1) { cout << ans[i] << " "; }
}