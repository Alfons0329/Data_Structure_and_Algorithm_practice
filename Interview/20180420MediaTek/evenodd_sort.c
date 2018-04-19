/*
even odd sort
給你一個n，接下來有n個整數，對他們排序使得
(1) 偶數在奇數前面
(2) 偶數遞減排序、奇數遞增排序
然後輸出這個數列
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_N 1000000
void sort_increase(int *odd_arr, int odd_n) //i
{
    for(int i = odd_n - 1; i >=1 ; --i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(odd_arr[j] > odd_arr[j+1])
            {
                odd_arr[j] ^= odd_arr[j+1];
                odd_arr[j+1] ^= odd_arr[j];
                odd_arr[j] ^= odd_arr[j+1];
            }
        }
    }
}
void sort_decrease(int *even_arr, int even_n)
{
    for(int i = even_n - 1; i >=1 ; --i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(even_arr[j] < even_arr[j+1])
            {
                even_arr[j] ^= even_arr[j+1];
                even_arr[j+1] ^= even_arr[j];
                even_arr[j] ^= even_arr[j+1];
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    //preprocessing
    int total_n, odd_n = 0, even_n = 0;
    scanf("%d\n", &total_n);
    int *odd_arr, *even_arr, *total_arr;
    total_arr = malloc(total_n * sizeof(int ));
    for(int i = 0; i < total_n; ++i)
    {
        scanf("%d", &total_arr[i]);
        if(total_arr[i] & 1) //is odd
        {
            ++odd_n;
        }
        else
        {
            ++even_n;
        }
    }
    even_arr = malloc(even_n * sizeof(int ));
    odd_arr = malloc(odd_n * sizeof(int ));
    int odd_cur = 0, even_cur = 0;//current position for push back
    for(int i = 0; i < total_n; ++i)
    {
        if(total_arr[i] & 1) //is odd
        {
            odd_arr[odd_cur++] = total_arr[i];
        }
        else
        {
            even_arr[even_cur++] = total_arr[i];
        }
    }
    //doing sort separately
    printf("even_n %d, odd_n %d \n", even_n, odd_n);
    sort_increase(odd_arr, odd_n);
    sort_decrease(even_arr, even_n);
    //put back, even first
    for(int i = 0; i < even_n; ++i)
    {
        total_arr[i] = even_arr[i];
    }

    for(int i = even_n, j = 0; i < total_n; ++i , ++j)
    {
        total_arr[i] = odd_arr[j];
    }
    printf("Final Result:   \n");
    for(int i = 0; i < total_n; ++i)
    {
        printf("%d ", total_arr[i]);
    }
    printf("\n");
    return 0;
}
