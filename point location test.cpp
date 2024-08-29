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
  ld x, y;

public:
  Point() {}
  Point(ld _x, ld _y) : x(_x), y(_y) {}
  Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
  ld operator*(const Point &p) const { return (x * p.y - y * p.x); }

  void operator+=(const ld k) {
    x += k;
    y += k;
  }
  void operator-=(const ld k) {
    x -= k;
    y -= k;
  }
  void operator*=(const ld k) {
    x *= k;
    y *= k;
  }
  void operator/=(const ld k) {
    x /= k;
    y /= k;
  }
  bool operator==(const Point &p) const { return x == p.x && y == p.y; }

  ld cross(const Point &b, const Point &c) const {
    return (b - *this) * (c - *this);
  }

  ld len(const Point &a, const Point &b) const {
    return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
  }

  pair<ld, ld> getCrossPoint(const Point &b, const Point &c, const Point &d) {
    ld m1 = (b.y - y) / (b.x - x);
    ld m2 = (d.y - c.y) / (d.x - c.x);

    ld a1 = m1;
    ld b1 = -1;
    ld c1 = y - m1 * x;
    ld a2 = m2;
    ld b2 = -1;
    ld c2 = c.y - m2 * c.x;

    ld x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
    ld y = (c1 * a2 - c2 * a1) / (a1 * b2 - a2 * b1);
    return make_pair(x, y);
  }
};

int getSign(ld x) {
  if (x < 0)
    return -1;
  if (x == 0)
    return 0;
  return 1;
}
bool sameLineTwoSegmentIntersectionCheck(ld a, ld b, ld c, ld d) {
  if (a > b)
    swap(a, b);
  if (c > d)
    swap(c, d);
  return max(a, c) <= min(b, d);
}
bool anyLineTwoSegmentIntersectionCheck(const Point &a, const Point &b,
                                        const Point &c, const Point &d) {
  if (a.cross(c, d) == 0 && b.cross(c, d) == 0)
    return (sameLineTwoSegmentIntersectionCheck(a.x, b.x, c.x, d.x) &&
            sameLineTwoSegmentIntersectionCheck(a.y, b.y, c.y, d.y));
  else
    return (getSign(a.cross(c, d)) != getSign(b.cross(c, d)) &&
            getSign(c.cross(a, b)) != getSign(d.cross(a, b)));
}

int main() {
  fast init {
    count++;
    ll i, j, k, x, y, z, p, q, m, n, l, r, l1, l2, r1, r2, ans, flag, sum;
    ll mini = lmax, maxi = -1, piv, piv1, piv2, rem, now, mid;
    ll dif = 0, change = 0, total = 0, same = 0, plus = 0, minus = 0, zero = 0;

    string s, s1 = "", s2 = "";
    // string res1 = "", res2 = "", chk1 = "", chk2 = "", chk3 = "", chk4 = "",
    // pivs = "", rems = "";

    // cin >> n;
    // n = s.size;

    // ll arr[n];
    // number[n], cost[n], forsum[n], backsum[n];

    vector<ll> v, v1, v2, vans, vpos, vlen, vsum, vdif;
    vector<pair<ll, ll>> vpr;
    // vector<vec> vdarr(n, vec(10, 0));

    pair<ll, ll> pr, pr1, pr2;
    set<ll> st, st1, st2, ms, ldiff, rdiff;
    priority_queue<ll> pq, pq1, pq2;
    stack<ll> stck, stck1, stck2;
    map<int, ll> mp, mp1, mp2;
    queue<ll> vq[10], vq1, vq2;

    Point pa, pb, pc, pd; //,pt[n];
    // Node pa,pb,pt[n];

    // cout<<"-----------------yess"<<endl;

    ans = 0;
    piv = 0;
    flag = 0;
    sum = 0;

    // cout<<LONG_MAX<<endl;
    //  cout<<(n|(n>>1))<<endl;
    //  return 0;

    cin >> pa.x >> pa.y >> pb.x >> pb.y >> pc.x >> pc.y;

    if (getSign(pc.cross(pa, pb)) == 1) {
      cout << "LEFT" << endl;
    } else if (getSign(pc.cross(pa, pb)) == -1) {
      cout << "RIGHT" << endl;
    } else
      cout << "TOUCH" << endl;

    // }
    // ans=(((((2|4)|12)|1)));

    // cout<<max(p,q)<<endl;
    // ans = 0;
  }
}
