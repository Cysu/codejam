def get_diff(a, b):
    return [i for i in xrange(len(a)) if a[i] != b[i]]


def flip(o, bits):
    o = list(o)
    for i in bits:
        o[i] = '0' if o[i] == '1' else '1'
    return ''.join(o)


def is_equal(outputs, targets):
    for o, t in zip(outputs, targets):
        if o != t:
            return False
    return True


def solve():
    m, n = map(int, raw_input().split())
    outputs = raw_input().split()
    targets = raw_input().split()
    targets.sort()

    best = n + 1
    for i in xrange(m):
        bits = get_diff(outputs[i], targets[0])
        if len(bits) >= best:
            continue
        flipped_outputs = [flip(o, bits) for o in outputs]
        flipped_outputs.sort()
        if is_equal(flipped_outputs, targets):
            best = len(bits)

    if best == n + 1:
        print 'NOT POSSIBLE'
    else:
        print best


if __name__ == '__main__':
    T = int(raw_input())
    for t in xrange(T):
        print 'Case #{0}:'.format(t + 1),
        solve()
