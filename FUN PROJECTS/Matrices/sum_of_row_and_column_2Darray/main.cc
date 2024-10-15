#include <iostream>

void print(int arr[][3], int outer, int inner) // the size of inner array(s) must be innitialized
{
    for (int i = 0; i < outer; i++)
    {
        for (int j = 0; j < inner; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int numbers[][3] =
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {10, 11, 12},
        };

    int row = sizeof(numbers) / sizeof(*numbers);          // length of the outer array
    int column = sizeof(numbers[0]) / sizeof(*numbers[0]); // length of the inner array
    print(numbers, row, column);

    std::cout << numbers[2][0] << std::endl;

    // Sum of the rows
    for (int i = 0; i < row; i++)
    {
        int row_sum = 0;
        for (int j = 0; j < column; j++)
        {
            row_sum += numbers[i][j];
        }
        std::cout << "sum of " << i + 1 << " row is " << row_sum << std::endl;
    }

    // Sum of the columns
    for (int i = 0; i < column; i++)
    {
        int col_sum = 0;
        for (int j = 0; j < row; j++)
        {
            col_sum += numbers[j][i];
        }
        std::cout << "sum of " << i + 1 << " column is " << col_sum << std::endl;
    }

    return 0;
}