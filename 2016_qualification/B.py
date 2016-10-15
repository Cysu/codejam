def solve():
    s = raw_input().strip()
    n = 0
    i = 0
    while i < len(s):
        n += 1
        j = i
        while j < len(s) and s[j] == s[i]: j += 1
        i = j
    if (n % 2 == 0 and s[0] == '+') or (n % 2 == 1 and s[0] == '-'):
        print n
    else:
        print n - 1

if __name__ == '__main__':
    T = int(raw_input())
    for t in xrange(T):
        print 'Case #{0}:'.format(t + 1),
        solve()
