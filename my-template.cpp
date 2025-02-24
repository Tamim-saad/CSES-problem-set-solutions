/// say Alhamdulillah

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define ll long long
const double PI = acos(-1.0);

// template <typename Key, typename Mapped, typename Compare, typename Tag,
//           typename Policy>
// class tree;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_multiset;

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
#define pll " --- "
#define size size()
#define mpr make_pair
#define vec vector<ll>
#define lmax LONG_LONG_MAX
#define lmin LONG_LONG_MIN
#define forr(i, a, b) for (ll i = a; i < b; i++)
#define forrev(i, a, b) for (ll i = a; i >= b; i--)
const ll mod = 1e9 + 7;

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
#define find(v, x) find(v.begin(), v.end(), x);

// bool compareByStructureAttribute(const Interval &a, const Interval &b) {
// return a.end <= b.end; }

// bool compareByPair(const std::pair<ll, ll> &a, const std::pair<ll, ll> &b) {
//   if (a.first == b.first)
//     return a.second > b.second; // For descending order of second element
//   return a.first < b.first;     // For ascending order of first element
// }

//----------------------------------------------------------------------------
// // sort the priority queue depned on a specific element
// struct Node {
//     int id;
//     int cost;
//     int heuristic;
// };
// // Functor to compare nodes based on the `cost` (ascending order)
// struct CompareNode {
//     bool operator()(const Node& n1, const Node& n2) {
//         return n1.cost > n2.cost;  // Min-heap based on cost
//     }
// };
// // Declare the priority queue with the custom comparator (min-heap based on
// cost)
//   priority_queue<Node, vector<Node>, CompareNode> pq;

//----------------------------------------------------------------------------
//---------sort using map and vector
// instantly-------------------------------------------------------------------
//----------------------------------------------------------------------------
// // Create a vector of pairs and copy the map elements into it
//     std::vector<std::pair<int, int>> vec(map.begin(), map.end());

//     // Sort the vector by value using a lambda function
//     std::sort(vec.begin(), vec.end(), [](const std::pair<int, int>& a, const
//     std::pair<int, int>& b) {
//         return a.second < b.second;
//     });
//----------------------------------------------------------------------------

void kmp_pattern_count_into_string(string s, string p) {
  vector<ll> v(p.size(), 0);
  ll i = 0, j = 1;
  while (j < p.size()) {
    if (p[i] == p[j]) {
      v[j] = i + 1;
      i++;
      j++;
    } else {
      if (i != 0)
        i = v[i - 1];
      else
        j++;
    }
  }

  ll ans = 0;
  i = 0;
  j = 0;
  while (j < s.size()) {
    if (s[j] == p[i]) {
      i++;
      j++;
      if (i == p.size()) {
        ans++;
        i = v[i - 1];
      }
    } else {
      if (i != 0)
        i = v[i - 1];
      else
        j++;
    }
  }
  cout << ans << endl;
}

//----------------------------------------------------------------------------------------

// by lucas theorem
bool is_nCr_odd(ll n, ll r) {
  while (n > 0 || r > 0) {
    if (r & 1 > n & 1)
      return false;
    n >>= 1;
    r >>= 1;
  }
  return true;
}

class SegmentTree {
private:
  vector<int> tree;
  vector<int> v;
  int n;

  // Build the segment tree
  void build(int node, int start, int end) {
    if (start == end) {
      // Leaf node will contain a single element
      tree[node] = v[start];
    } else {
      int mid = (start + end) / 2;
      build(2 * node + 1, start, mid);
      build(2 * node + 2, mid + 1, end);
      // Internal node will be the sum/min/max of the two child nodes
      tree[node] =
          tree[2 * node + 1] +
          tree[2 * node + 2]; // Modify this based on operation (sum/min/max)
    }
  }

  // Update the element at a specific position
  void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
      // Leaf node, update value
      v[idx] = val;
      tree[node] = val;
    } else {
      int mid = (start + end) / 2;
      if (start <= idx && idx <= mid) {
        update(2 * node + 1, start, mid, idx, val);
      } else {
        update(2 * node + 2, mid + 1, end, idx, val);
      }
      // Update the internal node after updating the child nodes
      tree[node] =
          tree[2 * node + 1] +
          tree[2 * node + 2]; // Modify this based on operation (sum/min/max)
    }
  }

  // Query the segment tree for a range
  int query(int node, int start, int end, int L, int R) {
    if (R < start || end < L) {
      // Range represented by a node is completely outside the given range
      return 0; // Modify this based on operation (for min use INT_MAX, for sum
                // use 0)
    }
    if (L <= start && end <= R) {
      // Range represented by a node is completely inside the given range
      return tree[node];
    }

    // Range represented by a node is partially inside and partially outside the
    // given range
    int mid = (start + end) / 2;
    int leftQuery = query(2 * node + 1, start, mid, L, R);
    int rightQuery = query(2 * node + 2, mid + 1, end, L, R);
    return leftQuery +
           rightQuery; // Modify this based on operation (sum/min/max)
  }

