#include <bits/stdc++.h>

using namespace std;

int onesAndZeros(string s) {
    int len = s.size();
    int cntZero, cntOne;
    cntZero = 0, cntOne = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '0') {
            cntZero++;
        }
        else {
            cntOne++;
        }
    }
    return abs(cntZero - cntOne);
}
int main() {
    return 0;
}