#include <iostream>

using namespace std;

int main()
{
    printf("ho ten: Tang The Toan\n");
    printf("MSSV: 20183998\n");
    int a[] = {1, 3, 4, 2};
    int size = sizeof(a)/sizeof(a[0]);
    for (int i = 0; i < size; i++){
        for (int j = i+1; j <= size; j++){
            for (int k = i; k < j; k++){
                printf("%d ", a[k]);
            }
            printf("\n");
        }
    }
    return 0;
}
