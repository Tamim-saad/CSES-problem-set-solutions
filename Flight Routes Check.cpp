/// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define ll long long
#define eb emplace_back
#define vec vector<ll>
#define forr(i, a, b) for (ll i = a; i < b; i++)

const ll N = 200000 + 5;
vector<vector<ll>> adj_list(N), adj_list2(N);
map<ll, ll> vis;

void dfs(ll curr) {
  vis[curr] = 1;

  forr(i, 0, adj_list[curr].size()) {
    ll neigh = adj_list[curr][i];
    if (!vis[neigh])
      dfs(neigh);
  }
}

int main() {
  ll i, x, y, n, m, ans = 0;

  cin >> n >> m;

  forr(i, 1, m + 1) {
    cin >> x >> y;
    adj_list[x].eb(y);
    adj_list2[y].eb(x);
  }

  dfs(1);
  forr(i, 1, n + 1) {
    if (!vis[i]) {
      cout << "NO\n";
      cout << 1 << " " << i << endl;
      return 0;
    }
  }

  swap(adj_list, adj_list2);
  vis.clear();

  dfs(1);
  forr(i, 1, n + 1) {
    if (!vis[i]) {
      cout << "NO\n";
      cout << i << " " << 1 << endl;
      return 0;
    }
  }
  cout << "YES\n";
}