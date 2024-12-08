// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);

// starting number with i digit, x = pow(10, i - 1);
// ending number with i digit, y = pow(10, i) - 1;
// y - x + 1 = [pow(10, i) - 1] - [pow(10, i - 1)] + 1 =
//                 9 * pow(10, i - 1)
// total digit for all numbers each of i digit =   9 * pow(10, i - 1)* i;

ll return_ith_Digit(ll num) {
  ll n = log10(num) + 1;

  ll x, i = 1, m = 0;
  while (1) {
    x = 9 * pow(10, i - 1) * i; // x = total digits for all numbers of i length
    if (m + x >= num)
      break;
    m += x;
    i += 1;
  }

  ll start = pow(10, i - 1);
  ll offset = (num - m - 1) / i;
  string s = to_string(start + offset);

  ll indexInNumber = (num - m - 1) % i;
  return s[indexInNumber] - '0';
}

int main() {
  fast;
  ll n, x;
  cin >> n;
  for (ll i = 0; i < n; i++) {
    cin >> x;
    cout << return_ith_Digit(x) << endl;
  }
}