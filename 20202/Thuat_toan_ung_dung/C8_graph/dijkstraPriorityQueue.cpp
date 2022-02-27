#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
const int INF = 1e9;

struct Arc {
    int node; // đỉnh kề của đỉnh hiện tại
    int w; // trọng số của cạnh
    Arc(int _node, int _w) {
        node = _node;
        w = _w;
    }
};
int n; // so dinh
int m; // so cung
vector<Arc> A[N]; // A[v] là 1 vector các cung kề với v

int s, t;
int d[N]; // d[i] : độ dài đường đi hiện tại tới đỉnh i

void printGraph() {
    cout << endl;
    for (int i = 1; i <= n; i++) {
        int len = A[i].size();
        for (int j = 0; j < len; j++) {
            cout << i << "->" << A[i].at(j).node << " = " << A[i].at(j).w << ", ";
        }
        cout << endl;
    }
}

void input() {
    cin >> n  >> m;
    for (int i = 1; i <= n; i++) {
        A[i].push_back(Arc(0, 0));
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                A[i].push_back(Arc(j, INF));
            }
            else if (i == j){
                A[i].push_back(Arc(j, 0));
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        A[u].at(v) = Arc(v, w);
    }

    cin >> s >> t;
}
void solve() {
    for (int v = 1; v <= n; v++) {
        d[v] = INF;
    }
}

void dijkstraPriorityQueue() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[s] = 0;
    pq.push(make_pair(d[s], s));
    while(!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        int u = p.second;
        if(u == t) {
            break;
        }
        for (int i = 0; i < A[u].size(); i++) {
            Arc a = A[u][i];
            int v = a.node;
            int w = a.w;
            if (w + d[u] < d[v]) {
                d[v] = d[u] + w;
                pq.push(make_pair(d[v], v));
            }
        }
    }
}
int main() {
    input();
    solve();
    dijkstraPriorityQueue();
    cout << d[t] << endl;
    return 0;
}