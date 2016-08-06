import numpy as np


def solve():
    n = int(raw_input())
    a = map(int, raw_input().split())
    best = np.inf
    for m in xrange(1, max(a) + 1):
        t = 0
        for ai in a:
            t += (ai - 1) // m
        if m + t < best:
            best = m + t
    print best


if __name__ == '__main__':
    T = int(raw_input())
    for t in xrange(T):
        print 'Case #{0}:'.format(t + 1),
        solve()
