#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX_N 10000
int main(int argc, char const *argv[])
{
    char str[MAX_N] = {0};
    int pos = 0;
    while(scanf("%c",&str[pos++]) != EOF);
    char * reversed;
    reversed = malloc(pos *sizeof(char));
    for(int i = pos, j = 0; i >= 0; --i)
    {
        reversed[j++] = str[i];
    }
    printf("\nReversed string:");
    for(int i = 0; i < pos + 1; ++i)
    {
        printf("%c", reversed[i]);
    }
    return 0;
}
