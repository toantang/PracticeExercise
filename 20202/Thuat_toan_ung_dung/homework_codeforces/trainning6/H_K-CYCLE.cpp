#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int n; // so dinh
int m; // so canh
int k;
int ans[MAX];
int answer = 0;

void input() {
    cin >> n >> m >> k;
    
    for (int i = 1; i <= n; i++) {
        ans[i] = 0;
    }
    
    int cnt = 1;
    while (cnt <= m)
    {
        int i, j;
        cin >> i >> j;
        ans[i] = ans[i] + 1;
        ans[j] = ans[j] + 1;
        cnt++;
    }
    
}

void solution() {
    for (int i = 1; i <= n; i++) {
        if (ans[i] == k) {
            answer = i;
            break;
        }
    }
}

int main() {
    input();
    solution();
    cout << answer << endl;
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}