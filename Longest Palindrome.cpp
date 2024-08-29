// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    if (s.empty())
      return "";

    string t = "^";
    for (int i = 0; i < s.size(); i++) {
      t += "*" + s.substr(i, 1);
    }
    t += "*$";

    // cout << t << endl;

    int mirror;
    int c = 0;
    int r = 0;
    vector<int> p(t.size(), 0);

    for (int i = 1; i < t.size() - 1; i++) {
      mirror = 2 * c - i;
      if (i < r)
        p[i] = min(r - i, p[mirror]);

      while (t[i + (1 + p[i])] == t[i - (1 + p[i])])
        p[i]++;

      if (i + p[i] > r) {
        r = i + p[i];
        c = i;
      }
    }

    int maxi = 0;
    int center = 0;
    for (int i = 0; i < t.size() - 1; i++) {
      if (p[i] > maxi) {
        maxi = p[i];
        center = i;
      }
    }

    int start = (center - 1 - maxi) / 2;

    return s.substr(start, maxi);
  }
};

int main() {
  Solution s;
  string str;
  cin >> str;
  cout << s.longestPalindrome(str) << endl;
}