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

const int MAX = (1 << 20);

int main() {
  fast;
  ll i, j, x, n;
  vec v, cnt(MAX, 0);
  cin >> n;

  forr(i, 0, n) {
    cin >> x;
    v.eb(x);
    cnt[x]++;
  }

  vec sup = cnt;
  vec sub = cnt;

  forr(i, 0, 20) {
    forr(j, 0, MAX) {
      if (j & (1 << i)) {
        sub[j] += sub[j ^ (1 << i)];
      }
    }
  }

  forr(i, 0, 20) {
    forr(j, 0, MAX) {
      if (!(j & (1 << i))) {
        sup[j] += sup[j | (1 << i)];
      }
    }
  }
  for (auto x : v) {
    cout << sub[x] << " " << sup[x] << " ";
    cout << n - sub[(MAX - 1) ^ x] << endl;
  }
}