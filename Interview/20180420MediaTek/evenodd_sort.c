/*
給你一個8-bit的整數數列，要你找出這串數列的連續最長的1bit的長度和他的起始位置
ps. 255=11111111就是8個連續的1bit, 119=01110111有兩組連續3個1bit
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_N 1000000
void sort_increase() //i
{

}
void sort_decrease()
{

}
int main(int argc, char const *argv[])
{
    /* code */
    int total_n;
    scanf("%d\n", &total_n);
    int *odd_arr, *even_arr, *total_arr;
    total_arr = malloc(total_n * sizeof(int ));
    for(int i = 0; i < total_n; ++i)
    {
        scanf("%d", &total_arr[i]);
        printf("%d ", total_arr[i]);
    }
    return 0;
}
