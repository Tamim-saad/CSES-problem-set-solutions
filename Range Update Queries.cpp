/// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

#define fast                    \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define ll long long
#define vec vector<ll>
#define forr(i, a, b) for (ll i = a; i < b; i++)
#define forrev(i, a, b) for (ll i = a; i >= b; i--)

const int N = 2e5 + 5;
ll segmantTree[4 * N];

void build(vec &arr, ll rootPos, ll l, ll r) {
  if (l == r) {
    segmantTree[rootPos] = arr[l];
    return;
  }

  ll m = (l + r) / 2;
  build(arr, rootPos * 2, l, m);
  build(arr, rootPos * 2 + 1, m + 1, r);

  segmantTree[rootPos] = (segmantTree[rootPos * 2] + segmantTree[rootPos * 2 + 1]);
  return;
}

void update(ll rootPos, ll l, ll r, ll pos, ll newValue) {
  if (pos < l || pos > r) return;
  if (l == r) {
    segmantTree[rootPos] += newValue;
    return;
  }

  ll m = (l + r) / 2;
  if (l <= pos && pos <= m)
    update(rootPos * 2, l, m, pos, newValue);
  else
    update(rootPos * 2 + 1, m + 1, r, pos, newValue);

  segmantTree[rootPos] = (segmantTree[rootPos * 2] + segmantTree[rootPos * 2 + 1]);
  return;
}

ll query(ll rootPos, ll l, ll r, ll L, ll R) {
  if (r < L || R < l)
    if (L > R || l > r || l > R || r < L) return 0;
  if (L <= l && r <= R)
    return segmantTree[rootPos];
  else {
    ll m = (l + r) / 2;
    ll ql = query(rootPos * 2, l, m, L, R);
    ll qr = query(rootPos * 2 + 1, m + 1, r, L, R);

    return (ql + qr);
  }
}

/**
 * @brief Entry point of the program.
 *
 * This function reads input values for the number of elements (n) and the number of queries (q).
 * It initializes a vector `v` of size `n + 1` and reads `n` elements into it.
 * The vector `v` is then transformed to store the differences between consecutive elements.
 * The `build` function is called to initialize a segment tree with the vector `v`.
 *
 * The function then processes `q` queries.
 */

int main() {
  fast;
  ll a, b, c, i, k, x, q, n;

  cin >> n >> q;
  vec v(n + 1);

  // cout<<"-----------------yess"<<endl;

  v[0] = 0;
  forr(i, 1, n + 1) {
    cin >> x;
    v[i] = x;
  }

  forrev(i, n, 1) { v[i] -= v[i - 1]; }

  build(v, 1, 1, n);

  forr(i, 0, q) {
    cin >> k;

    if (k == 1) {
      cin >> a >> b >> c;
      update(1, 1, n, a, c);
      if (b < n) update(1, 1, n, b + 1, -c);
    } else {
      cin >> a;
      cout << query(1, 1, n, 1, a) << endl;
    }
  }
}