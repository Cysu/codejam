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

const int M = 1000000007;

void solve() {
  int m, nQuery;
  cin >> m >> nQuery;
  vector<int> len(m, 0);
  vector<vector<int>> a(m, vector<int>(26, 0)); // characters histogram of vocab words
  for (int i = 0; i < m; ++i) {
    string w;
    cin >> w;
    len[i] = w.length();
    for (auto c : w) ++a[i][c - 'a'];
  }
  vector<vector<int>> f;
  int count[26];
  while (nQuery--) {
    string s;
    cin >> s;
    int n = s.length();
    f.resize(n);
    for (int i = 0; i < n; ++i) f[i].resize(m);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        f[i][j] = 0;
        if (i+1 < len[j]) continue;
        // check match
        memset(count, 0, sizeof(count));
        bool match = true;
        for (int p = i-len[j]+1; p <= i; ++p)
          if (++count[s[p] - 'a'] > a[j][s[p] - 'a']) {
            match = false;
            break;
          }
        if (!match) continue;
        if (i-len[j] < 0)
          f[i][j] = (f[i][j] + 1) % M;
        else {
          for (int k = 0; k < m; ++k) {
            f[i][j] = (f[i][j] + f[i-len[j]][k]) % M;
          }
        }
      }
    int ans = 0;
    for (int j = 0; j < m; ++j)
      ans = (ans + f[n-1][j]) % M;
    cout << ans;
    if (nQuery) cout << " ";
  }
  cout << endl;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    printf("Case #%d: ", i + 1);
    solve();
  }
}
