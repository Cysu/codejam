def solve():
    K, C, S = map(int, raw_input().strip().split())
    assert K == S
    ret = [k * (K ** (C-1)) for k in xrange(1, K+1)]
    print ' '.join(map(str, ret))

if __name__ == '__main__':
    T = int(raw_input())
    for t in xrange(T):
        print 'Case #{0}:'.format(t + 1),
        solve()
