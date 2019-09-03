#include <stdio.h>

void convertDigitToEnglish(int digit) {
    char numberArr[10][15] = {"zero, invalid", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    printf("%s\n", numberArr[digit]);
}

void isEvenOdd(int digit) {
    if (digit % 2 == 0) {
        printf("even\n");
        return;
    }
    printf("odd\n");
}

int main() 
{
    int a, b;    

    scanf("%d\n%d", &a, &b);
    // Complete the code.

    if (a == 0) {
        a = 1;
    }

    if (b >= 10) {
        b = 9;
    }

    for (int i = a; i <= b; i++) {
        convertDigitToEnglish(i);
    }

    for (int i = a; i <= b; i++) {
        isEvenOdd(i);
    }

    return 0;
}

