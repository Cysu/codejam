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

const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, 1, 0, -1};

int m, n;
vector<vector<double>> a;
vector<vector<int>> v;

void dfs(int i, int j, int nSteps, double score, double* best) {
  if (!nSteps) {
    *best = max(*best, score);
    return;
  }
  for (int k = 0; k < 4; ++k) {
    int p = i+di[k], q = j+dj[k];
    if (p < 0 || p >= m || q < 0 || q >= n) continue;
    double delta = a[p][q] * pow(1-a[p][q], v[p][q]);
    ++v[p][q];
    dfs(p, q, nSteps-1, score+delta, best);
    --v[p][q];
  }
}

void solve() {
  int x, y, nSteps;
  scanf("%d%d%d%d%d\n", &m, &n, &x, &y, &nSteps);
  double P, Q;
  scanf("%lf%lf\n", &P, &Q);
  a.resize(m); v.resize(m);
  for (int i = 0; i < m; ++i) {
    a[i].resize(n, Q);
    v[i].resize(n, 0);
    for (int j = 0; j < n; ++j) {
      char c;
      scanf("%c", &c);
      a[i][j] = c == 'A' ? P : Q;
      scanf("%c", &c);
      v[i][j] = 0;
    }
  }
  double best = 0;
  dfs(x, y, nSteps, 0, &best);
  printf("%.7lf\n", best);
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    printf("Case #%d: ", i + 1);
    solve();
  }
}
