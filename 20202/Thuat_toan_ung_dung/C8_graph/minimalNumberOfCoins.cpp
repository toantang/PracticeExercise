#include <bits/stdc++.h>

using namespace std;

int minimalNumberOfCoins(vector<int> coins, int price) {
    int len = coins.size();
    int ans = 0;

    if (price == 0) {
        return 0;
    }
    if (len == 1) {
        if (price%coins[0] != 0) {
            return price/coins[0] + 1;
        }
        else {
            return price/coins[0];
        }
    }
    for (int i = len - 1; i >= 0; i--) {
        int val = price/coins[i];
        ans += val;
        price -= val * coins[i];
    }
    return ans;
}
int main() {
    return 0;
}