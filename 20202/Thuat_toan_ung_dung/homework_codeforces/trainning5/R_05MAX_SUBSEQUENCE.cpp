#include <bits/stdc++.h>
#define MAX 1000006
using namespace std;

int n;
int a[MAX];
int ans;
int best;

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

void solution() {
    for (int i = 1; i <= n; i++) {
        best = max(a[i], best + a[i]);
        ans = max(ans, best);
    }
}
int main() {
    input();
    solution();
    cout << ans << endl;
    return 0;
}