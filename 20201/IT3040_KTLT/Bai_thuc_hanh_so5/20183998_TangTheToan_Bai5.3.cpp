#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

int par(string str){
    int a = str.length();
    printf("a = %d\n", a);
    stack<char> S;
    char x, y;
    for (int i=0; i<a; i++){
        x = str[i];
        printf("x[%d] = %c\n", i, str[i]);
        if (x == '(' || x == '[' || x == '{'){
            S.push(x);
        }
        else {
            if (x == ')') {
                if (S.top() == '('){
                    S.pop();
                }
                else return 0;
            }
            else if (x == ']') {
                if (S.top() == '['){
                    S.pop();
                }
                else return 0;
            }
            else if (x == '}') {
                if (S.top() == '{'){
                    S.pop();
                }
                else return 0;
            }
        }
    }
    if (S.empty()){
        return 0;
    }
    else {
        return 1;
    }
}

int main(){
    cout << "ho ten: Tang The Toan" << endl;
    cout << "MSSV: 20183998" << endl;
    int n;
    string str = "()()()";
    //par(str);
    cout << par(str) << endl;
    //cin >> n;
    /*for(int i=0; i<n; i++){
        cin >> str;
        cout << par(str) << endl;
    }*/

    return 0;
}
