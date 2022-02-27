#include <iostream>
using namespace std;

int n;
int X[100], Y[100];
int mark[100][100];

const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};

//# In ra dãy các di chuyển tìm được
void print_sol(){
    for (int j = 1; j <= n * n; ++j)
      cout << "(" << X[j] << " " << Y[j] << ")\n";
    exit(0);
}

//# Thuật toán quay lui
void TRY(int k){
    for(int i = 0; i < 8; i++){
        int xx = X[k-1] + hx[i];
        int yy = Y[k-1] + hy[i];

        if ( xx <1 || yy < 1 || xx > n || yy >n) continue;
        if (mark[xx][yy] == 1) continue;
        mark[xx][yy] = 1;
        X[k] = xx;
        Y[k] = yy;
        if (k == n*n)
            print_sol();
        else TRY(k+1);
        mark[xx][yy] = 0;

    }
}

int main(){
    //cout << "ho ten: Tang The Toan" << endl;
    //cout << "MSSV: 201839980" << endl;
    cin >> n;
    mark[1][1] = 1;
    X[1] = Y[1] = 1;
    TRY(2);
    return 0;
}
