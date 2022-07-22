#include"../include/app.h"

int main()
{
    Read_Player_Color_From_File(player_color); // read player color from file
    Read_Matrix_From_File(matrix_8_8); // read matrix from file

    Start_Game(); // start game

    Write_Player_Color_To_File(player_color); //    write player color to file
    Write_Matrix_To_File(matrix_8_8); // write matrix to file

    return 0;
}