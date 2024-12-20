// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
const double PI = acos(-1.0);
using cd = complex<double>;

vector<cd> fft(vector<cd> p, ll invert) {
  ll n = p.size();
  if (n == 1)
    return p;

  vector<cd> pe, po;
  for (ll i = 0; i < n; i++) {
    if (i % 2)
      po.emplace_back(p[i]);
    else
      pe.emplace_back(p[i]);
  }

  pe = fft(pe, invert);
  po = fft(po, invert);

  double ang = (2 * invert * PI) / n;
  cd w(1), w_d(cos(ang), sin(ang));

  for (ll i = 0; i < n / 2; i++) {
    p[i] = pe[i] + w * po[i];
    p[i + n / 2] = pe[i] - w * po[i];
    w *= w_d;
  }
  return p;
}

vector<ll> multiply(vector<ll> a, vector<ll> b) {
  ll m = a.size() + b.size() - 1;

  ll n = 1;
  while (n < m)
    n <<= 1;

  a.resize(n);
  b.resize(n);

  vector<cd> fa(a.begin(), a.end());
  vector<cd> fb(b.begin(), b.end());

  fa = fft(fa, 1);
  fb = fft(fb, 1);

  for (ll i = 0; i < n; i++)
    fa[i] *= conj(fb[i]);
  // fa[i] *= (fb[i]);

  fa = fft(fa, -1);
  vector<ll> result(m);
  for (ll i = 0; i < m; i++)
    result[i] = llround(fa[i].real() / n);

  return result;
}

int main() {
  fast;
  string s;
  cin >> s;

  ll n = s.length();
  vector<ll> a(n);

  for (ll i = 0; i < n; i++)
    a[i] = s[i] - '0';

  vector<ll> ans = multiply(a, a);
  for (ll i = 1; i < n; i++)
    cout << ans[i] << " ";
}

// int main() {
//   fast;
//   ll n, m;
//   cin >> n;
//   vector<ll> a(n);
//   for (ll i = 0; i < n; i++)
//     cin >> a[i];
//   cin >> m;
//   vector<ll> b(m);
//   for (ll i = 0; i < m; i++)
//     cin >> b[i];

//   vector<ll> result = multiply(a, b);
//   for (ll coeff : result)
//     cout << coeff << " ";
// }
