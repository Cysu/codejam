import numpy as np

def solve():
    n = int(raw_input())
    a = [raw_input() for __ in xrange(n)]
    a.sort()
    b = [len(set(x.replace(' ', ''))) for x in a]
    print a[np.argmax(b)]

if __name__ == '__main__':
    T = int(raw_input())
    for t in xrange(T):
        print 'Case #{0}:'.format(t + 1),
        solve()
