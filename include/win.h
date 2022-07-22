#include<stdio.h>
#include"enum.h"
#include<stdbool.h>

bool Search_Y(const short int * x ,const short int * y) // search y 
{
    short int number = 1; // modify number to search y
    unsigned short int counter = 1; // counter for same color

    while (true)
    {
        if (*y - number >= 0 && matrix_8_8[*x][*y] == matrix_8_8[*x][*y - number])
        {
            counter++; // counter for same color
            number++; // modify number to search y
        }

        else
            break;
    }

    if (counter == 4) // winner
    {
        return true;
    }

    number = 1;
    
    while (true)
    {
        if (*y + number < 8 && matrix_8_8[*x][*y] == matrix_8_8[*x][*y + number])
        {
            counter++; // counter for same color
            number++; // modify number to search y
        }

        else
            break;
    }
    
    if (counter == 4) // winner
    {
        return true;
    }
    
    return false;
}



bool Search_X(const short int * x ,const short int * y) // search x 
{
    short int number = 1; // modify number to search x
    unsigned short int counter = 1; // counter for same color

    while (true)
    {
        if (*x - number >= 0 && matrix_8_8[*x][*y] == matrix_8_8[*x - number][*y])
        {
            counter++; // counter for same color
            number++; // modify number to search x
        }

        else
            break;
    }

    if (counter == 4) // winner
    {
        return true;
    }

    number = 1; // reset number
    
    while (true)
    {
        if (*x + number < 8 && matrix_8_8[*x][*y] == matrix_8_8[*x + number][*y])
        {
            counter++; // counter for same color
            number++ ;// modify number to search x
        }

        else
            break;
    }
    
    if (counter == 4) // winner
    {
        return true;
    }
    
    return false;
}



bool Search_Z_1(const short int * x ,const short int * y) // search z 
{
    short int number = 1; // modify number to search z
    unsigned short int counter = 1; // counter for same color

    while (true)
    {
        if ( (*x - number >= 0 && *y + number < 8) && matrix_8_8[*x][*y] == matrix_8_8[*x - number][*y + number])
        {
            counter++; // counter for same color
            number++; //    modify number to search z
        }

        else
            break;
    }

    if (counter == 4) // winner
    {
        return true;
    }

    number = 1; // reset number
    
    while (true)
    {
        if ( (*x + number < 8 && *y - number >= 0) && matrix_8_8[*x][*y] == matrix_8_8[*x + number][*y - number])
        {
            counter++; // counter for same color
            number++; // modify number to search z
        }

        else
            break;
    }
    
    if (counter == 4) // winner
    {
        return true;
    }
    
    return false;
}



bool Search_Z_2(const short int * x ,const short int * y)
{
    short int number = 1; // modify number to search z
    unsigned short int counter = 1; // counter for same color

    while (true)
    {
        if ( (*x + number < 8 && *y + number < 8) && matrix_8_8[*x][*y] == matrix_8_8[*x + number][*y + number])
        {
            counter++; // counter for same color
            number++; // modify number to search z
        }

        else
            break;
    }

    if (counter == 4) // winner
    {
        return true;
    }

    number = 1; // reset number
    
    while (true)
    {
        if ( (*x - number >= 0 && *y - number >= 0) && matrix_8_8[*x][*y] == matrix_8_8[*x - number][*y - number])
        {
            counter++; // counter for same color
            number++; // modify number to search z
        }

        else
            break;
    }
    
    if (counter == 4) // winner
    {
        return true;
    }
    
    return false;
}