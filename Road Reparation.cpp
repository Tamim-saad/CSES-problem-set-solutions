// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eb emplace_back

#define forr(i, a, b) for (ll i = a; i < b; i++)
const ll mod = 1e9 + 7;

#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);

int main() {
  fast;
  ll n, m, x, y, i, c;
  cin >> n >> m;

  vector<vector<pair<ll, ll>>> adj_list(n + 1);
  vector<ll> vis(n + 1);
  vector<ll> value(n + 1, LONG_LONG_MAX);

  for (i = 1; i <= m; i++) {
    cin >> x >> y >> c;
    adj_list[x].push_back({y, c});
    adj_list[y].push_back({x, c});
  }

  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

  value[1] = 0;
  pq.push({value[1], 1});
  ll ans = 0;

  while (!pq.empty()) {
    auto [c, curr] = pq.top();
    pq.pop();

    if (vis[curr])
      continue;
    vis[curr] = 1;
    ans += c;

    for (auto [neigh, w] : adj_list[curr]) {
      if (vis[neigh])
        continue;
      if (w < value[neigh]) {
        value[neigh] = w;
        pq.push({w, neigh});
      }
    }
  }

  vis[0] = 1;
  forr(i, 1, n + 1) {
    if (!vis[i]) {
      cout << "IMPOSSIBLE";
      return 0;
    }
  }

  cout << ans;
}