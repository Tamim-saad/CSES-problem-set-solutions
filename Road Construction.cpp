// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eb emplace_back

#define forr(i, a, b) for (ll i = a; i < b; i++)
const ll mod = 1e9 + 7;
const ll N = 1e5 + 7;

#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);

vector<ll> par(N, -1);
vector<ll> rankk(N, 1);
vector<ll> childCount(N, 1);

ll findParent(ll u) {
  if (par[u] == -1)
    return u;
  return par[u] = findParent(par[u]);
}

ll uniion(ll u, ll v, ll &cnt, ll &maxi) {
  ll pu = findParent(u);
  ll pv = findParent(v);

  if (pu != pv) {
    cnt--;
    if (rankk[pu] >= rankk[pv]) {
      par[pv] = pu;
      childCount[pu] += childCount[pv];
      if (rankk[pu] == rankk[pv]) {
        rankk[pu]++;
      }
    } else {
      par[pu] = pv;
      childCount[pv] += childCount[pu];
    }
  }
  maxi = max(maxi, childCount[pv]);
  maxi = max(maxi, childCount[pu]);
  return cnt;
}

int main() {
  fast;
  ll n, m, x, y, i;
  cin >> n >> m;

  ll ans = n, maxi = 0;

  for (i = 1; i <= m; i++) {
    cin >> x >> y;
    cout << uniion(x, y, ans, maxi) << " " << maxi << endl;
  }
}