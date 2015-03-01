#include <cstdio>
#include <cstring>
#include <cstdint>
#include <iostream>

using namespace std;

int64_t mem[32][2][2][2];

int64_t f(int i, bool lessA, bool lessB, bool lessK,
          const int A, const int B, const int K)
{
    if (i < 0) {
        return lessA && lessB && lessK;
    }
    if (mem[i][lessA][lessB][lessK] >= 0) {
        return mem[i][lessA][lessB][lessK];
    }
    bool a = lessA || (((A >> i) & 1) == 1);
    bool b = lessB || (((B >> i) & 1) == 1);
    bool k = lessK || (((K >> i) & 1) == 1);
    int64_t ret = f(i-1, a, b, k, A, B, K);
    if (a) ret += f(i-1, lessA, b, k, A, B, K);
    if (b) ret += f(i-1, a, lessB, k, A, B, K);
    if (a && b && k) ret += f(i-1, lessA, lessB, lessK, A, B, K);
    mem[i][lessA][lessB][lessK] = ret;
    return ret;
}

void solve()
{
    int A, B, K;
    cin >> A >> B >> K;
    memset(mem, -1, sizeof(mem));
    cout << f(31, false, false, false, A, B, K) << endl;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
    }   
}
