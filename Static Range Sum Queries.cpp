#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forr(i, a, b) for (ll i = a; i < b; i++)

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
      (segmantTree[rootPos * 2] + segmantTree[rootPos * 2 + 1]);
  return;
}

ll query(ll rootPos, ll l, ll r, ll L, ll R) {
  if (L > R || l > r || l > R || r < L)
    return 0;
  if (L <= l && r <= R)
    return segmantTree[rootPos];
  else {
    ll m = (l + r) / 2;
    ll ql = query(rootPos * 2, l, m, L, R);
    ll qr = query(rootPos * 2 + 1, m + 1, r, L, R);

    return (ql + qr);
  }
}

int main() {

  ll q, n;
  cin >> n >> q;

  ll arr[n + 1];
  forr(i, 1, n + 1) { cin >> arr[i]; }
  build(arr, 1, 1, n);

  // forr(i,1,2*n)
  // {
  //     cout<<segmantTree[i]<<" ";

  // }
  // cout<<endl;

  forr(i, 0, q) {
    ll a, b;
    cin >> a >> b;

    cout << query(1, 1, n, a, b) << endl;
  }
  return 0;
}