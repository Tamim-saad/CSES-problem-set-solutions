/// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define ll long long

struct Point {
  ll x, y;

public:
  Point() {}
  Point(ll _x, ll _y) : x(_x), y(_y) {}
  Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
  ll operator*(const Point &p) const { return (x * p.y - y * p.x); }

  ll cross(const Point &b, const Point &c) const {
    return (b - *this) * (c - *this);
  }
};

bool compare(const Point &a, const Point &b) {
  return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

bool cwDirectionCheck(const Point &a, const Point &b, const Point &c) {
  return (a.cross(b, c) < 0);
}

int main() {
  fast;
  ll i, n;
  cin >> n;

  vector<Point> points(n);
  for (i = 0; i < n; i++) {
    cin >> points[i].x >> points[i].y;
  }

  sort(points.begin(), points.end(), compare);

  vector<Point> hull;
  for (i = 0; i < n; i++) {
    while (hull.size() > 1 &&
           cwDirectionCheck(hull[hull.size() - 2], hull[hull.size() - 1],
                            points[i])) {
      hull.pop_back();
    }
    hull.emplace_back(points[i]);
  }

  ll half = hull.size();

  for (i = n - 1; i >= 0; i--) {
    while (hull.size() > half &&
           cwDirectionCheck(hull[hull.size() - 2], hull[hull.size() - 1],
                            points[i])) {
      hull.pop_back();
    }
    if (i)
      hull.emplace_back(points[i]);
  }

  sort(hull.begin(), hull.end(), compare);
  hull.pop_back();

  cout << hull.size() << endl;
  for (const auto &p : hull)
    cout << p.x << " " << p.y << endl;
}
