#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool color(const vector< vector<int> >& graph,
           vector<int>& mark,
           int i, int c)
{
    mark[i] = c;

    const vector<int>& nodes = graph[i];
    for (int j = 0; j < nodes.size(); ++j) {
        int k = nodes[j];
        if (mark[k] == -1) {
            if (!color(graph, mark, k, 1-c)) return false;
        } else if (mark[k] == c) return false;
    }

    return true;
}


void solve()
{
    int M;
    scanf("%d", &M);

    int N = 0;
    map<string, int> nameIndices;
    vector< vector<int> > graph(2*M);
    for (int i = 0; i < M; ++i) {
        string a, b;
        cin >> a >> b;

        int ind_a, ind_b;
        if (nameIndices.find(a) != nameIndices.end()) {
            ind_a = nameIndices[a];
        } else {
            nameIndices[a] = N;
            ind_a = N++;
        }

        if (nameIndices.find(b) != nameIndices.end()) {
            ind_b = nameIndices[b];
        } else {
            nameIndices[b] = N;
            ind_b = N++;
        }

        graph[ind_a].push_back(ind_b);
        graph[ind_b].push_back(ind_a);
    }

    vector<int> mark(N, -1);
    for (int i = 0; i < N; ++i) {
        if (mark[i] == -1) {
            if (!color(graph, mark, i, 0)) {
                printf("No\n");
                return;
            }
        }
    }

    printf("Yes\n");
}


int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        printf("Case #%d: ", i+1);
        solve();
    }
    return 0;
}
