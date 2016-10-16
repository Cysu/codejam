#include <cstdio>
#include <cstring>
#include <cstdint>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<double>> f(n+1, vector<double>(m+1, 0));
  double z = 1.0;
  for (int j = 1; j <= m; ++j)
    z = z * (n+j) / j;
  for (int i = 1; i <= n; ++i) f[i][0] = 1.0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j < min(i, m+1); ++j)
      f[i][j] = f[i-1][j] + f[i][j-1];
  printf("%.8lf\n", f[n][m] / z);
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    printf("Case #%d: ", i + 1);
    solve();
  }
}
