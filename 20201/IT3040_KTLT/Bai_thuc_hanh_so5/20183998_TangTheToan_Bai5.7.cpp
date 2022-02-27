
#include <bits/stdc++.h>
using namespace std;
int main(){
    cout << "ho ten: Tang The Toan" << endl;
    cout << "MSSV: 20183998" << endl;
    int n;
    cin >> n;
    int ans = 0, sum = 0;
    int k,t,a;
    while(n--){
        cin >> k >> t;
        while(k--){
            cin >> a;
            sum += t*a;
        }
        ans = max(ans, -sum);
    }
    cout << ans;
}
