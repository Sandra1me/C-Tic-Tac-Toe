/*
    Tic-Tac-Toe Game
    ----------------------
    A two-player Tic-Tac-Toe game implemented in C, designed to practice structured programming, 2D arrays, modular functions, and input validation.

    Author: [Sandra Martin Elias]
    Date: [2026/02/05]
*/

#include <stdio.h>
#define SIZE 3

void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE], char player);
int checkDraw(char board[SIZE][SIZE]);

int main()
{
    // Main game loop (allows multiple matches)
    while (1)
    {
        char board[SIZE][SIZE];
        char currentPlayer = 'X';
        int row, col, win = 0, draw = 0;
        char playAgain = ' ';

        initializeBoard(board);
        printBoard(board);

        // Game loop (runs until win or draw)
        while (1)
        {
            printf("Player %c, your turn.\n", currentPlayer);
            
            // Input validation loop
            while (1)
            {
                printf("Please enter the row (1-3) for your move: ");
                scanf("%i", &row);
                printf("Please enter the column (1-3) for your move: ");
                scanf("%i", &col);
                if (row >= 1 && row <= SIZE && col >= 1 && col <= SIZE && board[row - 1][col - 1] == ' ')
                {
                    board[row - 1][col - 1] = currentPlayer;
                    printBoard(board);
                }
                else
                {
                    printf("Invalid move. Please try again.\n");
                    continue;
                }

                break;
            }

            win = checkWin(board, currentPlayer);
            draw = checkDraw(board);

            if (win)
            {
                printf("Player %c wins!\n", currentPlayer);
                break;
            }
            else if (draw)
            {
                printf("It's a draw!\n");
                break;
            }

            // Switch current player
            if (currentPlayer == 'X')
            {
                currentPlayer = 'O';
            }
            else
            {
                currentPlayer = 'X';
            }
        }

        while (playAgain != 'Y' && playAgain != 'N' && playAgain != 'y' && playAgain != 'n')
        {
            printf("Do you want to play again? (Y/N): ");
            scanf(" %c", &playAgain);
            if (playAgain == 'Y' || playAgain == 'y')
            {
                printf("Starting a new game...\n");
            }
            else if (playAgain == 'N' || playAgain == 'n')
            {
                printf("Thanks for playing!\n");
                return 0;
            }
            else
            {
                printf("Invalid input. Please enter Y or N.\n");
            }
        }
    }
}

// Initializes the game board by filling all cells with empty spaces
void initializeBoard(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// Prints the current state of the board to the console.
void printBoard(char board[SIZE][SIZE])
{
    printf("+---+---+---+\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("|");

        for (int j = 0; j < SIZE; j++)
        {
            printf(" %c |", board[i][j]);
        }

        printf("\n+---+---+---+\n");
    }
}

// Checks if the specified player has achieved three in a row.
// Returns 1 if the player wins, 0 otherwise.
int checkWin(char board[SIZE][SIZE], char player)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return 1;
        }
        else if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return 1;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return 1;
    }
    else if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return 1;
    }
    return 0;
}

// Checks if the board is full and no more moves are possible.
// Returns 1 if the game is a draw, 0 otherwise.
int checkDraw(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}