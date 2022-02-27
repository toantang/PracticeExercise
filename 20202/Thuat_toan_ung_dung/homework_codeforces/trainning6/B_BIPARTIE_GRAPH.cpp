#include <bits/stdc++.h> 

using namespace std;

const int N = 1e5 + 1;
int n; // so dinh
int m; //so canh
vector<int> A[N];
int d[N]; // mức cua cac dinh
int ans = 1;

void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}


void init() {
    for (int v = 1; v <= n; v++) {
        d[v] = -1;
    }
}


bool bfs(int u) {
    queue<int> Q;
    Q.push(u);
    d[u] = 0;
    while(!Q.empty()) {
        int x = Q.front();
        Q.pop();
        for (int i = 0; i < A[x].size(); i++) {
            int v = A[x][i];
            if (d[v] == -1) {
                d[v] = d[x] + 1;
                Q.push(v);
            }
            else {
                if((d[v] + d[x]) % 2 == 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

void solve() {
    init();
    for (int v = 1; v <= n; v++) {
        if (d[v] == -1) {
            bool ok = bfs(v);
            if (!ok) {
                ans = 0;
                break;
            }
        }
    }
    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    input();
    init();
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
    cout << endl;
    bfs(1);
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
    cout << endl;
    //solve();
    return 0;
}