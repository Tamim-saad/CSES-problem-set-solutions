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
set<ll> ans;
vector<vector<ll>> adj_list;

/**
 * @brief Depth-First Search (DFS) to find articulation points in a graph.
 *
 * This function performs a depth-first search (DFS) on a graph to identify
 * articulation points (or cut vertices). Articulation points are vertices
 * which, when removed, increase the number of connected components in the graph.
 *
 * @param curr The current vertex being explored.
 * @param parnt The parent vertex of the current vertex in the DFS tree.
 *
 * The function uses several global variables:
 * - vis: A vector to mark visited vertices.
 * - low: A vector to store the lowest discovery time reachable from the subtree rooted with the
 * vertex.
 * - explr: A vector to store the discovery times of visited vertices.
 * - timee: A global timer used to set discovery times.
 * - par: A vector to store the parent vertices in the DFS tree.
 * - adj_list: An adjacency list representing the graph.
 * - ans: A set to store the articulation points found.
 */

void dfs(ll curr, ll parnt) {
  if (vis[curr] == 1) return;
  low[curr] = explr[curr] = timee++;
  par[curr] = parnt;
  vis[curr] = 1;
  ll cnt = 0;

  for (ll neigh : adj_list[curr]) {
    if (neigh == par[curr]) continue;
    if (!vis[neigh]) {
      cnt++;
      dfs(neigh, curr);
      low[curr] = min(low[curr], low[neigh]);
      if (par[curr] == -1 && cnt > 1) {
        ans.insert(curr);
      }
      if (par[curr] != -1 && explr[curr] <= low[neigh]) {
        ans.insert(curr);
      }
    } else
      low[curr] = min(low[curr], explr[neigh]);
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

  dfs(1, -1);
  cout << ans.size() << endl;
  for (ll x : ans) {
    cout << x << " ";
  }
}