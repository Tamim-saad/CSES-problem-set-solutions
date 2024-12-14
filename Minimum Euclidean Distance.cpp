// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define ll long long

struct Point {
  ll x, y;

public:
  Point() {}
  Point(ll x, ll y) {
    this->x = x;
    this->y = y;
  }
};

ll len(const Point &a, const Point &b) {
  return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool compareX(const Point &a, const Point &b) { return a.x < b.x; }
bool compareY(const Point &a, const Point &b) { return a.y < b.y; }

ll closest(Point point[], ll l, ll h) {
  ll n = h - l + 1;
  if (n <= 1)
    return LONG_LONG_MAX;
  if (n == 2)
    return len(point[l], point[h]);

  ll mid = (h + l) / 2;
  Point midPoint = point[mid];

  ll dl = closest(point, l, mid);
  ll dr = closest(point, mid + 1, h);
  ll d = min(dl, dr);

  vector<Point> strip;
  for (ll i = l; i <= h; i++)
    if (abs(point[i].x - midPoint.x < sqrtl(d)))
      strip.emplace_back(point[i]);

  sort(strip.begin(), strip.end(), compareY);
  n = strip.size();

  for (ll i = 0; i < n; i++)
    for (ll j = i + 1; j <= min(n - 1, i + 8); j++)
      d = min(d, len(strip[i], strip[j]));

  return d;
}

int main() {
  fast;
  ll i, x, y, n;

  cin >> n;
  Point pt[n];

  for (i = 0; i < n; i++) {
    cin >> x >> y;
    pt[i].x = x;
    pt[i].y = y;
  }

  sort(pt, pt + n, compareX);
  cout << closest(pt, 0, n - 1);
}
