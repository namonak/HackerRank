#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
    //Write your code here.
    int and = 0, maxAND = 0;
    int or = 0, maxOR = 0;
    int xor = 0, maxXOR = 0;

    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            and = i & j;
            or = i | j;
            xor = i ^ j;
            if ( (maxAND < and) && (k > and) ) maxAND = and;
            if ( (maxOR < or) && (k > or) ) maxOR = or;
            if ( (maxXOR < xor) && (k > xor) ) maxXOR = xor;
        }
    }

    printf("%d\n%d\n%d\n", maxAND, maxOR, maxXOR);
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);

    return 0;
}
