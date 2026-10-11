#include <iostream>
using namespace std;

class Sudoku
{
private:
    int grid[9][9];

public:
    Sudoku()
    {
        int puzzle[9][9] =
        {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
        };

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                grid[i][j] = puzzle[i][j];
            }
        }
    }

    void display()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << grid[i][j] << " ";
            }

            cout << endl;
        }
    }

    bool isSafe(int row, int col, int number)
    {
        for (int j = 0; j < 9; j++)
        {
            if (grid[row][j] == number)
            {
                return false;
            }
        }

        for (int i = 0; i < 9; i++)
        {
            if (grid[i][col] == number)
            {
                return false;
            }
        }

        int startRow = row - row % 3;
        int startCol = col - col % 3;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid[startRow + i][startCol + j] == number)
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool solve()
    {
        int row = -1;
        int col = -1;
        bool emptyCell = false;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (grid[i][j] == 0)
                {
                    row = i;
                    col = j;
                    emptyCell = true;
                    break;
                }
            }

            if (emptyCell)
            {
                break;
            }
        }

        if (!emptyCell)
        {
            return true;
        }

        for (int number = 1; number <= 9; number++)
        {
            if (isSafe(row, col, number))
            {
                grid[row][col] = number;

                if (solve())
                {
                    return true;
                }

                grid[row][col] = 0;
            }
        }

        return false;
    }
};

int main()
{
    Sudoku s;

    cout << "Original Sudoku:" << endl;
    s.display();

    if (s.solve())
    {
        cout << endl;
        cout << "Solved Sudoku:" << endl;
        s.display();
    }
    else
    {
        cout << endl;
        cout << "No solution exists!" << endl;
    }

    return 0;
}
