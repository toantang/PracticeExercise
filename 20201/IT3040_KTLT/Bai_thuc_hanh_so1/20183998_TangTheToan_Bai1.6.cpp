#include <iostream>
#include <stdio.h>

using namespace std;

void print(int a[], int size)
{
    for (int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
}
void reversearray(int arr[], int size)
{
    int l = 0, r = size - 1, tmp;
    int dao = 0;
    for (tmp = l; tmp < (r+1)/2; tmp++){
        dao = arr[tmp];
        arr[tmp] = arr[r-tmp];
        arr[r-tmp] = dao;
    }
}
void ptr_reversearray(int *arr, int size)
{
    int l = 0, r = size - 1, tmp;
    int dao = 0;
    for (tmp = l ; tmp < (r+1)/2; tmp++){
        dao = *(arr+tmp);
        *(arr+tmp) = *(arr+r-tmp);
        *(arr+r-tmp) = dao;
    }
}

int main()
{
    printf("ho ten: Tang The Toan\n");
    printf("MSSV: 20183998\n");
    int arr[] = {4, -1, 5, 9};
    int arr2[] = {9, 3, 5, 6, 2, 5};
    printf("mang truoc khi dao nguoc: ");
    print(arr2, 6);
    reversearray(arr2, 6);
    printf("\nmang sau khi dao nguoc: ");
    print(arr2, 6);

    cout << endl;

    int size = 4;
    printf("mang truoc khi dao nguoc: ");
    print(arr, size);
    ptr_reversearray(arr, size);
    printf("\nmang sau khi dao nguoc: ");
    print(arr, size);
    cout << endl;
    return 0;
}
