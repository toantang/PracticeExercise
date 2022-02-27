#include <bits/stdc++.h>

using namespace std;

bool primeSquare(long long a, long long b) {
    if (a - b > 1 || a <= b || a <= 0 || b <= 0) {
        return false;
    }
    else {
        for (long long i = 2; i <= sqrt(a+b); i++) {
            if ((a+b) % i == 0) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    long long a[] = {6, 7, 34, 394958, 12346, 6};
    long long b[] = {5, 5, 33, 38434855, 12345, 3};
    for (int i = 0; i < 6; i++) {
        cout << primeSquare(a[i], b[i]) << endl;;
    }
    return 0;
}