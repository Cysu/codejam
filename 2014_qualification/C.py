def print_ans(ans):
    ans[-1][-1] = 'c'
    for i in xrange(len(ans)):
        print ''.join(ans[i])


def solve():
    r, c, m = map(int, raw_input().split())
    ans = [['.'] * c for __ in xrange(r)]
    print ''
    if r == 1 or c == 1:
        for i in xrange(r):
            for j in xrange(c):
                if m > 0:
                    ans[i][j] = '*'
                    m -= 1
        print_ans(ans)
        return

    if r * c - m == 2 or r * c - m == 3:
        print 'Impossible'
        return
    if r * c - m == 1:
        ans = [['*'] * c for __ in xrange(r)]
        print_ans(ans)
        return

    if r == 2 or c == 2:
        if m % 2 != 0:
            print 'Impossible'
        elif r == 2:
            for i in xrange(m // 2):
                ans[0][i] = ans[1][i] = '*'
            print_ans(ans)
        elif c == 2:
            for i in xrange(m // 2):
                ans[i][0] = ans[i][1] = '*'
            print_ans(ans)
        return

    if r * c - m >= 9:
        if r * c - m >= 3 * c:
            for i in xrange(r):
                if m == 0:
                    break
                elif m >= c:
                    ans[i] = ['*' for __ in xrange(c)]
                    m -= c
                elif m == c - 1:
                    for j in xrange(c - 2):
                        ans[i][j] = '*'
                    ans[i + 1][0] = '*'
                    m = 0
                else:
                    for j in xrange(m):
                        ans[i][j] = '*'
                    m = 0
        else:
            for i in xrange(r - 3):
                ans[i] = ['*' for __ in xrange(c)]
                m -= c
            for j in xrange(c):
                if m >= 3:
                    for i in xrange(r - 3, r):
                        ans[i][j] = '*'
                        m -= 1
                elif m == 2:
                    ans[r - 3][j] = ans[r - 3][j + 1] = '*'
                    break
                elif m == 1:
                    ans[r - 3][j] = '*'
                    break
                else:
                    break

        print_ans(ans)
    else:
        if r * c - m == 5 or r * c - m == 7:
            print 'Impossible'
            return

        ans = [['*'] * c for __ in xrange(r)]
        m = r * c - m
        if m == 1:
            ans[-1][-1] = '.'
        elif m == 8:
            ans[-1][-1] = ans[-1][-2] = ans[-1][-3] = '.'
            ans[-2][-1] = ans[-2][-2] = ans[-2][-3] = '.'
            ans[-3][-1] = ans[-3][-2] = '.'
        else:
            for i in xrange(1, m // 2 + 1):
                ans[-i][-1] = ans[-i][-2] = '.'
        print_ans(ans)


if __name__ == '__main__':
    T = int(raw_input())
    for t in xrange(T):
        print 'Case #{0}:'.format(t + 1),
        solve()
