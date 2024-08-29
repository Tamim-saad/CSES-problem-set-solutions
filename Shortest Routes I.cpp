#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ed "\n"
#define eb emplace_back
#define pl " "
#define size size()
#define mpr make_pair
#define vec vector<ll>
#define prllsep cout << ed << " ------- " << ed
#define forr(i, a, b) for (ll i = a; i < b; i++)

const ll N = 1e5 + 7;
const ll INF = LLONG_MAX;

vector<vector<pair<ll, ll>>> adj_list(N);

map<ll, ll> value;
map<ll, bool> vis;

void Dijkstra(ll n, ll s) {

  for (ll i = 0; i <= n; i++)
    value[i] = INF;

  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

  pq.push({0, s});
  value[s] = 0;

  while (!pq.empty()) {
    ll curr = pq.top().second;
    pq.pop();

    if (vis[curr])
      continue;
    vis[curr] = true;

    forr(i, 0, adj_list[curr].size) {
      ll neighbour = adj_list[curr][i].first;
      ll weight = adj_list[curr][i].second;

      if (!vis[neighbour] && value[neighbour] > value[curr] + weight) {
        value[neighbour] = value[curr] + weight;

        pq.push({value[neighbour], neighbour});
      }
    }
  }
}

int main() {
  ll n, m, s = 1;
  cin >> n >> m;

  for (ll i = 1; i < m + 1; i++) {
    ll u, v, w;
    cin >> u >> v >> w;

    adj_list[u].eb(mpr(v, abs(w)));
  }

  Dijkstra(n, s);

  forr(i, 1, n + 1) { cout << value[i] << pl; }
  cout << ed;
}