def solve():
    import math
    C, F, X = map(float, raw_input().split())
    n = X / C - 2.0 / F
    n = max(int(math.floor(n)), 0)
    t = C * sum([1.0 / (2.0 + k * F) for k in xrange(n)]) + X / (2.0 + n * F)
    print t


if __name__ == '__main__':
    T = int(raw_input())
    for t in xrange(T):
        print 'Case #{0}:'.format(t + 1),
        solve()
