def solve():
    n = int(raw_input()) - 1
    a = [map(int, raw_input().split()) for __ in xrange(4)]
    m = int(raw_input()) - 1
    b = [map(int, raw_input().split()) for __ in xrange(4)]
    a = set(a[n])
    b = set(b[m])
    c = (a & b)
    if len(c) == 1:
        print c.pop()
    elif len(c) > 1:
        print 'Bad magician!'
    else:
        print 'Volunteer cheated!'

if __name__ == '__main__':
    T = int(raw_input())
    for t in xrange(T):
        print 'Case #{0}:'.format(t + 1),
        solve()
