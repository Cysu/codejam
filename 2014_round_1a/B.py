import sys
sys.setrecursionlimit(1500)


def solve():
    n = int(raw_input())
    graph = [[] for __ in xrange(n)]
    for i in xrange(n - 1):
        u, v = map(lambda x: int(x) - 1, raw_input().split())
        graph[u].append(v)
        graph[v].append(u)

    def search(u, father):
        s = [search(v, u) for v in graph[u] if v != father]
        s.sort()
        return 1 if len(s) < 2 else s[-1] + s[-2] + 1

    best = max([search(root, -1) for root in xrange(n)])
    print '{0}'.format(n - best)


if __name__ == '__main__':
    T = int(raw_input())
    for t in xrange(T):
        print 'Case #{0}:'.format(t + 1),
        solve()
