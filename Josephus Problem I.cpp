/// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

#define fast                                                                   \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);
// cout.tie(0);
#define ll long long
// #define init             \
//     ll count = 0, zz, t; \
//     cin >> t;            \
//     while (t--)
#define ld long double
#define ed "\n"
#define eb emplace_back
#define con continue
#define bre break
#define pl " "
#define pll " --- "
// #define size size()
#define mpr make_pair
#define vec vector<ll>
#define lmax LONG_LONG_MAX
#define lmin LONG_LONG_MIN
#define forr(i, a, b) for (ll i = a; i < b; i++)
#define forrev(i, a, b) for (ll i = a; i >= b; i--)

// #define v.all v.begin(), v.end()

#define printArrWhole(arr, n)                                                  \
  for (ll i = 0; i < n; i++)                                                   \
    cout << arr[i] << " ";                                                     \
  cout << endl;

#define printArrLim(arr, in, n)                                                \
  for (ll i = in; i <= n; i++)                                                 \
    cout << arr[i] << " ";                                                     \
  cout << endl;

#define printYesNo(flag)                                                       \
  if (flag == 0)                                                               \
    cout << "NO";                                                              \
  else                                                                         \
    cout << "YES";                                                             \
  cout << endl;

#define printvcWhole(vc)                                                       \
  for (auto x : vc)                                                            \
    cout << x << " ";                                                          \
  cout << endl;

#define printvcLim(vc, in, n)                                                  \
  for (ll i = in; i <= n; i++)                                                 \
    cout << vc[i] << " ";                                                      \
  cout << endl;

#define printdqWhole(dq)                                                       \
  for (auto x : dq)                                                            \
    cout << x << " ";                                                          \
  cout << endl;

#define printdqLim(dq, in, n)                                                  \
  for (ll i = in; i <= n; i++)                                                 \
    cout << dq[i] << " ";                                                      \
  cout << endl;

#define sortArr(arr, n) sort(arr, arr + n);
#define sortvc(v) sort(v.begin(), v.end());
#define rev(v) reverse(v.begin(), v.end());
// #define find(v, x) find(v.begin(), v.end(), x);

int returnMod(int n, int mod) {
  if (n > mod)
    return n % mod;
  else
    return n;
}

int returnCeil(int a, int b) {
  int n = a / b;
  if (b * n != a)
    n++;
  return n;
}

int main() {

  ll n, ans;
  cin >> n;

  int currentNumber = n;
  int innerStart = 2;

  set<int> st;
  for (int i = 1; i <= n; i++) {
    st.insert(i);
  }

  while (!st.empty()) {
    int n = st.size();
    int step = (n / 2);
    auto it = st.begin();
    ++it;
    for (int i = 0; i < step; i++) {
      cout << *it << " ";
      st.erase(it++);
      if (i < step - 1)
        advance(it, 1);
      // it++;
      // if (it != st.end())
      //   ++it;
    }
    if (2 * step != n) {
      cout << *st.begin() << " ";
      st.erase(*st.begin());
    }
  }

  return 0;
}