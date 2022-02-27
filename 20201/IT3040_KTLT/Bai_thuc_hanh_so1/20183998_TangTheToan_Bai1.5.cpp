#include <iostream>

using namespace std;

double* maximum(double* a, int size){
    double *max;
    max = a;
    if (a==NULL) return NULL;
    for (int i = 0; i < size; i++){
        if (*max < *(a+i)){
            max = a+i;
        }
    }
    return max;
}
int main()
{
    printf("ho ten: Tang The Toan\n");
    printf("MMSV: 20183998\n");
    double a[] = {25.4651, 4, 16, 9};
    int size = sizeof(a)/sizeof(a[0]);
    double *max;
    max = maximum(a, size);
    printf("%g ", *max);
    return 0;
}
