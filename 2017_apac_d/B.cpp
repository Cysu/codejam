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

void solve() {
  cin >> m >> n;
  if (m > n) swap(m, n);
  int ans = 0;
  if (m <= 2) ans = m * (n/3*2 + n%3);
  else {
    for (int i = 0; i < m; ++i) {
      if (i % 3 == 0) {
        ans += n / 3 * 2 + n % 3;
      } else if (i % 3 == 1) {
        ans += n / 3 * 2;
        if (n % 3 >= 1) ans++;
      } else {
        ans += n / 3 * 2;
        if (n % 3 >= 2) ans++;
      }
    }
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
