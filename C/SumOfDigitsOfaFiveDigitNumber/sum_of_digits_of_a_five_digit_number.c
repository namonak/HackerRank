#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    int sum = 0;

    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.

    while(n) {
        sum += n % 10;
        n /= 10;
    }
    printf("%d\n", sum);

    return 0;
}
