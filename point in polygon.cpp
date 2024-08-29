/// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define ll long long
#define init                                                                   \
  ll count = 0, zz, t;                                                         \
  cin >> t;                                                                    \
  while (t--)
#define ld long double
#define ed "\n"
#define eb emplace_back
#define con continue
#define bre break
#define pl "  "
#define size size()
#define mpr make_pair
#define vec vector<ll>
#define lmax LONG_LONG_MAX
#define lmin LONG_LONG_MIN
#define forr(i, a, b) for (ll i = a; i < b; i++)
#define forrev(i, a, b) for (ll i = a; i >= b; i--)

// #define v.all v.begin(),v.end()
#define printarr(arr, in, n)                                                   \
  cout << ed;                                                                  \
  for (ll i = in; i < n; i++)                                                  \
    cout << arr[i] << " ";                                                     \
  cout << ed;
#define print(arr, n)                                                          \
  cout << ed;                                                                  \
  for (ll i = 0; i < n; i++)                                                   \
    cout << arr[i] << " ";                                                     \
  cout << ed;
#define printyn(flag)                                                          \
  if (flag == 0)                                                               \
    cout << "NO\n";                                                            \
  else                                                                         \
    cout << "YES\n";

#define printvc(vc)                                                            \
  cout << ed;                                                                  \
  for (auto x : vc)                                                            \
    cout << x << " ";                                                          \
  cout << ed;
// #define printvc(vc)  for(auto x:vc)cout<<x<<".";
// #define printvc(vc,in,n)  cout<<ed;for(ll i=in;i<n;i++)cout<<arr[i]<<"
// ";cout<<ed;

#define srt(arr, n) sort(ara, ara + n);
#define srtvc(v) sort(v.begin(), v.end());
#define rev(v) reverse(v.begin(), v.end());
// #define find(v,x) find(v.begin(), v.end(),x);
#define pll " --- "

struct Point {
  ll x, y;

public:
  Point() {}
  Point(ll _x, ll _y) : x(_x), y(_y) {}
  Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
  ll operator*(const Point &p) const { return (x * p.y - y * p.x); }

  void operator+=(const ll k) {
    x += k;
    y += k;
  }
  void operator-=(const ll k) {
    x -= k;
    y -= k;
  }
  void operator*=(const ll k) {
    x *= k;
    y *= k;
  }
  void operator/=(const ll k) {
    x /= k;
    y /= k;
  }
  bool operator==(const Point &p) const { return x == p.x && y == p.y; }

  ll cross(const Point &b, const Point &c) const {
    return (b - *this) * (c - *this);
  }
};

Point pt[1001];
ll gm, gn;

bool pointAndlineSegmentIntersectionCheck(const Point &a, const Point &b,
                                          const Point &c) {
  return (!(a.cross(b, c)) && (min(b.x, c.x) <= a.x && a.x <= max(b.x, c.x) &&
                               min(b.y, c.y) <= a.y && a.y <= max(b.y, c.y)));
}
void isInsideOrOnPolygon(const Point &p) {
  ll count = 0;
  bool onEdge = false;
  Point p1, p2;

  forr(i, 0, gn) {
    p1 = pt[i];
    p2 = i == gn - 1 ? pt[0] : pt[i + 1];

    if (p1.y <= p.y && p.y < p2.y && p.cross(p1, p2) > 0)
      count++;
    else if (p2.y <= p.y && p.y < p1.y && p.cross(p1, p2) < 0)
      count++;

    if (pointAndlineSegmentIntersectionCheck(p, p1, p2))
      onEdge = true;
  }

  if (onEdge)
    cout << "BOUNDARY" << endl;
  else if (count % 2)
    cout << "INSIDE" << endl;
  else
    cout << "OUTSIDE" << endl;
}

int main() {
  cin >> gn >> gm;

  forr(i, 0, gn) { cin >> pt[i].x >> pt[i].y; }

  Point pa;
  while (gm--) {
    cin >> pa.x >> pa.y;
    isInsideOrOnPolygon(pa);
  }
}
