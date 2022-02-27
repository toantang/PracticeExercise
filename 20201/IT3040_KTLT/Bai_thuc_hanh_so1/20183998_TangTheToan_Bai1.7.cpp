#include <iostream>

using namespace std;

int *a;
int n, tmp;

int main()
{
    printf("ho ten: Tang The Toan\n");
    printf("MSSV: 20183998\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    a = new int[n];
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);

    printf("The input array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");

    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n- i -1; j++){
            if (*(a+j) > *(a+j+1)){
                int tmp = *(a+j);
                *(a+j) = *(a+j+1);
                *(a+j+1) = tmp;
            }
        }
    }

    printf("The sorted array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");

    delete [] a;
    return 0;
}
