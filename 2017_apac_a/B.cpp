#include <cstdio>
#include <cstring>
#include <cstdint>
#include <climits>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>

using namespace std;

const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, 1, 0, -1};


void solve() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> a(m, vector<int>(n, 0));
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      cin >> a[i][j];

  vector<vector<int>> l(m, vector<int>(n, 0));
  vector<vector<int>> r(m, vector<int>(n, 0));
  vector<vector<int>> u(m, vector<int>(n, 0));
  vector<vector<int>> d(m, vector<int>(n, 0));
  vector<vector<int>> f(m, vector<int>(n, 0));
  vector<vector<bool>> fixed(m, vector<bool>(n, false));

  int ans = 0;
  for (int it = 0; it < m*n; ++it) {
    // left, right, up, down
    for (int i = 1; i < m-1; ++i) {
      l[i][0] = a[i][0]; r[i][n-1] = a[i][n-1];
      for (int j = 1; j < n-1; ++j) {
        l[i][j] = fixed[i][j] ? a[i][j] : max(a[i][j], l[i][j-1]);
        r[i][n-j-1] = fixed[i][n-j-1] ? a[i][n-j-1] : max(a[i][n-j-1], r[i][n-j]);
      }
    }
    for (int j = 1; j < n-1; ++j) {
      u[0][j] = a[0][j]; d[m-1][j] = a[m-1][j];
      for (int i = 1; i < m-1; ++i) {
        u[i][j] = fixed[i][j] ? a[i][j] : max(a[i][j], u[i-1][j]);
        d[m-i-1][j] = fixed[m-i-1][j] ? a[m-i-1][j] : max(a[m-i-1][j], d[m-i][j]);
      }
    }
    // compute update value
    int lowest = INT_MAX;
    for (int i = 1; i < m-1; ++i)
      for (int j = 1; j < n-1; ++j)
        if (!fixed[i][j]) {
          f[i][j] = min(min(l[i][j], r[i][j]), min(u[i][j], d[i][j]));
          lowest = min(lowest, f[i][j]);
        }
    bool update = false;
    for (int i = 1; i < m-1; ++i)
      for (int j = 1; j < n-1; ++j)
        if (!fixed[i][j] && f[i][j] == lowest) {
          ans += f[i][j] - a[i][j];
          a[i][j] = f[i][j];
          fixed[i][j] = true;
          update = true;
        }
    if (!update) break;
  }
  cout << ans << endl;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    printf("Case #%d: ", i + 1);
    solve();
  }
}
