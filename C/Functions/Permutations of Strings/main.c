#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
    int i, j, k;
    char *tmp;

    i = n - 1;
    while (i > 0 && strcmp(s[i], s[i - 1]) <= 0)
        i--;
    if (i <= 0)
        return 0;
    j = n - 1;
    while (strcmp(s[j], s[i - 1]) <= 0)
        j--;
    tmp = s[i - 1];
    s[i - 1] = s[j];
    s[j] = tmp;
    k = n - 1;
    while (i < k)
    {
        tmp = s[i];
        s[i] = s[k];
        s[k] = tmp;
        i++;
        k--;
    }
    return 1;
}

int main()
{
    char **s;
    int n;
    scanf("%d", &n);
    s = calloc(n, sizeof(char*));
    for (int i = 0; i < n; i++)
    {
        s[i] = calloc(11, sizeof(char));
        scanf("%s", s[i]);
    }
    do
    {
        for (int i = 0; i < n; i++)
            printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');

    } while (next_permutation(n, s));
    for (int i = 0; i < n; i++)
        free(s[i]);
    free(s);
    return 0;
}
