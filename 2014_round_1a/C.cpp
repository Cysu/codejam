#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1000;

double f[MAXN][MAXN];
double r[MAXN];

void compute_f()
{
    int n = MAXN;
    memset(f, 0, sizeof(f));

    const double p = 1.0 / n;
    const double q = 1.0 - p;

    for (int i = 0; i < n; ++i) f[i][i] = 1.0;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            memset(r, 0, sizeof(r));
            for (int j = 0; j < n; ++j) {
                r[k] += f[i][j];
            }
            r[k] *= p;
            for (int j = 0; j < n; ++j) {
                if (k == j) continue;
                r[j] = f[i][j] * q + f[i][k] * p;
            }
            memcpy(f[i], r, sizeof(r));
       }
    }
}

void solve()
{
    int n;
    cin >> n;

    double prob = 1.0;
    int a;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        prob *= f[a][i] * n;
    }

    if (prob > 1.0) cout << "BAD" << endl;
    else cout << "GOOD" << endl;
}


int main()
{
    compute_f();
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
    }
}

