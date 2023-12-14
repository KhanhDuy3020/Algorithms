#include <iostream>
using namespace std;

const int N = 9;
int grid[N][N];

bool isSafe(int row, int col, int num)
{
    for (int x = 0; x < N; x++)
    {
        if (grid[row][x] == num || grid[x][col] == num)
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
            if (grid[i + startRow][j + startCol] == num)
            {
                return false;
            }
        }
    }

    return true;
}

bool findUnassignedLocation(int &row, int &col)
{
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            if (grid[row][col] == 0)
            {
                return true;
            }
        }
    }
    return false;
}

int countSolutions()
{
    int row, col;
    if (!findUnassignedLocation(row, col))
    {
        return 1; // Nếu tìm thấy một giải pháp, trả về 1
    }

    int count = 0;
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(row, col, num))
        {
            grid[row][col] = num;
            count += countSolutions();
            grid[row][col] = 0;
        }
    }
    return count;
}

int main()
{
    // Nhập bảng Sudoku
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    }

    int solutionCount = countSolutions();
    cout << solutionCount << endl;

    return 0;
}
