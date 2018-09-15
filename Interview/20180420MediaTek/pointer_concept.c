#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_N 1000000
int main(int argc, char const *argv[])
{
    int a = 5;
    int *c = &a;
    printf("c addr %p\n", c);
    // c = 8; //wrong(make p point to addr 0x8 but nothin  in that address, so crash)
    // printf("c addr %p\n", c, a);
    // printf("c value %d\n", *c);//segfault
    *c = 8; //correct
    printf("c addr %p\n", c);
    printf("c value %d\n", *c);//no segfault
    return 0;
}
