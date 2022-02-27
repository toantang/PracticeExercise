#include <stack>
#include <string>
#include <iostream>
#define MAX 1000

using namespace std;

stack<char> S;
string a[MAX];
int n;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[i] = s;
    }
}
int solution(string s) {
    stack<char> st;

    for (auto c : s) {
        switch (c) {
        case '{':
        case '(':
        case '[':
            st.push(c);
            break;
        case '}':
            if (st.empty() || (st.top() != '{')) {
                return 0;
            }
            st.pop();
            break;
        case ')':
            if (st.empty() || (st.top() != '(')) {
                return 0;
            }
            st.pop();
            break;
        case ']':
            if (st.empty() || (st.top() != '[')) {
                return 0;
            }
            st.pop();
            break;
        }
    }

    return st.empty() ? 1 : 0;
}


int main() {
    input();    
    for (int i = 0; i < n; i++) {
        cout << solution(a[i]) << endl;
    }
    return 0;
}