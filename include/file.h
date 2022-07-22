#include"win.h"

#include<stdio.h>
#include<stdlib.h>

void Write_Player_Color_To_File(enum Color * color) // write player color to file
{
    FILE * file = fopen("player_color.txt", "w"); // open file

    if (file == NULL) // validation
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(file, "%d\n", (unsigned short)color[0]); // write color to file
    fprintf(file, "%d\n", (unsigned short)color[1]); // write color to file
    fprintf(file ,"%hu\n" ,player_turn); // write player turn to file
    fclose(file); // close file
}


void Read_Player_Color_From_File(enum Color * color) // read player color from file
{
    FILE * file = fopen("player_color.txt", "r"); // open file

    if (file == NULL) // validation
    {
        Choose_Color_Player(color);
        Write_Player_Color_To_File(color);
        return;
    }

    fscanf(file, "%d\n", &color[0]); // read color from file
    fscanf(file, "%d\n", &color[1]); // read color from file
    fscanf(file ,"%hu\n" ,&player_turn); // read player turn from file
    fclose(file); // close file
}


void Write_Matrix_To_File(enum Color matrix_8_8[8][8]) // write matrix cell to file
{
    FILE * file = fopen("matrix.txt", "w"); // open file

    if (file == NULL) // validation 
    {
        printf("Error opening file!\n");
        exit(1);
    }

    for (int i = 0; i < 8; i++) // write matrix cell to file one by one 
    {
        for (int j = 0; j < 8; j++)
        {
            fprintf(file, "%d ", (unsigned short)matrix_8_8[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

void Read_Matrix_From_File(enum Color matrix_8_8[8][8]) // read matrix from file
{
    FILE * file = fopen("matrix.txt", "r"); // open file

    if (file == NULL) // validation 
    {
        Set_Matrix_Empty(matrix_8_8); // set matrix empty
        Write_Matrix_To_File(matrix_8_8); // write matrix to file
        return;
    }

    for (int i = 0; i < 8; i++) // read matrix cell one by one 
    {
        for (int j = 0; j < 8; j++)
        {
            fscanf(file, "%d ", &matrix_8_8[i][j]);
        }
        fscanf(file, "\n");
    }

    fclose(file);
}