public:
  // Constructor to initialize the segment tree
  SegmentTree(vector<int> &input) {
    v = input;
    n = v.size();
    tree.resize(4 * n);
    build(0, 0, n - 1);
  }

  // Function to call update operation
  void update(int idx, int val) { update(0, 0, n - 1, idx, val); }

  // Function to call range query operation
  int query(int L, int R) { return query(0, 0, n - 1, L, R); }
};

//------------------------------------------------------------------------------------------

const double PI = acos(-1.0);
using cd = complex<double>;
vector<cd> fft(vector<cd> p, ll invert) {
  ll n = p.size();
  if (n == 1)
    return p;

  vector<cd> pe, po;
  for (ll i = 0; i < n / 2; i++) {
    pe.emplace_back(p[2 * i]);
    po.emplace_back(p[2 * i + 1]);
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

  for (ll i = 0; i < n; i++) {
    fa[i] = fa[i] * (fb[i]);
  }

  fa = fft(fa, -1);
  vector<ll> result(m);
  for (ll i = 0; i < m; i++)
    result[i] = llround(fa[i].real() / n);
  return result;
}

//------------------------------------------------------------------------------------------

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

  ll cross(const Point &b, const Point &c) const {
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

bool cwDirectionCheck(const Point &a, const Point &b, const Point &c) {
  return (a.cross(b, c) < 0); //return true , if (a,b,c) points are clockwise
}

// ld area(Point a, Point b, Point c) { return abs((a.x * (b.y - c.y) + b.x *
// (c.y - a.y) + c.x * (a.y - b.y)) / 2.0); }

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

void allPossibleWord(string s) // accept duplicate characters
{
  sort(s.begin(), s.end());

  map<string, ll> mp;
  vector<string> vc;

  vc.eb(s);
  mp[s] = 1;

  while (next_permutation(s.begin(), s.end())) {
    if (!mp[s]) {
      vc.eb(s);
      mp[s] = 1;
    }
  }
  cout << vc.size << endl;
  forr(i, 0, vc.size) { cout << vc[i] << endl; }
}

ll subArraySum_for_K(ll n, ll k, ll arr[]) {
  ll forsum[n];

  forsum[0] = arr[0];
  forr(i, 1, n) { forsum[i] = forsum[i - 1] + arr[i]; }

  map<ll, ll> mp;
  ll ans = 0;

  forr(i, 0, n) {
    ans += mp[forsum[i] - k];
    ans += (forsum[i] == k);
    mp[forsum[i]]++;
  }
  return ans;
}

ll median_from_multiplication_table(ll n) // n=odd
{
  ll low = 1, high = n * n, mid, cnt, currPos, pos = (n * n + 1) / 2;
  while (low < high) {
    cnt = 0;
    currPos = (low + high) / 2;
    forr(i, 1, n + 1) cnt += min(currPos / i, n);

    if (pos <= cnt)
      high = currPos;
    else
      low = currPos + 1;
  }
  return low;
}

ll longestSubarrayWithDistinctValues(ll arr[], ll n) {
  ll ans = 0;
  ll i = 0, j = 0;
  map<ll, ll> mp;

  while (j < n) {
    if (mp[arr[j]] == 0) {
      mp[arr[j]] = 1;
    } else {
      ans = max(ans, j - i);
      while (arr[i] != arr[j]) {
        mp[arr[i]] = 0;
        i++;
      }
      i++;
    }
    j++;
  }

  ans = max(ans, j - i);
  return ans;
}

ll binaryLength(ll n) {
  if (n == 0)
    return 0;
  return 64 - __builtin_clzll(n);
}

int sum_without_using_sign(int a, int b) {
  if (!a || !b)
    return a | b;
  return recur(a ^ b, (a & b) << 1);
}

ll countAllSetBits(ll n) {
  ll total = 0;
  while (n >= 1) {
    ll len = binaryLength(n) - 1;

    ll piv = 1ll << len;
    total += len * (piv) / 2;
    n -= piv;
    total += n + 1;
  }
  return total;
}

// modified version
ll allBitSubSequence(vec &v, ll sum) // by bit manipulation
{
  ll temp, ans, n = v.size, mini = LONG_LONG_MAX;

  forr(i, 0, pow(2, n)) // check for all number upto total
  {
    temp = 0;
    forr(j, 0, n) // check for all bit of a number
    {
      if (i >> j & 1) // if jth bit is set
      {
        temp += v[n - j - 1];
      }
    }
    ans = abs((sum - temp) - temp);
    mini = min(ans, mini);
  }
  return mini;
}

ll maxAreaHistogram(vec &height, ll n) {
  stack<ll> s;
  vec left(n), right(n);

  s.push(0);
  left[0] = 0;
  forr(i, 1, n) {
    while (!s.empty() && height[i] <= height[s.top()])
      s.pop();
    if (s.empty())
      left[i] = 0;
    else
      left[i] = s.top() + 1;
    s.push(i);
  }
  while (!s.empty())
    s.pop();
  ////////////////////////////////////////////////
  s.push(n - 1);
  right[n - 1] = n - 1;
  forrev(i, n - 2, 0) {
    while (!s.empty() && height[i] <= height[s.top()])
      s.pop();
    if (s.empty())
      right[i] = n - 1;
    else
      right[i] = s.top() - 1;
    s.push(i);
  }

  ll maxArea = 0;
  forr(i, 0, n) {
    ll curr = abs(right[i] - left[i] + 1) * height[i];
    maxArea = max(maxArea, curr);
  }
  return maxArea;
}

ll missingCoinSum(vec v) {
  sortvc(v);
  ll n = v.size;
  ll upto = 0;

  forr(i, 0, n) {
    if (v[i] > upto + 1) {
      return upto + 1;
    } else {
      upto += v[i];
    }
  }
  return upto + 1;
}

//-----------------------------------------
bool validParenthesisCheck(string s) {
  stack<char> st;
  forr(i, 0, s.size) {
    if (s[i] == '(') {
      st.push('(');
      con;
    }
    if (st.empty() == true || !(s[i] == ')' && st.top() == '('))
      return false;
    st.pop();
  }
  if (st.empty() == true)
    return true;
  else
    return false;
}

//-----------------------------------------
bool validBracketOrderCheck(string s) {
  stack<char> st;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
      st.push(s[i]);
      continue;
    }
    if (s[i] == ')') {
      if (st.empty() || st.top() != '(')
        return false;
    } else if (s[i] == '}') {
      if (st.empty() || st.top() != '{')
        return false;
    } else if (s[i] == ']') {
      if (st.empty() || st.top() != '[')
        return false;
    }
    st.pop();
  }

  if (st.empty())
    return true;
  return false;
}
//------------------------------
ll generateAllSubSetOfArray(vector<ll> nums) {
  ll n = nums.size();
  for (ll i = 0; i < (1 << n); i++) {
    set<ll> st;
    for (ll j = 0; j < n; j++) {
      if (i & (1 << j)) {
        st.insert(nums[j]);
      }
    }
    for (auto x : st) {
      cout << x << " ";
    }
    cout << endl;
  }
}
bool subsetSumCheck(vector<int> &nums, int target) {
  vector<vector<bool>> dp(nums.size() + 1, vector<bool>(target + 1, false));
  for (int i = 0; i <= nums.size(); i++)
    dp[i][0] = true;

  for (int i = 1; i <= nums.size(); i++) {
    for (int j = 0; j <= target; j++) {
      bool exclude = dp[i - 1][j];
      bool include = false;
      if (j - nums[i - 1] >= 0)
        include = dp[i - 1][j - nums[i - 1]];
      dp[i][j] = include || exclude;
    }
  }
  return dp[nums.size()][target];
}

