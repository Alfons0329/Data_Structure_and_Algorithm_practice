#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX_N 10000
void int_2_bin(int num)
{
    while(num)
    {
        if(num & 1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        num >>= 1;
    }
}
int main()
{
    char encoded[MAX_N] = {-1};
    scanf("%s ", &encoded);
    // for(int i = 0; i < MAX_N; ++i)
    // {
    //     printf("%d ", encoded[i]);
    // }
    for(int i = 0; i < MAX_N; ++i)
    {
        int_2_bin(encoded[i]);
        if(!encoded[i])
        {
            break;
        }
    }
    return 0;
}
