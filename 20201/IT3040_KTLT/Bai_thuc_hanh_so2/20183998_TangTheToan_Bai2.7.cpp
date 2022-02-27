#include <iostream>
#include <math.h>
#include <stdio.h>
#include <ostream>
#include <iomanip>
using namespace std;

template <typename T>
T arr_sum(T a[], int sizeA, T b[], int sizeB)
{
    T sum = 0;
    if (sizeA > sizeB){
        for (int i = 0; i < sizeA; i++){
            if (i >= sizeB){
                sum = sum + a[i];
            }
            else {
                sum = sum + a[i] + b[i];
            }
        }
    }
    else {
        for (int i = 0; i < sizeB; i++){
            if (i >= sizeA){
                sum = sum + b[i];
            }
            else {
                sum = sum + a[i] + b[i];
            }
        }
    }
    return sum;
}

int main() {
    printf("ho ten: Tang The Toan\n");
    printf("MSSV: 20183998\n");
    int val;
    cin >> val;

    {
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }

    {
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }

    return 0;
}
