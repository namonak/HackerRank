#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a = 0, b = 0;
    float c = 0.0f, d = 0.0f;

    scanf("%d %d", &a, &b);
    scanf("%f %f", &c, &d);

    printf("%d %d\n", a+b, a-b);
    printf("%0.1f %0.1f\n", c+d, c-d);

    return 0;
}
