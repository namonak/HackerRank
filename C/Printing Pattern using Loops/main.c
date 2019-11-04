#include <stdio.h>

int main() 
{
    int n;
    int loop;
    scanf("%d", &n);
  	// Complete the code to print the pattern.

    loop = (n * 2) - 1;

    for (int i = 0; i < loop; i++) {
        printf("%d ", n);
    }
    printf("\n");

    return 0;
}
