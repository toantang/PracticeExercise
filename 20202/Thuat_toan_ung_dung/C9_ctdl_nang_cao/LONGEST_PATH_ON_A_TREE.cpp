#include <bits/stdc++.h>
#define MAX_N 100001
using namespace std;

struct Edge {
    int node; // u->node = w
    int w;
    Edge(int _node, int _w) {
        node = _node;
        w = _w;
    }
};

int N;
vector<Edge> A[MAX_N];
int d[MAX_N]; // d[v] is khoang cach tu source node to v BFS
int p[MAX_N]; // P[V] is the parent of v by BFS

void input() {
    cin >> N;
    for (int i = 1; i <= N-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        A[v].push_back(Edge(u, w));
        A[u].push_back(Edge(v, w));
    }
}

void init() {
    for (int v = 1; v <= N; v++) {
        d[v] = -1;
        p[v] = -1;
    }
}

void BFS(int u) {
    queue<int> Q;
    d[u] = 0;
    Q.push(u);

    while(!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int i = 0; i < A[v].size(); i++) {
            Edge e = A[v][i];
            int node = e.node;
            int w = e.w;
            if (p[v] == node) {
                continue;
            }
            Q.push(node);
            d[node] = d[v] + w;
            p[node] = v;
        }
    }
}

int findMax() {
    int max_d = -1;
    int u = -1;
    for (int v = 1; v <= N; v++) {
        if (max_d < d[v]) {
            max_d = d[v];
            u = v;
        }
    }

    return u;
}

void solve() {
    init();
    BFS(1);
    int x = findMax();
    init();
    BFS(x);
    int y = findMax();
    cout << d[y] << endl;
}
int main() {
    input();
    solve();
    return 0;
}