#include"file.h" // for enum Color

void Print_Mat_1D(unsigned short int number) // print each row of matrix
{
    printf("|");
    for (size_t i = 0; i < 8; i++)
    Print_Turn(matrix_8_8[number][i]); // print each element (character) of row

    printf("\n");
}

void Display_Matrix() // table
{
    printf("+---+---+---+---+---+---+---+---+\n");
    Print_Mat_1D(0);
    printf("+---+---+---+---+---+---+---+---+\n");
    Print_Mat_1D(1);
    printf("+---+---+---+---+---+---+---+---+\n");
    Print_Mat_1D(2);
    printf("+---+---+---+---+---+---+---+---+\n");
    Print_Mat_1D(3);
    printf("+---+---+---+---+---+---+---+---+\n");
    Print_Mat_1D(4);
    printf("+---+---+---+---+---+---+---+---+\n");
    Print_Mat_1D(5);
    printf("+---+---+---+---+---+---+---+---+\n");
    Print_Mat_1D(6);
    printf("+---+---+---+---+---+---+---+---+\n");
    Print_Mat_1D(7);
    printf("+---+---+---+---+---+---+---+---+\n");
    printf("  1   2   3   4   5   6   7   8  \n");
}


bool Insert(short int number ,enum Color color) // insert a piece in matrix
{
    number--; // because of array (begin from 0 )

    for (short i = 7 ; i >= 0 ; i--) 
    {
        if (matrix_8_8[i][number] == EMPTY ) // check empty or not
        {
            matrix_8_8[i][number] = color; // if empty insert piece

            if (Search_X(&i ,&number)   || Search_Y(&i ,&number) ||
                Search_Z_1(&i ,&number) || Search_Z_2(&i ,&number)) // check if there is a winner
            {
                system("clear");
                // system("cls"); // for windows
                Display_Matrix(); // display matrix
                remove("matrix.txt"); // delete file for play again
                remove("player_color.txt"); // delete file for play again
                printf("Player %d Won _ With Color : %s \n" ,player_turn + 1 ,Color_Text(&color));
                exit(1);
            }

            return true;
        }
    }

    printf("Column is Full \n"); // if column is full
    printf("Enter Any Key To Continue : \n"); // ask user to continue
    fflush(stdin); // flush input buffer
    getchar(); // get char from buffer
    getchar(); // get char from buffer
    return false;
}