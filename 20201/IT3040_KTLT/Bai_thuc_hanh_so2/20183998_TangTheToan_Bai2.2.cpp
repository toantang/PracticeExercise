#include <iostream>

using namespace std;

void rotate(int &x, int &y, int &z)
{
    int temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    printf("ho ten: Tang The Toan\n");
    printf("MSSV: 20183998\n");
    int x, y, z;
    scanf("%d%d%d", &x, &y,&z);
    printf("Before: %d, %d, %d\n", x, y, z);
    rotate(x, y, z);
    printf("After: %d, %d, %d\n", x, y, z);

    return 0;
}
