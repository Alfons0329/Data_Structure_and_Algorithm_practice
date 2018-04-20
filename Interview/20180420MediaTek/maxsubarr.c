/*
題目給定兩行輸入，第一行為array的長度，第二行分別為array裡面的值，要求出Subarray中SUM的最大值。舉例來說：
Input：
6
2 3 -8 1 2 3
Output：
6
由於第3 4 5 項所加總的值最大，因此輸出最大值為6。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_N 1000000

int main(int argc, char const *argv[])
{
    int len;
    scanf("%d",&len);
    int* arr;
    arr = malloc(len * sizeof(int));
    for(int i = 0; i < len; ++i)
    {
        scanf("%d\n", &arr[i]);
    }
    int cur_sum = 0, max_sum = 0;
    for(int i = 0; i < len; ++i)
    {
        cur_sum += arr[i];
        if(cur_sum < 0) //if cause the decrease, then re accumulate
        {
            cur_sum = 0;
        }
        if(cur_sum > max_sum)
        {
            max_sum = cur_sum;
        }
    }
    printf("Max subarray sum: %d\n", max_sum);
    return 0;
}
