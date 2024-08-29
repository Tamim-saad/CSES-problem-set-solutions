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
#define pl " "
#define pll " --- "
#define size size()
#define mpr make_pair
#define vec vector<ll>
#define lmax LONG_LONG_MAX
#define lmin LONG_LONG_MIN
#define forr(i, a, b) for (ll i = a; i < b; i++)
#define forrev(i, a, b) for (ll i = a; i >= b; i--)

// #define v.all v.begin(), v.end()

#define printArrWhole(arr, n) for (ll i = 0; i < n; i++)

#define printArrLim(arr, in, n)                                                \
  for (ll i = in; i <= n; i++)                                                 \
    cout << arr[i] << " ";

#define printYesNo(flag)                                                       \
  if (flag == 0)                                                               \
    cout << "NO\n";                                                            \
  else                                                                         \
    cout << "YES\n";

#define printvcWhole(vc)                                                       \
  for (auto x : vc)                                                            \
    cout << x << " ";

#define printvcLim(vc, in, n)                                                  \
  for (ll i = in; i <= n; i++)                                                 \
    cout << vc[i] << " ";

#define sortArr(arr, n) sort(arr, arr + n);
#define sortvc(v) sort(v.begin(), v.end());
#define rev(v) reverse(v.begin(), v.end());
#define find(v, x) find(v.begin(), v.end(), x);
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
  fast
  // init
  {
    // count++;
    ll i, j, k, x, y, z, p, q, m, n, l, r, l1, l2, r1, r2, ans, flag, sum;
    ll mini = lmax, maxi = -1, piv, piv1, piv2, rem, now, mid;
    ll dif = 0, change = 0, total = 0, same = 0, plus = 0, minus = 0, zero = 0;

    string s, s1 = "", s2 = "";
    // string res1 = "", res2 = "", chk1 = "", chk2 = "", chk3 = "", chk4 = "",
    // pivs = "", rems = "";

    cin >> n;
    // n = s.size;

    ll arr[n];
    // number[n], cost[n], forsum[n], backsum[n];

    vector<ll> v, v1, v2, vans, vpos, vlen, vsum, vdif;
    vector<pair<ll, ll>> vpr;
    // vector<vec> vdarr(n, vec(10, 0));

    // pair<ll, ll> pr, pr1, pr2;
    // set<ll> st, st1, st2, ms, ldiff, rdiff;
    // priority_queue<ll> pq, pq1, pq2;
    // stack<ll> stck, stck1, stck2;
    // map<int, ll> mp, mp1, mp2;
    // queue<ll> vq[10],vq1,vq2;

    // Point pa,pb,pt[n];
    // Node pa,pb,pt[n];

    // cout<<"-----------------yess"<<endl;

    // ans=0;
    // piv=0;
    // flag=0;
    // sum=0;

    while (n != 1) {
      cout << n << pl;
      if (n % 2 == 1) {
        n = n * 3 + 1;
        // cout<<n<<pl;
      } else {
        n /= 2;
        // cout<<n<<pl;
      }
    }
    cout << n << pl;
  }
}