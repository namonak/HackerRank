#include <stdio.h>

void printPattern(int a, int b) {
    int loop = a;

    for (int i = 1; i <= loop; i++) {
        printf("%d ", a);
        if (a != b) {
            a--;
        }
    }

    for (int j = 1; j <= loop - 1; j++) {
        if (j >= b) {
            a++;
        }
        printf("%d ", a);

    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.

    for (int i = n; i >= 1; i--) {
        printPattern(n, i);
    }

    return 0;
}
