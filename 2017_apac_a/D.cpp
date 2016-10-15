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

vector<vector<int>> a, c;

void dfs(int i, int remain, int m, int64_t sum, int64_t* best) {
  const int n = a.size();
  if (!remain) {
    *best = max(*best, sum);
    return;
  }
  // cut the branch
  vector<int> maxv(n-i, 0);
  for (int j = i; j < n; ++j) {
    for (int k = a[j].size()-1; k >= 0; --k)
      if (c[j][k] <= m) {
        maxv[j-i] = a[j][k];
        break;
      }
  }
  sort(maxv.begin(), maxv.end());
  if (accumulate(maxv.begin() + n-i-remain, maxv.end(), sum) < *best) return;
  // don't select i-th
  if (remain < n-i) dfs(i+1, remain, m, sum, best);
  // enum from 0 to a[i].size()-1 levels
  for (int k = 0; k < a[i].size(); ++k) {
    if (c[i][k] > m) break;
    dfs(i+1, remain-1, m-c[i][k], sum+a[i][k], best);
  }
}

void solve() {
  int m, n;
  cin >> m >> n;
  a.resize(n);
  c.resize(n);
  for (int i = 0; i < n; ++i) {
    int k, l, tmp;
    cin >> k >> l;
    a[i].resize(k-l+1);
    c[i].resize(k-l+1);
    for (int j = 0; j < l-1; ++j) cin >> tmp;
    for (int j = 0; j < a[i].size(); ++j) cin >> a[i][j];
    c[i][0] = 0;
    for (int j = 0; j < l-1; ++j) cin >> tmp;
    for (int j = 1; j < c[i].size(); ++j) {
      cin >> c[i][j];
      c[i][j] += c[i][j-1];
    }
  }
  int64_t best = 0;
  dfs(0, 8, m, 0, &best);
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
