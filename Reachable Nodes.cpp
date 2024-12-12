// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

#define fast                                                                   \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define ll long long

const ll N = 50007;
vector<vector<ll>> adj_list(N);
map<ll, ll> vis;
vector<ll> visit_order;

void dfs(ll curr) {
  if (vis[curr] == 1)
    return;
  vis[curr] = 1;

  for (int i = 0; i < adj_list[curr].size(); i++)
    dfs(adj_list[curr][i]);

  visit_order.emplace_back(curr);
  return;
}

int main() {
  fast;
  ll n, m, x, y, i;
  cin >> n >> m;

  for (i = 1; i <= m; i++) {
    cin >> x >> y;
    adj_list[x].emplace_back(y);
  }

  for (i = 1; i <= n; i++)
    dfs(i);

  vector<bitset<50001>> cnt(n + 1, bitset<50001>());

  for (auto x : visit_order) {
    cnt[x].set(x);

    for (auto neigh : adj_list[x])
      cnt[x] |= cnt[neigh];
  }

  for (i = 1; i <= n; i++)
    cout << cnt[i].count() << " ";
}
