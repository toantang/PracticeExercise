#include <bits/stdc++.h>

using namespace std;

int countActiveBit(int number) {
    int cntActiveBit = 0;

    while(number != 0) {
        int val = number%2;
        if (val == 1) {
            cntActiveBit++;
        }
        number = number/2;
    }
    return cntActiveBit;
}
int nextNumber(int n) {
    int activeBitNum = countActiveBit(n);
    int value = n+1;
    while(true) {
        if (countActiveBit(value) == activeBitNum) {
            return value;
        }
        value++;
    }
}
int main() {
    int n;
    n = 5;
    //n = pow(10, 9);
    //n = 1260132;
    return 0;
}