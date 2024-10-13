#include <bits/stdc++.h>
using namespace std;

#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);

using ll = long long;

struct Node {
  ll maxPreSum;
  ll maxLastSum;
  ll totalSum;
  ll ansSum;

  Node() { maxPreSum = totalSum = maxLastSum = ansSum = 0; }
};

class SegmentTree {
public:
  vector<ll> v;
  vector<Node> tree;
  ll n;

  SegmentTree(ll n) {
    this->n = n;
    tree.resize(4 * n);
    v.resize(n);
  }

  Node merge(Node a, Node b) {
    Node ans;
    ans.totalSum = a.totalSum + b.totalSum;
    ans.maxPreSum = max(a.maxPreSum, a.totalSum + b.maxPreSum);
    ans.maxLastSum = max(b.maxLastSum, a.maxLastSum + b.totalSum);
    ans.ansSum = max({a.maxLastSum + b.maxPreSum, a.ansSum, b.ansSum});
    return ans;
  }

  void build(ll rootPos, ll l, ll r) {
    if (l == r) {
      tree[rootPos].maxPreSum = tree[rootPos].totalSum =
          tree[rootPos].maxLastSum = v[l];
      return;
    }

    ll m = (l + r) / 2;
    build(rootPos * 2 + 1, l, m);
    build(rootPos * 2 + 2, m + 1, r);

    tree[rootPos] = merge(tree[rootPos * 2 + 1], tree[rootPos * 2 + 2]);
  }

  void update(ll rootPos, ll l, ll r, ll pos, ll newValue) {
    if (pos < l || pos > r)
      return;
    if (l == r) {
      v[l] = newValue;
      tree[rootPos].maxPreSum = tree[rootPos].totalSum =
          tree[rootPos].maxLastSum = v[l];
      return;
    }

    ll m = (l + r) / 2;
    update(rootPos * 2 + 1, l, m, pos, newValue);
    update(rootPos * 2 + 2, m + 1, r, pos, newValue);

    tree[rootPos] = merge(tree[rootPos * 2 + 1], tree[rootPos * 2 + 2]);
  }

  Node query(ll rootPos, ll l, ll r, ll L, ll R) {
    if (R < l || L > r) {
      return Node();
    }
    if (L <= l && r <= R) {
      return tree[rootPos];
    }

    ll m = (l + r) / 2;
    Node left = query(rootPos * 2 + 1, l, m, L, R);
    Node right = query(rootPos * 2 + 2, m + 1, r, L, R);
    return merge(left, right);
  }
};

int main() {
  fast;
  ll q, n;
  cin >> n >> q;

  SegmentTree st(n);
  for (ll i = 0; i < n; i++) {
    cin >> st.v[i];
  }

  st.build(0, 0, n - 1);

  for (ll i = 0; i < q; i++) {
    ll k, a, b;
    cin >> a >> b;

    st.update(0, 0, n - 1, a - 1, b);
    Node ans = st.query(0, 0, n - 1, 0, n - 1);
    cout << max(0ll, ans.ansSum) << endl;
  }

  return 0;
}
