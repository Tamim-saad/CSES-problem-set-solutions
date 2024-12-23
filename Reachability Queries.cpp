#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);

const ll N = 50001;
vector<vector<ll>> adj_list(N), adj_list_rev(N);
vector<ll> vis(N, 0);
vector<ll> order, sccNo(N, -1);
vector<vector<ll>> densed;

void dfs(ll curr) {
  vis[curr] = 1;

  for (auto neigh : adj_list[curr])
    if (!vis[neigh])
      dfs(neigh);

  order.emplace_back(curr);
}

void dfs2(ll curr, ll no) {
  sccNo[curr] = no;

  for (auto neigh : adj_list_rev[curr])
    if (sccNo[neigh] == -1)
      dfs2(neigh, no);
}

vector<bitset<N>> dp;

bitset<N> dfs3(ll curr) {
  vis[curr] = 1;
  dp[curr].set(curr);

  for (auto neigh : densed[curr]) {
    if (!vis[neigh])
      dfs3(neigh);
    dp[curr] |= dp[neigh];
  }
  return dp[curr];
}

int main() {
  fast;
  ll n, m, x, q, y, i;
  cin >> n >> m >> q;

  for (i = 1; i <= m; i++) {
    cin >> x >> y;
    adj_list[x].emplace_back(y);
    adj_list_rev[y].emplace_back(x);
  }

  for (i = 1; i <= n; i++)
    if (!vis[i])
      dfs(i);

  fill(vis.begin(), vis.end(), 0);
  ll sccSize = 0;
  densed.resize(n + 1);

  for (i = order.size(); i >= 0; i--)
    if (sccNo[order[i]] == -1) {
      dfs2(order[i], sccSize);
      sccSize++;
    }

  densed.resize(sccSize);
  dp.resize(sccSize);
  vector<set<ll>> un_edges(sccSize, set<ll>());

  for (i = 1; i <= n; i++)
    for (auto x : adj_list[i])
      if (sccNo[i] != sccNo[x]) {
        if (un_edges[sccNo[i]].find(sccNo[x]) == un_edges[sccNo[i]].end()) {
          densed[sccNo[i]].emplace_back(sccNo[x]);
          un_edges[sccNo[i]].insert(sccNo[x]);
        }
      }

  fill(vis.begin(), vis.end(), 0);

  for (i = 1; i < sccSize; i++)
    if (!vis[i])
      dfs3(i);

  for (i = 1; i <= q; i++) {
    cin >> x >> y;
    if (dp[sccNo[x]][sccNo[y]])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
