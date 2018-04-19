#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_N 1000000
int main(int argc, char const *argv[])
{
    /* code */
    int num;
    while(scanf("%d\n", &num) != EOF)
    {
        // printf("Test: %d \n",num & 0b100000000000000000000);
        printf("Ans: %s \n",((num & 0b100000000000000000000) >> 20 == 1) ? "YES" : "NO");
    }
    return 0;
}
