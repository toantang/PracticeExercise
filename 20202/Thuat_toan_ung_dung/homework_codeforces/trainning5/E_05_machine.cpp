#include <bits/stdc++.h>
#define N 2000005

using namespace std;
int maxs[N];
int s[N];
int t[N];
int ans = -1;
int n = 0;


void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> t[i];
    }
}
int main() {
    input();
    for (int i = 1; i <= n; i++) {
        maxs[t[i]] = max(maxs[t[i]], t[i] - s[i]);
    }

    for (int i = 1; i < N; i++) {
        maxs[i] = max(maxs[i-1], maxs[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (maxs[s[i] - 1] > 0) {
            ans = max(ans, maxs[s[i] - 1] + t[i] - s[i]);
        }
    }

    cout << ans << endl;
    return 0;
}