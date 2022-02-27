#include <bits/stdc++.h>
#define MAX 1000003
using namespace std;

int n;
int a[MAX];
int ans = -1;
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
        if (best%2 == 0) {
            ans = max(ans, best);
        }
    }
}
int main() {
    input();
    solution();
    if (ans != -1) {
        cout << ans << endl;
    }
    else {
        cout << "NOT_FOUND" << endl;
    }
    return 0;
}