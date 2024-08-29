#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const ll N = 503;
const ll INF = LLONG_MAX;
// ld dist[N][N];

void Floyd_Warshall(vector<vector<ll>> &dist, ll n) {
  for (ll k = 1; k <= n; k++) {
    for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= n; j++) {
        if (i != k && j != k && dist[i][k] < LLONG_MAX &&
            dist[k][j] < LLONG_MAX) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }
}

int main() {

  ll n, m, q;
  cin >> n >> m >> q;

  vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));

  for (ll i = 0; i <= n; i++)
    dist[i][i] = 0;

  for (ll i = 0; i < m; i++) {
    ll u, v;
    ll w;
    cin >> u >> v >> w;

    dist[u][v] = min(abs(w), dist[u][v]);
    dist[v][u] = min(abs(w), dist[v][u]);
  }

  Floyd_Warshall(dist, n);

  ll s, d;
  while (q--) {
    cin >> s >> d;
    if (s == d)
      cout << 0 << endl;
    else if (dist[s][d] != INF)
      cout << setprecision(14) << dist[s][d] << endl;
    else
      cout << -1 << endl;
  }
}
