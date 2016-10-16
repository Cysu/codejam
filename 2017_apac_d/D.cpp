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
  int n, m, l;
  cin >> n >> m >> l;
  vector<int> f(l+1, m+1), g(l+1, m+1);
  f[0] = g[0] = 0;
  vector<int> queue(l+1, 0);
  int head = 0, tail = 0;
  for (int i = 0; i < n; ++i) {
    int a, b, p;
    cin >> a >> b >> p;
    head = 0; tail = -1;
    for (int j = a; j <= l; ++j) {
      while (head <= tail && queue[head] < j-b) ++head;
      while (head <= tail && g[queue[tail]] >= g[j-a]) --tail;
      queue[++tail] = j-a;
      f[j] = min(f[j], g[queue[head]] + p);
    }
    copy(f.begin(), f.end(), g.begin());
  }
  if (f[l] <= m)
    cout << f[l] << endl;
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
