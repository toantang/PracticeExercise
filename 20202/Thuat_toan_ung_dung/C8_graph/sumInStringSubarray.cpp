#include <bits/stdc++.h>

using namespace std;

int sumInStringSubarray(string s)
{ 
    vector<int> arr ;
    for (int i=0;i<(int) s.size();i++){
        arr.push_back(s[i]-'0');
    } 
    int sum=0 ;
    int n=arr.size() ;
    for (int i=0;i<n;i++) {
            sum+=arr[i]*(i+1)*(n-i) ;
    } 
    return sum ;
}
int main() {
    string s;
    s = "1234";
    cout << sumInStringSubarray(s);
    return 0;
}