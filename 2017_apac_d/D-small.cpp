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

int n, m, target;
vector<int> a, b, p;

void dfs(int i, int left, int right, int budget, int* best) {
  if (left <= target && target <= right) {
    *best = min(*best, m-budget);
    return;
  }
  if (left > target || i >= n) return;
  dfs(i+1, left, right, budget, best);
  if (budget >= p[i]) {
    dfs(i+1, left+a[i], right+b[i], budget-p[i], best);
  }
}

void solve() {
  cin >> n >> m >> target;
  a.resize(n); b.resize(n); p.resize(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i] >> b[i] >> p[i];
  int best = INT_MAX;
  dfs(0, 0, 0, m, &best);
  if (best < INT_MAX)
    cout << best << endl;
  else
    cout << "IMPOSSIBLE" << endl;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    printf("Case #%d: ", i + 1);
    solve();
  }
}
