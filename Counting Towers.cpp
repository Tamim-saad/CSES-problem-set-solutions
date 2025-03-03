/// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

#define fast                    \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define ll int
const ll mod = 1e9 + 7;
const ll mAX = 1e6;

int main() {
  fast;
  ll n, x;
  vector<vector<ll>> dp(mAX, vector<ll>(8));

  for (ll i = 0; i < mAX; i++) {
    for (ll j = 0; j < 8; j++) {
      if (!i)
        dp[i][j] = 1;
      else if (j == 0)
        dp[i][j] = (((((dp[i][j] + dp[i - 1][0]) % mod + dp[i - 1][1]) % mod + dp[i - 1][2]) % mod + dp[i - 1][4]) % mod + dp[i - 1][6]) % mod;
      else if (j == 1)
        dp[i][j] = (((dp[i][j] + dp[i - 1][3]) % mod + dp[i - 1][5]) % mod + dp[i - 1][7]) % mod;
      else if (j == 2)
        dp[i][j] = (((((dp[i][j] + dp[i - 1][2]) % mod + dp[i - 1][0]) % mod + dp[i - 1][1]) % mod + dp[i - 1][4]) % mod + dp[i - 1][6]) % mod;
      else if (j == 3)
        dp[i][j] = (((((dp[i][j] + dp[i - 1][0]) % mod + dp[i - 1][1]) % mod + dp[i - 1][2]) % mod + dp[i - 1][4]) % mod + dp[i - 1][6]) % mod;
      else if (j == 4)
        dp[i][j] = (((((dp[i][j] + dp[i - 1][4]) % mod + dp[i - 1][0]) % mod + dp[i - 1][1]) % mod + dp[i - 1][2]) % mod + dp[i - 1][6]) % mod;
      else if (j == 5)
        dp[i][j] = (((dp[i][j] + dp[i - 1][5]) % mod + dp[i - 1][3]) % mod + dp[i - 1][7]) % mod;
      else if (j == 6)
        dp[i][j] = (((((dp[i][j] + dp[i - 1][6]) % mod + dp[i - 1][0]) % mod + dp[i - 1][1]) % mod + dp[i - 1][2]) % mod + dp[i - 1][4]) % mod;
      else if (j == 7)
        dp[i][j] = (((dp[i][j] + dp[i - 1][7]) % mod + dp[i - 1][3]) % mod + dp[i - 1][5]) % mod;
    }
  }

  // cout<<"-----------------yess"<<endl;

  cin >> n;
  for (ll i = 0; i < n; i++) {
    cin >> x;
    cout << (dp[x - 1][3] + dp[x - 1][5]) % mod << endl;
  }
}

///////////////////////////////////////////////////////////////////////
//    0-----
//     |_|_|   from=0,1,2,4,6
//     |_|_|

//    1-----
//     |_|_|   from=3,5,7
//     |___|

//    2-----
//     |_| |   from=0,1,2,4,6
//     |_|_|

//    3-----
//     |___|   from=0,1,2,4,6
//     |_|_|

//    4-----
//     | |_|   from=0,1,2,4,6
//     |_|_|

//    5-----
//     |___|   from=3,5,7
//     |___|

//    6-----
//     | | |   from=0,1,2,4,6
//     | | |

//    7-----
//     |   |   from=3,5,7
//     |___|

///////////////////////////////////////////////////////////////////////
