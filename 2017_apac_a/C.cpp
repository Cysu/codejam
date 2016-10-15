#include <cstdio>
#include <cstring>
#include <cstdint>
#include <cstdlib>
#include <cmath>
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

vector<int> a;

double f(const double x) {
  double r = 0;
  for (auto c : a) r = r * x + c;
  return r;
}

double df(const double x) {
  double r = 0;
  const int n = a.size()-1;
  for (int i = 0; i < n; ++i)
    r = r * x + a[i] * (double)(n-i);
  return r;
}

void solve() {
  int n;
  cin >> n;
  a.resize(n+1);
  for (int i = 0; i <= n; ++i)
    cin >> a[i];
  a[0] = -a[0];
  // newton's method
  double x = rand() * 1000.0 / RAND_MAX;
  while (true) {
    double new_x = x - f(x) / df(x);
    if (fabs(x - new_x) < 1e-9) break;
    x = new_x;
  }
  printf("%.10lf\n", x-1);
}

int main() {
  srand(time(0));
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    printf("Case #%d: ", i + 1);
    solve();
  }
}
