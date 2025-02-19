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

/**
 * @brief Depth-First Search (DFS) to find bridges in a graph.
 *
 * This function performs a DFS traversal to find all the bridges in an undirected graph.
 * A bridge is an edge which, when removed, makes the graph disconnected.
 *
 * @param curr The current node being explored.
 * @param parnt The parent node of the current node.
 *
 * @details
 * - `vis` is a vector that keeps track of visited nodes.
 * - `low` is a vector that stores the lowest discovery time reachable from the subtree rooted with
 * the node.
 * - `explr` is a vector that stores the discovery times of visited nodes.
 * - `timee` is a global variable to keep track of the discovery time.
 * - `par` is a vector that stores the parent nodes in the DFS tree.
 * - `adj_list` is the adjacency list representing the graph.
 * - `ans` is a vector that stores the bridges found in the graph.
 *
 * The function updates the `low` and `explr` values for each node and checks if the current edge is
 * a bridge.
 */

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
      if (explr[curr] < low[neigh]) {
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