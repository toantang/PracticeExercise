#include <bits/stdc++.h>

using namespace std;

const vector<int> c = {2,3,5,7,11,13,17,19,23,29,31,37,39,41,43,47};

int longestArray(std::vector<int> a) {
    int len = a.size();
    int lenC = c.size();

    int cntNum[lenC + 1];
    for (int i = 0; i < lenC; i++) {
        cntNum[i] = 0;
    }
    int ans = INT_MIN;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < lenC; j++) {
            if (a[i]%c[j] == 0) {
                cntNum[j]++;
            }
        }
    }

    for (int i = 0; i < lenC; i++) {
        if (cntNum[i] > ans) {
            ans = cntNum[i];
        }
    }
    return ans;
}

int main() {
    vector<int> a;
    a = {1, 2, 3, 4, 5, 6};
    cout << longestArray(a) << endl;
    return 0;
}