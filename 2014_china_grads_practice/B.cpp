#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

void solve()
{
    int V, D;
    scanf("%d %d", &V, &D);

    double g = 9.8;

    double A = V * V / (g * D);

    double delta = sqrt(1 - 1 / (A*A));

    double t = 180*acos(sqrt(0.5 + 0.5*delta))/M_PI;

    if (A > 1 && t > 45) t = 90 - t;
    else if (A < 1 && t < 45) t = 90 - t;

    printf("%lf\n", t);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        printf("Case #%d: ", i+1);
        solve();
    }
    return 0;
}
