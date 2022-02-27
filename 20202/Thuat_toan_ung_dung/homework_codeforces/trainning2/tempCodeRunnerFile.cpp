#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int n;
int a[MAX];
int ans[MAX];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans[i] = -1;
    }
}

void solution() {
    int minFromStart[n+1];
    minFromStart[n] = a[n];
    for (int i = n-1; i >= 1; i--) {
        minFromStart[i] = min(minFromStart[i+1], a[i]);
    }
    for (int i = 1; i <= n; i++) {
        cout << minFromStart[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = n; j > i; j--) {
            if (a[i] > a[j]) {
                ans[i] = j - i - 1;
                break;
            }
        }
    }
}

int main() {
    input();
    solution();
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}