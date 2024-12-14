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

int main() {
  ll n, area = 0;
  cin >> n;

  Point pa, pb, pc, pd;
  cin >> pa.x >> pa.y >> pb.x >> pb.y;

  while (n--) {
    cin >> pc.x >> pc.y;
    area += pa.cross(pb, pc);
    pb = pc;
  }

  cout << abs(area) << endl;
}
