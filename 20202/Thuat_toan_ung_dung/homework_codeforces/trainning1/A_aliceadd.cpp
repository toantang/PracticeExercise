#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

string add(string a, string b)
{
    string ans = "";
    while(a.length() < b.length()) {
        a  = "0" + a;
    }
    while(b.length() < a.length()) {
        b = "0" + b;
    }
    int carry = 0;
    for (int i = a.length() - 1; i >= 0; i--) {
        int tmp = a[i] - 48 + b[i] - 48 + carry;
        carry = tmp/10;
        tmp = tmp%10;
        ans = (char)(tmp+48) + ans;
    }
    if (carry > 0) {
        ans = "1" + ans;
    }
    else {
        return ans;
    }
    return "";
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << add(a, b);
    return 0;
}
