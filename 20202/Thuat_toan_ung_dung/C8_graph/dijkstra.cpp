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
int d[MAX]; // d[i] : độ dài đường đi hiện tại tới đỉnh i
bool visited[MAX];

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
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        A[i].push_back(Arc(0, 0));
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                A[i].push_back(Arc(j, 999));
            }
            else if (i == j){
                A[i].push_back(Arc(j, 0));
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w = 0;
        A[u].at(v) = Arc(v, w);
        cin >> u >> v >> w;
        A[u].push_back(Arc(v, w));
        A[v].push_back(Arc(u, w));
    }
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        d[i] = INT_MAX;
    }
}

void dijkstra(int u) {
    list<int> listVertex;
    for (int i = 1; i <= n; i++) {
        if (i != u) {
            listVertex.push_back(i);
        }
    }

    int len = A[u].size();
    for (int i = 0; i < len; i++) {
        int node = A[u].at(i).node;
        int w = A[u].at(i).w;
        for (int j = 1; j <= n; j++) {
            if (j == node) {
                d[node] = w;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
    cout << endl;
    
    int currentNode = u;
    while(!listVertex.empty()) {
        int minWeight = INT_MAX;
        int minNode = 0;

        list<int> copyListVertext(listVertex);
        cout << copyListVertext.size() << endl;
        while(!copyListVertext.empty()) {
            int f = copyListVertext.front();
            cout << f << " ";
            if (d[f] < minWeight) {
                minWeight = d[f];
                minNode = f;
            }
            copyListVertext.pop_front();
        }

        currentNode = minNode;
        cout << "currentNode = " << currentNode << endl;
        for (int i = 1; i <= n; i++) {
            if (d[i] > d[currentNode] + A[currentNode].at(i).w) {
                d[i] = d[currentNode] + A[currentNode].at(i).w;
            }
        }
        cout << "currentNode = " << currentNode << endl;
        listVertex.remove(currentNode);
    }
}
int main() {
    input();
    dijkstra(2);
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }

    return 0;
}