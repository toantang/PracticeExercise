#include <bits/stdc++.h>
#define MAX 105
using namespace std;
int N;
int a[MAX];
int x[MAX]; //mang chua cac phan tu co tich am
int m, m1;
int y[MAX]; // mang chua cac phan tu co tich duong
int p, p1;
int z[MAX]; // mang chua cac phan tu co tich = 0
int q;

int cnt = 0;
void printArray(int x[], int len) {
    cout << len << " ";
    for (int i = 1; i <= len; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}
void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
}

void solution() {
    for (int i = 1; i <= N; i++) {
        if (a[i] == 0) {
            q++;
            z[q] = 0;
        }
        else if (a[i] < 0) {
            cnt++;
        }
    }
    int sptam = (cnt-1)/2;
    if (cnt > 1) {
        m = 1;
        p = N - m - q;
    }
    else {
        m = 1;
        p = 0;
    }

    for (int i = 1; i <= N; i++) {
        if (a[i] < 0) {
            if (m1 < m) {
                m1++;
                x[m1] = a[i];
            }
            else {
                p1++;
                y[p1] = a[i];
            }
        }
        else if (a[i] > 0) {
            if (p == 0) {
                p++;
                p1++;
                y[p1] = a[i];
            }
            else {
                p1++;
                y[p1] = a[i];
            }
        }
    }
}
int main() {
    input();
    solution();
    printArray(x, m);
    printArray(y, p);
    printArray(z, q);
    return 0;
}