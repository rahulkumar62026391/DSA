/*
Time Complexity: O(n!) 

   You place 1 queen per row → total N rows.
   N!=N×(N−1)×(N−2)⋯×1

Auxiliary Space: O(n)
   You don’t need a full N×N board — just the info needed to check if a queen placement is safe.
*/

#include <iostream>
using namespace std;

#define N 4

// Print the board
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
    cout << endl;
}

// Check if it's safe to place a queen at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// Solve N-Queen using backtracking
bool solveNQueens(int board[N][N], int row) {
    if (row == N) {
        printSolution(board);
        return true; // Return true if only one solution is needed
    }

    bool res = false;
    for (int col = 0; col < N; col++) 
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 1;
            res = solveNQueens(board, row + 1) || res;
            board[row][col] = 0; // backtrack
        }
    }
    return res;
}

int main() {
    int board[N][N] = {0};

    if (!solveNQueens(board, 0))
        cout << "No solution exists." << endl;

    return 0;
}

/*
1.Sudoku solvers

2.Crossword generators

3.Puzzle games

4.Pathfinding with constraints
*/