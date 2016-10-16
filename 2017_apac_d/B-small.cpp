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

int m, n;
vector<vector<int>> a;

void dfs(int i, int j, int count, int* best) {
  if (i >= m) {
    *best = max(*best, count);
    return;
  }
  if (j >= n) {
    dfs(i+1, 0, count, best);
    return;
  }
  dfs(i, j+1, count, best);
  if (j <= 1 || !a[i][j-1] || !a[i][j-2])
    if (i <= 1 || !a[i-1][j] || !a[i-2][j]) {
      a[i][j] = 1;
      dfs(i, j+1, count+1, best);
      a[i][j] = 0;
    }
}

void solve() {
  cin >> m >> n;
  a.resize(m);
  for (int i = 0; i < m; ++i) {
    a[i].resize(n, 0);
    for (int j = 0; j < n; ++j)
      a[i][j] = 0;
  }
  int best = 0;
  dfs(0, 0, 0, &best);
  cout << best << endl;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    printf("Case #%d: ", i + 1);
    solve();
  }
}
