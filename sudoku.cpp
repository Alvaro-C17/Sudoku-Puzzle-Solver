#include <iostream>
#include <fstream>
using namespace std;

const int N = 9; // Sudoku board size

// Check if a number can be placed in a cell of the Sudoku board
bool isValid(int board[N][N], int row, int col, int num) {
    // Check row and column
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }
    // Check 3x3 subgrid
    int rowStart = (row / 3) * 3;
    int colStart = (col / 3) * 3;
    for (int i = rowStart; i < rowStart + 3; i++) {
        for (int j = colStart; j < colStart + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

// Find the next empty cell in the Sudoku board
bool findEmptyCell(int board[N][N], int& row, int& col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// Solve the Sudoku puzzle using backtracking
bool solveSudoku(int board[N][N]) {
    int row, col;
    if (!findEmptyCell(board, row, col)) {
        return true; // All cells are filled, puzzle solved
    }
    for (int num = 1; num <= N; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board)) {
                return true; // Solution found
            }
            board[row][col] = 0; // Backtrack and try a different number
        }
    }
    return false; // No solution found
}

// Print the Sudoku board to the console
void printBoard(int board[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
}

// // Read a Sudoku puzzle from a file
// bool readBoardFromFile(const char* filename, int board[N][N]) {
//     ifstream inFile(filename);
//     if (!inFile.is_open()) {
//         return false; // File not found or cannot be opened
//     }
//     for (int row = 0; row < N; row++) {
//         for (int col = 0; col < N; col++) {
//             inFile >> board[row][col];
//         }
//     }
//     inFile.close();
//     return true;
// }

int main() {
    // int board[N][N];
    // const char* filename = "puzzle.txt"; // Input puzzle file name
    // if (!readBoardFromFile(filename, board)) {
    //     cout << "Error reading puzzle file." << endl;
    //     return 1;
    // }
    // if (solveSudoku(board)) {
    //     cout << "Solved puzzle:" << endl;
    //     printBoard(board);
    // } else {
    //     cout << "No solution found." << endl;
    // }
    // return 0;
    
    int puzzle[9][9];

    // Read in puzzle from standard input
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cin >> puzzle[i][j];
        }
    }

    // Solve the puzzle
    if (solveSudoku(puzzle)) {
        // Print the solution
        printBoard(puzzle);
    } else {
        std::cout << "No solution found.\n";
    }

    return 0;
}
