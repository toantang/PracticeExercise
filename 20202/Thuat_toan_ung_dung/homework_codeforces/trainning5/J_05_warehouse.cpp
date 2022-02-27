#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int n; // so nha kho
int T; // thời gian xe tải chờ tối đa
int D; // khoảng cách tối đa giữa 2 trạm
int a[MAX];
int t[MAX];
int dp[MAX][MAX];
int ans = -1;

void input() {
    cin >> n >> T >> D;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
}

void solution() {
    for (int i = 1; i <= n; i++) {
        for (int k = t[i]; k <= T; k++) {
            for (int j = i - 1; j >= max(0, i-D); j--) {
                dp[i][k] = max(dp[i][k], dp[j][k - t[i]] + a[i]);
            }
            ans = max(ans, dp[i][k]);
        }
    }
}
int main() {
    input();
    solution();
    cout << ans << endl;
    return 0;
}