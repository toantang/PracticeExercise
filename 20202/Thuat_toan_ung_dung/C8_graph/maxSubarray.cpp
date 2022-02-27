#include <bits/stdc++.h>

using namespace std;

int maxSubarray(vector<int> inputArray) {
    int len = inputArray.size();
    int ans = INT_MIN;
    int best = INT_MIN;
    for (int i = 0; i < len; i++) {
        best = max(best + inputArray[i], inputArray[i]);
        ans = max(best, ans);
    }
    return ans;
}
int main() {
    return 0;
}