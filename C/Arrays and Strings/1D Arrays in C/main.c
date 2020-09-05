#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int count = 0;
    int *arr = NULL;
    int sum = 0;

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d", &count);
    if (count <= 0 || count > 1000) {
        return -1;
    }

    arr = (int*)malloc(sizeof(int) * count);
    if (arr == NULL) {
        return -1;
    }

    for (int i = 0; i < count; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] <= 0 || arr[i] > 1000) {
            return -1;
        }
        sum += arr[i];
    }

    printf("%d\n", sum);

    free(arr);

    return 0;
}
