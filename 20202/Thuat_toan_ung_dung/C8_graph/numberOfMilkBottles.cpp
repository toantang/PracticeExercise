#include <bits/stdc++.h>

using namespace std;

long long numberOfMilkBottles(int a, int b, long long c) {
    long long count = 0;
    while(c > a) {
        count += c/a;
        c = (c/a) * b + c%a;
    }
    return count;
}
int main() {
    return 0;
}