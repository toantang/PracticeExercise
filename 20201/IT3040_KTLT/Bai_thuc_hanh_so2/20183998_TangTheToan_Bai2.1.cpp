#include <stdio.h>
#include <math.h>
float get_hypotenuse(float x, float y)
{
    return sqrt(x*x + y*y);
}
int main(){
    printf("ho ten: Tang The Toan\n");
    printf("MSSV: 20183998\n");
    float x, y;
    scanf("%f%f", &x, &y);

    float z = get_hypotenuse(x, y);
    printf("z = %.2f\n", z);

    return 0;
}
