import numpy as np


def solve():
    n, a = raw_input().split()
    n = int(n)
    if n == 0:
        print 0
        return
    a = map(int, list(a))
    a = np.cumsum(a)[:-1]
    b = np.arange(1, n+1)
    print max(0, (b - a).max())


if __name__ == '__main__':
    T = int(raw_input())
    for t in xrange(T):
        print 'Case #{0}:'.format(t + 1),
        solve()
