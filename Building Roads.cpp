/// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

#define fast                    \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

#define ll long long
#define eb emplace_back
#define forr(i, a, b) for (ll i = a; i < b; i++)

const ll N = 1e5 + 7;
vector<vector<ll>> adj_list(N);
deque<ll> gdeq;
map<ll, bool> vis;

ll gans = 0;

void dfs_On_Grid(ll curr) {
  vis[curr] = true;

  forr(i, 0, adj_list[curr].size()) {
    if (!vis[adj_list[curr][i]] && curr != adj_list[curr][i]) {
      dfs_On_Grid(adj_list[curr][i]);
    }
  }
  return;
}

void connected_Components_On_Grid(ll n) {
  forr(i, 1, n + 1) {
    if (!vis[i]) {
      gdeq.eb(i);
      dfs_On_Grid(i);
    }
  }
}

/**
 * @brief Main function to read input, process the graph, and output the result.
 *
 * This function performs the following steps:
 * 1. Reads the number of nodes (n) and edges (m) from the input.
 * 2. Reads the edges and constructs the adjacency list for the graph.
 * 3. Calls the function to find connected components in the graph.
 * 4. Outputs the number of additional roads needed to connect all components.
 * 5. Outputs the pairs of nodes that need to be connected to achieve this.
 *
 * @return int Exit status of the program.
 */
int main() {
  fast;
  ll i, m, n;
  cin >> n >> m;

  forr(i, 0, m) {
    ll u, v;
    cin >> u >> v;
    adj_list[u].eb(v);
    adj_list[v].eb(u);
  }

  connected_Components_On_Grid(n);
  cout << gdeq.size() - 1 << endl;

  while (gdeq.size() > 1) {
    cout << gdeq.front() << " ";
    gdeq.pop_front();
    cout << gdeq.front() << " ";
  }
}