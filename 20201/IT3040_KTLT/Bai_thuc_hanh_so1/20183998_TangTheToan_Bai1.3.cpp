#include <iostream>

using namespace std;

int main()
{
    printf("ho ten: Tang The Toan\n");
    printf("MMSV: 20183998\n");
    int x, y, z;
    int *ptr;
    scanf("%d %d %d", &x, &y, &z);
    printf("Here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);

    ptr = &x;
    x = *ptr + 100;
    ptr = &y;
    y =  *ptr + 100;
    ptr = &z;
    z = *ptr + 100;
    printf("Once again, here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);
    return 0;
}
