#include <bits/stdc++.h>
#define MAX 100
using namespace std;

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
vector<Arc> A[MAX]; // A[v] là 1 vector các cung kề với v

bool visited[MAX];
void printGraph() {
    for (int i = 1; i <= n; i++) {
        int len = A[i].size();
        for (int j = 0; j < len; j++) {
            cout << i << "->" << A[i].at(j).node << " = " << A[i].at(j).w << ", ";
        }
        cout << endl;
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w = 0;
        cin >> u >> v >> w;
        A[u].push_back(Arc(v, w));
        A[v].push_back(Arc(u, w));
    }
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
}

void DFSrecursion(int u) {
    visited[u] = true;
    int len = A[u].size();
    cout << u << " ";
    for (int i = 0; i < len; i++) {
        int node = A[u].at(i).node;
        int w = A[u].at(i).w;
        if (visited[node] == false) {
            DFSrecursion(node);
        }
    }
}

void DFS(int u) {
    stack<int> S;
    visited[u] = true;
    int len = A[u].size();
    for (int i = len-1; i >= 0; i--) {
        int node = A[u].at(i).node;
        visited[node] = true;
        S.push(node);
    }

    cout << u << " ";
    while(!S.empty()) {
        int currentTop = S.top();
        cout << currentTop << " ";
        visited[currentTop] = true;
        int len = A[currentTop].size();
        S.pop();
        for (int i = len-1; i >= 0; i--) {
            int node = A[currentTop].at(i).node;
            if (visited[node] == false) {
                S.push(node);
            }
        }
    }
}

void BFS(int u) {
    queue<int> S;
    cout << u << " ";
    visited[u] = true;
    int len = A[u].size();
    for (int i = 0; i < len; i++) {
        int node = A[u].at(i).node;
        visited[node] = true;
        S.push(node);     
    }

    while(!S.empty()) {
        int currentFront = S.front();
        cout << currentFront << " ";
        visited[currentFront] = true;
        S.pop();
        int length = A[currentFront].size();
        for (int i = 0; i < length; i++) {
            int nodeCurrent = A[currentFront].at(i).node;
            //cout << "currFront = " << currentFront << ", nodeCurrent = " << nodeCurrent << endl;
            if (visited[nodeCurrent] == false) {
                visited[nodeCurrent] = true;
                S.push(nodeCurrent);
                
            }
        }
    }
}

int main() {
    solve();
    //DFSrecursion(1);
    DFS(2);
    //BFS(1);
    //printGraph();
    return 0;
}