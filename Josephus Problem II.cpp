/// Alhamdulillah
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

// template <typename Key, typename Mapped, typename Compare, typename Tag,
//           typename Policy>
// class tree;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);
#define ll long long

int main() {
  ll n, ans, j;
  cin >> n >> j;

  ll currentNumber = n;
  ll innerStart = 2;

  indexed_set st;
  for (ll i = 1; i <= n; i++) {
    st.insert(i);
  }

  int ind = j % st.size();
  while (!st.empty()) {
    int killed = *st.find_by_order(ind);
    cout << killed << " ";
    st.erase(killed);
    if (!st.empty()) ind = ((ind % st.size() + j) % st.size());
  }
}
