#include <bits/stdc++.h>

using namespace std;

int digitsProduct(int product) {
    if (product == 0) {
        return 10;
    }
    if (product < 9) {
        return product;
    }

    vector<int> v;
    
    while(product != 0 && product >= 10) {
        bool sign = false;

        for (int i = 9; i >= 2; i--) {
            if (product%i == 0) {
                v.push_back(i);
                product = product/i;
                sign = true;
                break;
            }
        }
        if (sign == false) {
            return -1;
        }
    }

    if (product != 0) {
        v.push_back(product);
    }
    sort(v.begin(), v.end());
    string s;
    for (int i = 0; i < v.size(); i++) {
        s += v[i] + '0';
    }
    cout << endl;
    return atoi(s.c_str());
}

int main() {
    int product;
    product = 12;
    //product = 19;
    //product = 450;
    //product = 0; //true
    //product = 13; //true
    cout << digitsProduct(product);
    return 0;
}