#include <bits/stdc++.h>

using namespace std;

const int MAX = 101;

string ans[MAX];

string fiboWord(int n) {
    if (n == 0) {
        return "0";
    }
    if (n == 1) {
        return "1";
    }
    if (ans[n] != "") {
        return ans[n];
        cout << ans[n] << endl;
    }
    else {
        ans[n] = fiboWord(n-1) + fiboWord(n-2);
    }
    return ans[n];
}
int main() {
    int n;
    n =30;
    for (int i = 0; i <= n; i++) {
        ans[i] = "";
    }

    ans[0] = "0";
    ans[1] = "1";
    fiboWord(n);
    cout << ans[n] << endl;
    return 0;
}