//--------------------------------

bool isprime(ll n) {
  if (n == 1) return false;
  if (n == 2 || n == 3) return true;
  ll k = sqrt(n);
  for (ll i = 2; i <= k; i++) {
    if (n % i == 0) return false;
  }
  return true;
}


ll lcm(ll arr[], ll n) {
  ll ans = arr[0];
  forr(i, 1, n) { ans = ((arr[i] * ans)) / (__gcd(arr[i], ans)); }
  return ans;
}

ll gcd(ll arr[], ll n) {
  ll ans = arr[0];
  forr(i, 1, n) { ans = __gcd(arr[i], ans); }
  return ans;
}

//---------compute factorial with modular
// exponent--------------------------------------------------------
ll modular_exponent(ll base, ll pow, ll mod) {
  if (pow == 0)
    return 1;

  ll x = modular_exponent(base, pow / 2, mod);

  if (pow % 2 == 0)
    return (x * x) % mod;
  else
    return ((x * x) % mod * base) % mod;
}

void compute_factorial_with_modular_inverse(ll mod, vector<ll> &factorials,
                                            vector<ll> &factorials_mod_inv) {
  factorials[0] = 1;
  int n = factorials.size() - 1;
  for (int i = 1; i <= n; i++) {
    factorials[i] = factorials[i - 1] * i % mod;
  }
  factorials_mod_inv[n] = modular_exponent(factorials[n], mod - 2, mod);
  for (int i = n - 1; i >= 0; i--) {
    factorials_mod_inv[i] = factorials_mod_inv[i + 1] * (i + 1) % mod;
  }
}
//---------------------------------------------------------------------------------

