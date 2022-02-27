#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

int n;
int a[MAX];
int f[MAX];

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void print_array() {
    for (int i = 0; i < n; i++) {
        cout << f[i] << " ";
    }
    cout << endl;
}
void solution() {
    f[0] = a[0];
    for (int i = 1; i < n; i++) {
        f[i] = min(a[i], f[i-1]);
    }
}
int main() {
    input();
    solution();
    print_array();
    return 0;
}