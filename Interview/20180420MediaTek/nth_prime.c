#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX_N 1000000
bool check_prime(int num)
{
    if(num == 2)
    {
        printf("%d is prime \n",num);
        return true;
    }
    for(int i = 2; i <= num / 2; ++i)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    printf("%d is prime \n",num);
    return true;
}
int main(int argc, char const *argv[])
{
    int nth = 0, cnt = 0, num = 2;
    scanf("%d\n", &nth);
    while(1)
    {
        if(check_prime(num))
        {
            ++cnt;
            if(cnt == nth)
            {
                break;
            }
        }
        ++num;
    }
    printf("%dth prime is %d \n", nth, num);
    return 0;
}
