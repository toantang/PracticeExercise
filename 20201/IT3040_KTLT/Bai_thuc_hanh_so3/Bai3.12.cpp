
#include<bits/stdc++.h>
using namespace std;

#define MAX_N 31

int x[MAX_N][MAX_N], mark[MAX_N];
int n,k,m;
int dem = 0;
void dfs(int u, int s){
    if(s==k) ++dem;
    else{
        mark[u] = 1;
        for(int i = 1; i <= n; ++i){
            if(x[u][i]==1 && mark[i]==0){
                dfs(i,s+1);
            }
        }
        mark[u] = 0;
    }
}

int main(){
    cin>>n>>k>>m;
    for(int i = 1; i <= n ; ++i) {
        mark[i] = 0;
    }

    for(int i = 1; i <= n; ++i ){
        for(int j = 1; j <= n ; ++j){
            x[i][j] = 0;
        }
    }

    for(int i = 0; i < m; ++i){
        int u,v;
        cin>>u>>v;
        x[u][v] = x[v][u] = 1;
    }

    for(int i = 1; i <= n ; ++i){
        dfs(i,0);
    }
    dem = dem/2;
    cout<<dem<<endl;
}
