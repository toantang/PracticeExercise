#include <iostream>
#include <stdio.h>

using namespace std;

void allocate_mem(int ***mt, int m, int n){
    *mt = new int*[m];
    for (int i = 0; i < m; i++){
        (*mt)[i] = new int[n];
    }
}

void input(int **mt, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("mt[%d][%d] = ", i, j);
            scanf("%d", *(mt+i) + j);
        }
    }
}

void output(int **mt, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", *(*(mt+i) + j));
        }
        cout << endl;
    }

}

int process(int **mt, int m, int n){
    int tong = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (*(*(mt+i) + j) % 2 == 0){
                tong = tong + *(*(mt+i) + j);
            }
        }
    }
    return tong;
}

void free_mem(int **mt, int m, int n){
    for (int i = 0; i < m; i++){
        delete[] mt[i];
    }
    delete[] mt;
}

int main(){
    printf("ho ten: Tang The Toan\n");
    printf("MSSV: 20183998\n");
    int m, n, **mt;
    printf("Enter m, n = ");
    scanf("%d%d", &m, &n);
    allocate_mem(&mt, m, n);
    input(mt, m, n);
    output(mt, m, n);
    printf("The sum of all even elements is %d", process(mt, m, n));
    free_mem(mt, m, n);
    return 0;
}