string binary = bitset<8>(n).to_string();
unsigned long decimal = bitset<8>(binary).to_ulong();

string binaryStr = "110111";
int value =
    std::stoi(binaryStr, nullptr, 2); // Convert binary string to integer
std::cout << value << std::endl;      // Output: 55

/// ------------------------------------------
const ll N = 100007;
vector<vector<ll>> adj_list(N);
ll par[N];
map<ll, ll> vis;
ll timee = 0, gcount;
ll gv[N];
vector<ll> gSizes;

void dfs(ll curr, ll parnt) {
  timee++;
  gcount++;
  gv[timee] = curr;
  par[curr] = parnt;
  vis[curr] = 1;

  for (int i = 0; i < adj_list[curr].size(); i++) {
    ll neigh = adj_list[curr][i];
    if (par[curr] != neigh) {
      dfs(neigh, curr);
    }
  }
  return;
}

int main() {
  fast;
  ll n, m, x, y, i;
  cin >> n >> m;

  for (i = 1; i <= m; i++) {
    cin >> x >> y;
    adj_list[x].emplace_back(y);
    adj_list[y].emplace_back(x);
  }

  for (i = 1; i < n + 1; i++) {
    if (!vis[i]) {
      gcount = 0;
      dfs(i, i);
      gSizes.emplace_back(gcount);
    }
  }
}

/// ---Cycle Detection in Graph-----------------------------

vector<vector<ll>> adj_list;
vector<ll> par;
vector<bool> vis;
bool found_cycle = false;
ll gx, gy;

bool dfs(ll curr, ll parent = -1) {
  vis[curr] = true;
  par[curr] = parent;

  for (auto x : adj_list[curr]) {
    if (x == parent)
      continue;
    if (vis[x]) {
      found_cycle = true;
      gx = x;
      gy = curr;
      return true;
    }
    if (dfs(x, curr))
      return true;
  }
  return false;
}

/// ---determine farthest node in a tree------------------------

// vector<vector<ll>> adj_list;
// vector<ll> par, vis;
// ll node = -1, depth = 0, maxdepth = 0;

void dfs(ll curr, ll parent = -1) {
  if (vis[curr] != -1) {
    if (vis[curr] == 1)
      depth--;
    return;
  }

  par[curr] = parent;
  vis[curr] = 0;
  depth++;
  if (maxdepth <= depth) {
    maxdepth = depth;
    node = curr;
  }
  // cout << curr << pl << depth << ed;

  for (auto x : adj_list[curr]) {
    if (par[curr] != x)
      dfs(x, curr);
  }

  vis[curr] = 1;
  depth--;
  return;
}
/// --------------**************--------------------------
// this is efficient 1d DP of boolean value for fixed size input(eg: 100007)
// for example: if we can find all possible sum for input :2,5,7
// output will be : 0, 2, 5, 7, 9, 12, 14
// then output of following code: 101001010100101
// here position of set bits indicate the possible sums
/// --------------**************--------------------------

bitset<100007> dp;
dp[0] = 1;

for (int size : gv)
  dp |= (dp << size);

for (int i = 1; i <= n; i++)
  cout << dp[i];

/// ------------------------------------------------------

