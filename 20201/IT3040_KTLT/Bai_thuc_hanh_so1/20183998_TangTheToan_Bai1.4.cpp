#include <iostream>

using namespace std;

int counteven(int* arr, int size){
    int count = 0;
    for (int i = 0; i < size; i++){
        if (*(arr+i) % 2 == 0){
            count++;
        }
    }

    return count;
}
int main()
{
    printf("ho ten: Tang The Toan\n");
    printf("MMSV: 20183998\n");
    int arr[] = {3, 5, 2, 8, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("%d ", counteven(arr, size));
    return 0;
}
