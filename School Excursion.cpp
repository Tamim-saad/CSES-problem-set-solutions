// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 100007;
vector<vector<ll>> adj_list(N);
ll par[N];
map<ll, ll> vis;
ll timee = 0;
vector<ll> gv;

void dfs(ll curr, ll parnt) {
  timee++;
  par[curr] = parnt;
  vis[curr] = 1;

  for (int i = 0; i < adj_list[curr].size(); i++) {
    ll neigh = adj_list[curr][i];
    if (par[curr] != neigh) {
      dfs(neigh, curr);
    }
  }
  return;
}

int main() {
  ll n, m, x, y, i;
  cin >> n >> m;

  for (i = 1; i <= m; i++) {
    cin >> x >> y;
    adj_list[x].emplace_back(y);
    adj_list[y].emplace_back(x);
  }

  for (i = 1; i < n + 1; i++) {
    if (!vis[i]) {
      timee = 0;
      dfs(i, i);
      gv.emplace_back(timee);
    }
  }

  bitset<100007> dp;
  dp[0] = 1;

  for (int size : gv)
    dp |= (dp << size);

  for (int i = 1; i <= n; i++)
    cout << dp[i];
}
