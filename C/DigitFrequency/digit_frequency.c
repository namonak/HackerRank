#include <stdio.h>

#define MAX_INPUT_LENGTH    1000
#define MAX_OUTPUT_LENGTH   10
#define ASCII_CODE_ZERO     0x30
#define ASCII_CODE_NINE     0x39

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char inputArr[MAX_INPUT_LENGTH] = {'\0', };
    int outputArr[MAX_OUTPUT_LENGTH] = {0, };
    int i = 0;

    scanf("%s", inputArr);

    while(i < MAX_INPUT_LENGTH) {        
        if(inputArr[i] >= ASCII_CODE_ZERO && inputArr[i] <= ASCII_CODE_NINE) {
            outputArr[inputArr[i] - ASCII_CODE_ZERO]++;
        } else if(inputArr[i] == '\0') {
            break;
        }
        i++;
    }

    i = 0;

    while(i < MAX_OUTPUT_LENGTH) {
        printf("%d ", outputArr[i]);
        i++;
    }

    return 0;
}
