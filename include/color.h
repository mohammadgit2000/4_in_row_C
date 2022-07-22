#include<stdio.h>

void Red() // red code color
{
    printf("\033[1;31m");
}

void Green() // green code color
{
    printf("\033[1;32m");
}

void Yellow() // yellow code color
{
    printf("\033[1;33m");
}

void Blue() // blue code color
{
    printf("\033[1;34m");
}

void Reset() // reset code color
{
    printf("\033[0m");
}