#include <bits/stdc++.h>
using namespace std;

int x[16];
int T,n,H;

void solution(){
    for( int i = 0; i < n ; ++i) cout<<x[i];
    cout << endl;
}

void Try(int k, int count){
    if(k == n){
        if(count==H) solution();
        return;
    }

    if(count < H){
        for(int i = 0; i < 2; ++i){
        x[k] = i;
        Try(k+1,count+i);
        }
    }
    else{
        x[k] = 0;
        Try(k+1,count);
    }
}

int main(){
    cin >> T;
    for(int i = 0; i < T; ++i){
        cin>> n>> H;
        Try(0,0);
        cout << endl;
    }

}
