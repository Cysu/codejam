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

const int64_t M = 1000000007;

int64_t fast_pow(int64_t x, int64_t n, int64_t m) {
  int64_t r = 1;
  while (n) {
    if (n&1) {
      r = (r * x) % m;
      --n;
    } else {
      x = (x * x) % m;
      n >>= 1;
    }
  }
  return r % m;
}

void solve() {
  int64_t A, B, K;
  int64_t N;
  cin >> A >> B >> N >> K;
  vector<int64_t> c1(K, 0), c2(K, 0);
  vector<int64_t> iA(K, 0), jB(K, 0);
  for (int64_t k = 0; k < K; ++k) {
    c1[k] = (N/K + (N%K >= k)) % M;
    if (k == 0) --c1[k];
    iA[k] = fast_pow(k, A, K);
    jB[k] = fast_pow(k, B, K);
    c2[jB[k]] = (c2[jB[k]] + c1[k]) % M;
  }
  int64_t ans = 0;
  for (int64_t k = 0; k < K; ++k) {
    ans = (ans + (c1[k] * c2[(K - iA[k]) % K]) % M) % M;
    if ((iA[k] + jB[k]) % K == 0)
      ans = (ans - c1[k]) % M;
  }
  cout << (ans % M + M) % M << endl;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    printf("Case #%d: ", i + 1);
    solve();
  }
}
