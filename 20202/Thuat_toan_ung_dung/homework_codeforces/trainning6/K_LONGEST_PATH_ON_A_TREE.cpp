#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int node;
    int w;
}edge;

void BFS(int u) {
    queue<int> Q;
    d[u] = 0;
    Q.push(u);

    while(!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int i = 0; i < A[v].size(); i++) {
            Edge e = A[v][i];
            int x = e.node;
            if(p[v] == x) continue;
            int w = e.w;
            Q.push(x);
            d[x] = d[v] + w;
            p[x] = v;
        }
    }
}

int main() {
    return 0;
}