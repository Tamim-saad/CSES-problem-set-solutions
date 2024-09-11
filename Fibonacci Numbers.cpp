#include <bits/stdc++.h>
using namespace std;

vector<long long> multiply(vector<long long> m1, vector<long long> m2) {
  vector<long long> ans(4);
  long long mod = 1e9 + 7;

  ans[0] = ((m1[0] * m2[0]) % mod + (m1[1] * m2[2]) % mod) % mod;
  ans[1] = ((m1[0] * m2[1]) % mod + (m1[1] * m2[3]) % mod) % mod;
  ans[2] = ((m1[2] * m2[0]) % mod + (m1[3] * m2[2]) % mod) % mod;
  ans[3] = ((m1[2] * m2[1]) % mod + (m1[3] * m2[3]) % mod) % mod;
  return ans;
}

void nthFibonacci(long long n, vector<long long> &matrix) {
  if (n <= 1)
    return;

  nthFibonacci(n / 2, matrix);
  matrix = multiply(matrix, matrix);
  if (n % 2 == 1)
    matrix = multiply(matrix, {1, 1, 1, 0});
}

int main() {
  long long n;
  cin >> n;

  if (n == 0)
    cout << 0;
  else if (n == 1)
    cout << 1;
  else {
    vector<long long> matrix({1, 1, 1, 0});
    nthFibonacci(n - 1, matrix);
    cout << matrix[0] << endl;
  }
  return 0;
}
