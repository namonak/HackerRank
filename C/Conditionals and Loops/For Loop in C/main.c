#include <stdio.h>

int main() 
{
    int a, b;
    char *numArr[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    scanf("%d\n%d", &a, &b);
    // Complete the code.

    for (; a <= b; a++) {
        if (a < 10) {
            printf("%s\n", numArr[a - 1]);
        } else if (a % 2 == 0) {
            printf("even\n");
        } else {
            printf("odd\n");
        }
    }

    return 0;
}
