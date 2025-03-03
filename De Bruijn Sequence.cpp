// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

#define ll long long

map<string, vector<string>> adj_list;
map<string, ll> vis;
string ans = "";

void dfs(string curr) {
  vis[curr] = 1;
  if (ans.length() == 0)
    ans += curr;
  else
    ans += curr[curr.length() - 1];

  for (auto neigh : adj_list[curr]) {
    if (!vis[neigh]) dfs(neigh);
  }
  return;
}

int main() {
  ll n;
  cin >> n;
  ll nodeCount = 1;

  string s = "";
  for (ll i = 1; i <= n; i++) {
    s += '0';
    nodeCount *= 2;
  }

  queue<string> q;
  map<string, ll> qvis;

  q.push(s);
  while (!q.empty()) {
    string t, st;
    t = st = q.front();
    q.pop();
    if (qvis[t]) continue;
    qvis[t] = 1;

    st.erase(0, 1);
    string s1 = st + '0', s2 = st + '1';
    q.push(s1);
    q.push(s2);

    adj_list[t].emplace_back(s2);
    adj_list[t].emplace_back(s1);
  }
  dfs(s);
  cout << ans << endl;
}