ll knapsack_01(ll n, ll x, ll weight[], ll profit[]) {
  // here ll should be int(ll = int)
  ll dp[n + 1][x + 1];
  forr(i, 0, n + 1) {
    forr(j, 0, x + 1) {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      else if (weight[i] <= j)
        dp[i][j] = max(profit[i] + dp[i - 1][j - weight[i]], dp[i - 1][j]);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  return dp[n][x];
}

ll knapSackRec(ll W, ll wt[], ll val[], ll i, ll **dp) {
  // base condition
  if (i < 0)
    return 0;
  if (dp[i][W] != -1)
    return dp[i][W];

  if (wt[i] > W) {

    // Store the value of function call
    // stack in table before return
    dp[i][W] = knapSackRec(W, wt, val, i - 1, dp);
    return dp[i][W];
  } else {
    // Store value in a table before return
    dp[i][W] = max(val[i] + knapSackRec(W - wt[i], wt, val, i - 1, dp),

                   knapSackRec(W, wt, val, i - 1, dp));

    // Return value of table after storing
    return dp[i][W];
  }
}

ll knapSack(ll n, ll W, ll wt[], ll val[]) {
  // double poller to declare the
  // table dynamically
  ll **dp;
  dp = new ll *[n];

  // loop to create the table dynamically
  for (ll i = 0; i < n; i++)
    dp[i] = new ll[W + 1];

  // loop to initially filled the
  // table with -1
  for (ll i = 0; i < n; i++)
    for (ll j = 0; j < W + 1; j++)
      dp[i][j] = -1;
  return knapSackRec(W, wt, val, n - 1, dp);
}

// count++;
// ll i, j, k, x, y, z, p, q, m, n, l, r, l1, l2, r1, r2, ans, flag, sum;
// ll mini = lmax, maxi = -1, piv, piv1, piv2, low, high, rem, now, prev;
// ll dif = 0, change = 0, total = 0, same = 0, plus = 0, minus = 0, zero = 0;

// char ch, ch1, ch2, ch3, ch4;
// string sarr[n];
// string s, s1 = "", s2 = "";
// string res1 = "", res2 = "", chk1 = "", chk2 = "", chk3 = "", chk4 = "",
// pivs = "", rems = "";

// cin >> n;
// n = s.size;

// ll arr[n];
// number[n], cost[n], forsum[n], backsum[n];

// vector<ll> v, v1, v2, vans, vpos, vlen, vsum, vdif;
// vector<ll> v(n), v1(n), v2(n);
// vector<vec> dp(n+1,vec(x+1,0));
// vector<tuple<ll,ll,ll>> vtup, vtup1, vtup2, vtup3;
// vector <string> vstr(n);
// vector<pair<ll, ll>> vpr, vpr1, vpr2, vpr3;
// vector<vec> vdarr(n, vec(10, 0));
// deque<ll> dq, dq1, dq2;

// pair<ll, ll> pr, pr1, pr2;
// set<ll> st, st1, st2, ms, ldiff, rdiff;
// multiset <ll> mst, mst1, mst2;
// multiset<ll, greater<ll>> mst, mst1, mst2;
// multiset <pair<ll,ll>> mst, mst1, mstans;
// priority_queue<ll> pq, pq1, pq2;
//************priority queue of 2d vector using customize global comapre()
// function of 3rd component of each vector*****************
// priority_queue<vector<int>, vector<vector<int>>,function<bool(const
// vector<int> &, const vector<int> &)>> pq(compare); stack<ll> stck, stck1,
// stck2; map<int, ll> mp, mp1, mp2; map<pair<ll,ll>,ll> mpair, mpair1,
// mpair2; vector<pair<ll,ll>> vpr, vpr1, vpr2; queue<ll> vq[10],vq1,vq2;

// Point pa,pb,pt[n];
// Node pa,pb,pt[n];
// fill(par.begin(), par.end(), -1);
// fill(vis.begin(), vis.end(), -1);

// cout<<"-----------------yess"<<endl;

// ans = 0;
// piv = 0;
// flag=0;
// sum=0;

// forr(i,0,n)
// {
//     cin>>x>>y;
//     vtup.push_back(make_tuple(x,y,i));
// }
// sort(vtup.begin(),vtup.end());
// x=get<0>(vtup[i]);

///--------------begin_Main_Code_here-----------------------
int main() {
  fast init {
    ll i, j, k, x, y, z, p, q, m, n, l, r, ans, flag, sum;
    cin >> n;
    vector<ll> v, v1, v2, vans, vpos, vlen, vsum, vdif;
    priority_queue<ll> pq, pq1, pq2;

    ll sub = 0;
    forr(i, 0, n) {
      cin >> x;
      cout << "test" << endl;
      v.eb(x);
      if (i < n - 2)
        sub -= x;
      if (i >= n - 2)
        sub = x - sub;
    }
    cout << sub << endl;

    // cout<<ans<<endl;
  }
}