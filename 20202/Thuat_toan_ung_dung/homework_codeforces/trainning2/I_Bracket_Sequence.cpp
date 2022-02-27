#include <bits/stdc++.h>

using namespace std;

int main() {
    stack<char> S;
    string s;
    cin >> s;
    int size = s.length();
    int ans = 0;
    if (s == "") {
        ans = 0;
    }
    else {
        S.push(s[0]);
        for (int i = 1; i < size; i++) {
            if (S.empty()) {
                S.push(s[i]);
            }
            else {
                char x = S.top();
                if (x == '[') {
                    if (s[i] == ']') {
                        S.pop();
                    }
                    else {
                        S.push(s[i]);
                    }
                }
                else if (x == '(') {
                    if (s[i] == ')') {
                        S.pop();
                    }
                    else {
                        S.push(s[i]);
                    }
                }
            }
        }
    }

    if (S.empty()) {
        ans = 1;
        cout << ans << endl;
        cout << s << endl;
    }
    else {
        ans = 0;
        cout << ans << endl;
    }
    return 0;
}