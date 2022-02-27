#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

int n;
int m;
int a[MAX];
int b[MAX];
int f[MAX][MAX];
void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = 0;
        }
    }
}

int lcs() {
    for (int i = 1; i <= n; i++) {
        for (int  j = 1; j <= m; j++) {
        if (a[i] == b[j]) {
            f[i][j] = f[i-1][j-1] + 1;
        }
        else {
            f[i][j] = max(f[i-1][j], f[i][j-1]);
            } 
        }
    }
    return f[n][m];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    cout << lcs() << endl;
}