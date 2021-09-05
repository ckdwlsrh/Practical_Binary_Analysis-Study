#include<stdio.h>

void main()
{
    int input=0, output=10;
    __asm__ __volatile__(
    "mov %1, %%eax   \n\t"
    "add $1, %%eax   \n\t"
    "mov %%eax, %0   \n\t"
    : "=r" (output)
    : "r" (input)
    : "eax");
}