#include <stdio.h>

#define MAX_INPUT_LENGTH    1000
#define MAX_OUTPUT_LENGTH   10
#define ASCII_CODE_ZERO     0x30
#define ASCII_CODE_NINE     0x39

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char inputArr[MAX_INPUT_LENGTH] = {'\0', };
    int outputArr[MAX_OUTPUT_LENGTH] = {0, };

    scanf("%s", inputArr);

    for (int i = 0; i < MAX_INPUT_LENGTH && inputArr[i] != '\0'; i++) {
        if (inputArr[i] >= ASCII_CODE_ZERO && inputArr[i] <= ASCII_CODE_NINE) {
            outputArr[ inputArr[i] - ASCII_CODE_ZERO ]++;
        }
    }

    for (int i =0; i < MAX_OUTPUT_LENGTH; i++) {
        printf("%d ", outputArr[i]);
    }
    printf("\n");

    return 0;
}
