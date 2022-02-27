#include <bits/stdc++.h>
using namespace std;

int a[200];
int N;
int m1,m2;

void print_solution(){
    for (int i = 0; i < N; ++i) {
        cout << a[i];
    }
    printf("\n");
}

void Try(int k, int l){
    if(k>=N){
        if(l==0 || l>=m1)
        print_solution();
    }

    else{
        if(l<m1){
            a[k] = 1;
            Try(k+1,l+1);

        }
        else{
            if(l == m2){
                a[k] = 0;
                Try(k+1,0);
            }
            else{
                a[k] = 0;
                Try(k+1,0);
                a[k] = 1;
                Try(k+1,l+1);
            }
        }
    }
}

int main(){
    cin>>N>>m1>>m2;
    for(int i = 0; i < 2; ++i){
        a[0] = i;
        Try(1,a[0]);
    }
}
