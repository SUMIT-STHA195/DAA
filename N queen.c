#include <stdio.h>
#include <stdlib.h>

// Function to check if a queen can be placed on board[row][col]
int isSafe(int **board, int row, int col, int N)
{
        int i, j;

        // Check this row on left side
        for (i = 0; i < col; i++)
        {
                if (board[row][i] == 1)
                        return 0;
        }

        // Check upper diagonal on left side
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
                if (board[i][j] == 1)
                        return 0;
        }

        // Check lower diagonal on left side
        for (i = row, j = col; j >= 0 && i < N; i++, j--)
        {
                if (board[i][j] == 1)
                        return 0;
        }

        return 1;
}

// Recursive function to solve N-Queens problem
int solveNQUtil(int **board, int col, int N, int **solutions, int *solutionCount)
{
        if (col >= N)
        {
                // Found a solution, copy current board configuration to solutions
                solutions[*solutionCount] = (int *)malloc(N * sizeof(int));
                for (int i = 0; i < N; i++)
                {
                        for (int j = 0; j < N; j++)
                        {
                                if (board[i][j] == 1)
                                        solutions[*solutionCount][i] = j + 1; // Store column indices (1-based)
                        }
                }
                (*solutionCount)++;
                return 1;
        }

        int res = 0;
        for (int i = 0; i < N; i++)
        {
                if (isSafe(board, i, col, N))
                {
                        board[i][col] = 1; // Place queen

                        // Recur to place queens in next columns
                        res = solveNQUtil(board, col + 1, N, solutions, solutionCount) || res;

                        // Backtrack if queen placement doesn't lead to a solution
                        board[i][col] = 0;
                }
        }

        return res;
}

// Function to solve N-Queens problem
int **nQueen(int N, int *solutionCount)
{
        int **solutions = (int **)malloc(1000 * sizeof(int *)); // Allocate memory for solutions
        *solutionCount = 0;

        int **board = (int **)malloc(N * sizeof(int *));
        for (int i = 0; i < N; i++)
        {
                board[i] = (int *)malloc(N * sizeof(int));
                for (int j = 0; j < N; j++)
                {
                        board[i][j] = 0;
                }
        }

        if (!solveNQUtil(board, 0, N, solutions, solutionCount))
        {
                printf("No solution exists\n");
        }

        for (int i = 0; i < N; i++)
        {
                free(board[i]);
        }
        free(board);

        return solutions;
}

int main()
{
        int N = 5; // Example: solve N-Queens for n = 4
        int solutionCount;
        int **solutions = nQueen(N, &solutionCount);

        // Print all solutions
        for (int i = 0; i < solutionCount; i++)
        {
                printf("[");
                for (int j = 0; j < N; j++)
                {
                        printf("%d ", solutions[i][j]);
                }
                printf("]\n");
                free(solutions[i]);
        }
        free(solutions);

        return 0;
}
