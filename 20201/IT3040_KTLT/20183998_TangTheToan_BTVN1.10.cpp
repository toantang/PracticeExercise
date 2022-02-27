#include <iostream>

using namespace std;

double **makeMatrix(int n)
{
    double **arr = new double *[n];
    for (int i = 0; i < n; i++){
        *(arr+i) = new double[n];
    }
    return arr;
}

void input(double **matrix, int n)
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("matrix[%d][%d]: ", i, j);
            scanf("%lf", *(matrix+i) + j);
        }
    }
}

void output(double **matrix, int n)
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << *(*(matrix+i) + j) << "\t";
        }
        printf("\n");
    }
}

double **addMatrix(double **matrixA, double **matrixB, int n)
{
    double **matrixC = makeMatrix(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            *(*(matrixC + i) + j) = *(*(matrixA + i) + j) + *(*(matrixB + i) + j);
        }
    }
    return matrixC;
}

double **mulMatrix(double **matrixA, double **matrixB, int n)
{
    double **matrixD= makeMatrix(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            double sum = 0;
            for (int k = 0; k < n; k++){
                sum = sum + *(*(matrixA + i) + k) * *(*(matrixB + k) + j);
            }
            *(*(matrixD + i) + j) = sum;
        }
    }
    return matrixD;
}

void freeMatrix(double **matrix, int n)
{
    for (int i = 0; i < n; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main()
{
    printf("ho ten: Tang The Toan\n");
    printf("MSSV: 20183998\n");
    int n = 2;
    printf("Matrix A: \n");
    double **matrixA = makeMatrix(n);
    input(matrixA, n);
    output(matrixA, n);

    printf("Matrix B: \n");
    double **matrixB = makeMatrix(n);
    input(matrixB, n);
    output(matrixB, n);

    printf("tong 2 ma tran: \n");
    double **matrixC = addMatrix(matrixA, matrixB, n);
    output(matrixC, n);

    printf("tich 2 ma tran: \n");
    double **matrixD = mulMatrix(matrixA, matrixB, n);
    output(matrixD, n);
    return 0;
}
