#include <bits/stdc++.h>

using namespace std;

const int MAX = 20;
int c[MAX][MAX];
int n, m;
bool visited[MAX];

void input() {
    cin >> n >> m;
     for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            c[i][j] = 0;
        }
    }

    
    for (int v = 1; v <= m; v++) {
        int x, y, val;
        cin >> x >> y >> val;
        c[x][y] = val;
        c[y][x] = val;
    }
}


void DFS(int u) {
    stack<int> S;
    cout << u << " ";
    visited[u] = true;
    for (int i = n; i >= 1; i--) {
        if (c[u][i] != 0) {
            S.push(i);
            visited[i] = true;
        }
    }

    while(!S.empty()) {
        int currentTop = S.top();
        visited[currentTop] = true;
        cout << currentTop << " ";
        S.pop();
        for (int i = n; i >= 1; i--) {
            if (c[currentTop][i] != 0 && visited[i] == false) {
                S.push(i);
            }
        }
    }
}


void solution() {
    stack<int> s;

}
int main() {
    input();
    DFS(2);
    return 0;
}