#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forr(i, a, b) for (ll i = a; i < b; i++)

//------------------------------------------------------------------------
//------------------------------------------------------------------------

const int N = 2e5 + 5;
ll segmantTree[4 * N];

void build(ll arr[], ll rootPos, ll l, ll r) {
  if (l == r) {
    segmantTree[rootPos] = arr[l];
    return;
  }

  ll m = (l + r) / 2;
  build(arr, rootPos * 2, l, m);
  build(arr, rootPos * 2 + 1, m + 1, r);

  segmantTree[rootPos] =
      min(segmantTree[rootPos * 2], segmantTree[rootPos * 2 + 1]);
  return;
}

void update(ll rootPos, ll l, ll r, ll pos, ll newValue) {
  if (pos < l || pos > r)
    return;
  if (l == r) {
    segmantTree[rootPos] = newValue;
    return;
  }

  ll m = (l + r) / 2;
  if (l <= pos && pos <= m)
    update(rootPos * 2, l, m, pos, newValue);
  // if(l<=pos && pos<=m)
  else
    update(rootPos * 2 + 1, m + 1, r, pos, newValue);

  segmantTree[rootPos] =
      min(segmantTree[rootPos * 2], segmantTree[rootPos * 2 + 1]);
  return;
}

ll query(ll rootPos, ll l, ll r, ll L, ll R) {
  if (r < L || R < l)
    if (L > R || l > r || l > R || r < L)
      return LONG_LONG_MAX;
  if (L <= l && r <= R)
    return segmantTree[rootPos];
  else {
    ll m = (l + r) / 2;
    ll ql = query(rootPos * 2, l, m, L, R);
    ll qr = query(rootPos * 2 + 1, m + 1, r, L, R);

    return min(ql, qr);
  }
}

int main() {

  ll q, n;
  cin >> n >> q;

  ll arr[n + 1];
  forr(i, 1, n + 1) { cin >> arr[i]; }

  build(arr, 1, 1, n);

  forr(i, 0, q) {
    ll k, a, b;
    cin >> k >> a >> b;

    if (k == 1) {
      update(1, 1, n, a, b);
    }
    if (k == 2) {
      cout << query(1, 1, n, a, b) << endl;
    }
  }
  return 0;
}
