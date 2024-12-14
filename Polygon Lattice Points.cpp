/// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Point {
  ll x, y;

public:
  Point() {}
  Point(ll x, ll y) {
    this->x = x;
    this->y = y;
  }
  Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
  ll operator*(const Point &p) const { return (x * p.y - y * p.x); }

  ll cross(const Point &b, const Point &c) const {
    return (b - *this) * (c - *this);
  }
};

ll getPolygonArea(vector<Point> &points) {
  ll n = points.size();
  ll area = 0;
  Point pa = points[0], pb = points[1], pc;

  for (ll i = 2; i < n; i++) {
    pc = points[i];
    area += pa.cross(pb, pc);
    pb = pc;
  }
  return area;
}

int main() {
  ll n, area = 0;
  cin >> n;

  Point pa, pb;
  vector<Point> points;
  ll onLine = 0;

  for (ll i = 0; i < n; i++) {
    cin >> pa.x >> pa.y;
    points.emplace_back(pa);
    if (i)
      onLine += __gcd(abs(points[i].x - points[i - 1].x),
                      abs(points[i].y - points[i - 1].y));
  }
  onLine += __gcd(abs(points[0].x - points[n - 1].x),
                  abs(points[0].y - points[n - 1].y));

  area = getPolygonArea(points);

  // Using Pick's Theorem:
  cout << (abs(area) - onLine) / 2 + 1 << " " << onLine;
}