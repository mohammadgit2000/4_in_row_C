#include<stdio.h>

#include"matrix.h"

bool game_over() // if all of index have color return true 
{
    for(int i = 0 ; i < 8 ; i++)
    {
        if (matrix_8_8[0][i] == EMPTY)
        {
            return false;
        }
    }

    return true;
}


void Start_Game() // manage game ..
{
    unsigned short int counter = 0; // counter for same color

    while (1)
    {
        system("clear"); // on linux system clear screen
        // system("cls"); // on windows

        Display_Matrix(); // display matrix in console
        printf("Enter Column : ");
        short int choice;
        scanf("%hu" ,&choice); // get column from user

        if ( game_over() ) // if all index of matrix have color
        {
            printf("Game Over \n");
            return;
        }

        if (choice == 0) // for exit from game every time user enter 0
        {
            return;
        }
        
        while (choice < 0 || choice > 8) // validation 
        {
            printf("enter valid column : ");
            scanf("%hu" ,&choice);

            if (choice == 0) // for exit from game every time user enter 0
            {
                return;
            }
        }

        if( Insert(choice ,player_color[player_turn]) ) // insert color in matrix
            Write_Matrix_To_File(matrix_8_8); // write matrix to file

        player_turn == 0 ? player_turn++ : player_turn--; // change turn
    }
}