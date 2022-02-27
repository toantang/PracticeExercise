#include <bits/stdc++.h>

using namespace std;

int findSpecialNumber(int n, int k) {
    if (k==1 || k==2) return n;

    if (n==0) return 0;

    int a = log(n)/log(k);
    cout << "a = " << a << endl;
    long long b = (pow(k,a+1) - 1) / (k-1);
    cout << "b = " << b << endl;
    if (b < n) {
        return (long long) pow(k,a+1)%(long long)(pow(10,9)+7);
        }
    else {
        return (long long)(pow(k,a) + findSpecialNumber(n-pow(k,a),k) )%(long long)(pow(10,9)+7);
    }
}

int main() {
    int n, k;
    n = 8, k = 3;
    n = 17, k = 4;
    //n = 92, k = 13;
    cout << findSpecialNumber(n, k) << endl;
    return 0;
}