/// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;
#define fast                    \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define ll long long

ll gans = 0;
vector<vector<bool>> vis;
vector<pair<ll, ll>> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool isValidVisit(ll i, ll j, ll n, ll m) {
  if (i < 0 || j < 0 || i >= n || j >= m) return false;
  if (vis[i][j]) return false;

  return true;
}

void dfs_On_Grid(ll i, ll j, ll n, ll m) {
  vis[i][j] = true;

  for (auto k : moves) {
    if (isValidVisit(i + k.first, j + k.second, n, m)) {
      dfs_On_Grid(i + k.first, j + k.second, n, m);
    }
  }
}

void connected_Components_On_Grid(ll n, ll m) {
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      if (!vis[i][j]) {
        dfs_On_Grid(i, j, n, m);
        gans++;
      }
    }
  }
}

int main() {
  fast;
  ll m, n;
  char c;

  cin >> n >> m;
  vis.resize(n);

  for (ll i = 0; i < n; i++) {
    vis[i].resize(m);
  }

  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      cin >> c;
      if (c == '#') vis[i][j] = true;
    }
  }

  connected_Components_On_Grid(n, m);
  cout << gans << endl;
}