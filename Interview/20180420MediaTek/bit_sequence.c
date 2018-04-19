/*
給你一個8-bit的整數數列，要你找出這串數列的連續最長的1bit的長度和他的起始位置
ps. 255=11111111就是8個連續的1bit, 119=01110111有兩組連續3個1bit
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void check_longest(int num)
{
    unsigned int longest_seq = 0, start_pos = 8, cur_seq = 0, final_pos = 8;
    int original = num;
    while(num)
    {
        if(num & 1) //if bit is 1
        {
            cur_seq++;
        }
        else
        {
            if(cur_seq > longest_seq)
            {
                longest_seq = cur_seq;
                final_pos = start_pos;
                cur_seq = 0;
            }
        }
        start_pos--;
        num >>= 1;
    }
    if((original & 0b10000000) >> 7) //for test case like 11110111, output shpuld be longest4 and start pos is 3 (from right most)
    {
        if(cur_seq > longest_seq)
        {
            longest_seq = cur_seq;
            //final_pos = start_pos; ramin the last one, does not need to increase
        }
    }
    printf("start_pos (from leftmost msb)%d, longest seq %d \n",final_pos, longest_seq);
}
int main(int argc, char const *argv[])
{
    unsigned int num;
    scanf("%d",&num);
    check_longest(num);
    return 0;
}
