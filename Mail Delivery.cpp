// Alhamdulillah

#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace __gnu_pbds;
#define ll long long

#define forr(i, a, b) for (ll i = a; i < b; i++)
#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);

typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_multiset;

vector<indexed_multiset> adj_list;
vector<ll> topoPath, visEdge;

void dfs(ll curr) {
  while (!adj_list[curr].empty()) {
    auto to = adj_list[curr].find_by_order(0);
    auto [eid, neigh] = *to;

    if (!visEdge[eid]) {
      visEdge[eid] = 1;
      adj_list[curr].erase(to);
      adj_list[neigh].erase({eid, curr});

      dfs(neigh);
    }
  }
  topoPath.emplace_back(curr);
}

int main() {
  fast;
  ll n, m, x, y, i, odd = 0;
  cin >> n >> m;

  adj_list.resize(n + 1);
  visEdge.resize(m + 1, 0);

  vector<ll> degree(n + 1, 0);

  for (i = 1; i <= m; i++) {
    cin >> x >> y;
    adj_list[x].insert({i, y});
    adj_list[y].insert({i, x});
    degree[x]++;
    degree[y]++;
  }

  forr(i, 1, n + 1) {
    if (degree[i] % 2) {
      // as starting and ending both at node 1, no odd degree is allowed,
      // when starting node != ending node, there are two odd degree node,
      // but in this case all node have even degree
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  }

  dfs(1);

  if (topoPath.size() != m + 1) {
    // check all edges are visited or stuck on a node without ending
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  reverse(topoPath.begin(), topoPath.end());
  for (auto x : topoPath) {
    cout << x << " ";
  }
}