#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int n;
int m;
vector<int> edge[MAX];
bool visited[MAX];
int cnt = 0;

void input() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
}

void dfs(int u) {
    visited[u] = 1;
    for (int i = 0; i < edge[u].size(); i++) {
        int v = edge[u][i];
        cout << v << " ";
        if (visited[v] == true) {
            continue;
        }
        dfs(v);
    }
}
int main() {
    input();
    for (int i = 1; i <= n; ++i) {
        if(visited[i] == 0) {
            cnt++;
            cout << endl;
            cout << "i = " << i << endl;
            dfs(i);
        }
    }
    cout << cnt << endl;
    return 0;
}