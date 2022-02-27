#include <bits/stdc++.h>

using namespace std;

int candles(int a, int b) {
    int cnt = a;
    while(a >= b) {
        int val = a/b;
        cnt += val;
        a = a%b + val;
    }
    return cnt;
}
int main() {
    int a, b;
    a = 5, b = 2;
    cout << candles(a, b) << endl;
    return 0;
}