#include"color.h"

enum Color {
    RED = 1,
    GREEN,
    YELLOW,
    BLUE,
    EMPTY
}; // enum Color

enum Color player_color[2]; // store color of each player
enum Color matrix_8_8[8][8]; // store color of each cell of matrix 8x8
unsigned short int player_turn = 0; // store turn of each player

void Set_Color(enum Color * color , unsigned short number) // set color of each cell of matrix
{
    switch (number)
    {
        case RED:
            *color = RED;
            break;

        case GREEN:
            *color = GREEN;
            break;
    
        case BLUE:
            *color = BLUE;
            break;

        case YELLOW:
            *color = YELLOW;
            break;
    }
}



void Choose_Color_Player(enum Color * color) // player can choose color for playing
{
    unsigned short int number;

    printf("Enter color player 1: \n");
    Red();
    printf("1-Red\n");
    Green();
    printf("2-Green\n");
    Yellow();
    printf("3-Yellow\n");
    Blue();
    printf("4-Blue\n");
    Reset();
    scanf("%hu", &number);

    while (number < 1 || number > 4) // validation
    {
        printf("Enter Valid Number : \n");
        scanf("%hu", &number);
    }
    
    color[0] = (enum Color)number; // cast number to enum Color
    
    printf("Enter color player 2: \n");
    Red();
    printf("1-Red\n");
    Green();
    printf("2-Green\n");
    Yellow();
    printf("3-Yellow\n");
    Blue();
    printf("4-Blue\n");
    Reset();
    scanf("%hu", &number);

    while (number < 1 || number > 4) // valid number of color
    {
        printf("Enter Valid Number : \n");
        scanf("%hu", &number);
    }

    color[1] = (enum Color)number; // cast number to enum Color
}


void Print_Turn(enum Color color) // print character of each player with color
{
    switch (color)
    {
        case RED:
            Red();
            break;

        case GREEN:
            Green();
            break;

        case BLUE:
            Blue();
            break;

        case YELLOW:
            Yellow();
            break;

        case EMPTY:
            Reset();
            printf("   |");
            return;
    }

    if (player_color[0] == color)
    {
        printf(" X ");
        Reset();
        printf("|");
    }

    else if (player_color[1] == color)
    {
        printf(" O ");
        Reset();
        printf("|");
    }

    Reset();
}


void Set_Matrix_Empty(enum Color matrix[8][8]) // set all cell of matrix to empty
{
    unsigned short int i, j;

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            matrix[i][j] = EMPTY;
        }
    }
}


const char * Color_Text(const enum Color * color) // return color name 
{
    switch (*color)
    {
        case RED:
            return "Red";
        case GREEN:
            return "Green";
        case BLUE:
            return "Blue";
        case YELLOW:
            return "Yellow";
    }
}