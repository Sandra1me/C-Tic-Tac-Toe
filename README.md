# Tic-Tac-Toe (C)

A two-player Tic-Tac-Toe game implemented in C, designed to practice structured programming, 2D arrays, modular functions, and input validation.

<img width="1920" height="1080" alt="Tic-Tac-toe game" src="https://github.com/user-attachments/assets/95c1a5cb-130f-4861-b75b-97aee62f7313" />

## Features

- 3x3 board implemented using a 2D array
- Two-player mode (X and O)
- Input validation for row and column selection
- Win detection (rows, columns, diagonals)
- Draw detection
- Option to play multiple matches
- Modular design using separate functions

## Compilation 

Use a C compiler such as gcc.

```c
gcc tic-tac-toe.c -o tic-tac-toe
```

## Execution

```c
./tic-tac-toe
```

The game will prompt players to enter the row and column (1–3) for each move.

After a match ends, players can choose whether to start a new game.

## Project Structure
- initializeBoard() → Initializes the game board.
- printBoard() → Displays the current board state.
- checkWin() → Checks if a player has won.
- checkDraw() → Checks if the board is full.
- main() → Controls game flow and user interaction.

## Possible Future Improvements

- Single-player mode with basic AI
- Score tracking between matches
- Dynamic board size
- Refactoring using structures
- Improved input handling with error checking

## License

This project is released under the [MIT License](https://choosealicense.com/licenses/mit/).
