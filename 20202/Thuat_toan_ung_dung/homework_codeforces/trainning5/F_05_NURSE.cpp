#include <bits/stdc++.h>
#define MAX 405
using namespace std;

int n;
int l1;
int l2;
int a[MAX];
int x[MAX];
int sum = 0;

void input() {
    cin >> n >> l1 >> l2;
    a[1] = 0;
    int sign = l1;
    int i = 2;
    while(sign <= l2) {
        a[i] = sign;
        i++;
        sign++;
    }
}

void print_solution() {
    int i = 1;
    while(true) {
        cout << x[i] << " ";
        if (x[i] == 0 && x[i+1] == 0) {
            break;
        }
        i++;
    }
    cout << endl;
}
bool check(int v, int k) {
    if (x[k-1] == 0 && a[v] != 0) {
        return true;
    }
    else if (x[k-1] != 0 && a[v] == 0){
        return true;
    }

    return false;
}
void TRY(int k) {
    for (int v = 1; v <= l2; v++) {
        if (check(v, k)) {
            x[k] = a[v];
            if (a[v] == 0) {
                sum += 1;
            }
            else {
                sum += v;
            }
            if (sum == n) {
                print_solution();
            }
            else {
                if (sum < n) {
                    TRY(k+1);
                }
            }

            if (a[v] == 0) {
                sum -= 1;
            }
            else {
                sum -= v;
            }
        }
    }
}

int main() {
    input();
    for (int i = 1; i <= l2; i++) {
        x[1] = a[i];
        TRY(2);
    }

    return 0;
}