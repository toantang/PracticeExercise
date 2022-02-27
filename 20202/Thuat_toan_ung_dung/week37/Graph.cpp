#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int a[MAX][MAX];
int n;
bool visited[MAX];

void solve() {
    for (int i = 0; i < MAX; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            a[i][j] = -1;
        }
    }
}
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (i != j) {
                a[i][j] = x;
                a[j][i] = x;
            }
            else {
                a[i][j] = 0;
            }
        }
    }
}

void print_graph() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
//tim bac cua mot dinh
int deg(int v) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[v][i] < 0) {
            cnt++;
        }
    }
    return cnt;
}

void DFS(int v) {
    stack<int> s;
    s.push(v);
    visited[v] = true;
    while(!s.empty()) {
        int x = s.top();
        cout << s.top() << " ";
        s.pop();
        for (int i = n; i >= 1; i--) {
            if (a[x][i] > 0 && visited[i] == false) {
                s.push(i);
                visited[x] = true;
            }
        }        
    }
}

void BFS(int v) {
    queue<int> s;
    s.push(v);
    //visited[v] = true;
    //cout << v << " ";
    while(!s.empty()) {
        int x = s.front();
        for (int i = 1; i <= n; i++) {
            if(a[x][i] > 0 && visited[i] == false) {
                s.push(i);
                visited[x] = true;
                visited[i] = true;
            }
        }
        cout << s.front() << " ";
        s.pop();
    }
}
int main() {
    solve();
    input();
    //print_graph();
    //print_graph();
    //DFS(1);
    BFS(1);
    return 0;
}