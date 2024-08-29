#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forr(i, a, b) for (ll i = a; i < b; i++)

const ll N = 1e6 + 5;
ll segmantTree[4 * N];

void build(ll arr[], ll rootPos, ll l, ll r) {
  if (l > r)
    return;
  if (l == r) {
    segmantTree[rootPos] = arr[l];
    return;
  }
  ll m = (l + r) / 2;
  build(arr, rootPos * 2, l, m);
  build(arr, rootPos * 2 + 1, m + 1, r);
  segmantTree[rootPos] =
      max(segmantTree[rootPos * 2], segmantTree[rootPos * 2 + 1]);
  return;
}
void update(ll rootPos, ll l, ll r, ll pos, ll newValue) {
  if (pos < l || pos > r)
    return;
  if (l == r) {
    segmantTree[rootPos] -= newValue;
    return;
  }

  ll m = (l + r) / 2;

  if (l <= pos && pos <= m)
    update(rootPos * 2, l, m, pos, newValue);
  else
    update(rootPos * 2 + 1, m + 1, r, pos, newValue);

  segmantTree[rootPos] =
      max(segmantTree[rootPos * 2], segmantTree[rootPos * 2 + 1]);
  return;
}

ll query(ll rootPos, ll l, ll r, ll L, ll R, ll val) {
  if (segmantTree[rootPos] < val || L > R || l > R || r < L ||
      segmantTree[rootPos] < val)
    return -1;

  if (l == r) // && segmantTree[rootPos]>=val)
  {
    // update(L,L,R,rootPos,segmantTree[rootPos]-val);
    return l;
  }

  ll m = (l + r) / 2;
  if (segmantTree[2 * rootPos] >= val)
    return query(2 * rootPos, l, m, L, R, val);
  else
    return query(2 * rootPos + 1, m + 1, r, L, R, val);
}

int main() {
  string s;
  ll m, n;
  cin >> n >> m;

  ll arr[n + 1];
  forr(i, 1, n + 1) { cin >> arr[i]; }
  build(arr, 1, 1, n);
  forr(i, 0, m) {
    ll a;
    cin >> a;
    ll d = query(1, 1, n, 1, n, a);
    if (d == -1)
      cout << 0 << " ";
    else {
      cout << d << " ";
      update(1, 1, n, d, a);
    }
  }
  return 0;
}