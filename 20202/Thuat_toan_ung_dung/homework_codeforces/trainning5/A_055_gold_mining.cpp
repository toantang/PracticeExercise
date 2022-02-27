#include <bits/stdc++.h>
#define MAX 100002
using namespace std;

int n; // so kho vang
int a[MAX];
int l1;
int l2;

int ans = INT_MIN;
int f[MAX];

void input() {
    cin >> n >> l1 >> l2;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void solution() {
    for (int i = 0; i < n; i++) {
        f[i] = a[i];
    }
    for (int i = l1; i < n; i++) {
        for (int j = i - l2; j <= i - l1; j++) {
            if (j < 0) continue;
            f[i] = max(f[i], f[j] + a[i]);
            ans = max(ans, f[i]);
        }
    }
    /*for (int i = 0; i < n; i++) {
        ans = max(ans, f[i]);
    }*/
}

int main() {
    input();
    solution();
    cout << ans;
    return 0;
}