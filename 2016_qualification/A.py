def solve():
    N = int(raw_input())
    if N == 0:
        print 'INSOMNIA'
    else:
        seen = set(xrange(10))
        n = N
        while True:
            digits = set(int(d) for d in str(n))
            seen = seen - digits
            if len(seen) == 0: break
            n += N
        print n

if __name__ == '__main__':
    T = int(raw_input())
    for t in xrange(T):
        print 'Case #{0}:'.format(t + 1),
        solve()
