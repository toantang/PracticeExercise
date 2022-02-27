#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << "ho ten: Tang The Toan" << endl;
    cout << "MSSV: 20183998" << endl;
    int n;
    cin >> n;//co n nam trong danh sach
    bool found = false;
    while(n--){
        int a;
        cin >> a;
        if ((a % 4 == 0 && a % 100 != 0) || (a % 100 == 0))
        {
            found = true;
            break;
        }
    }
    if (found) cout << "Yes";
    else cout << "No";
}
