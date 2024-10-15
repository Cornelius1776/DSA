#include <iostream>
#define ROW 3
#define COLUMN 4

// Subtraction
void subtract(int a[ROW][COLUMN], int b[ROW][COLUMN], int result[ROW][COLUMN])
{
    std::cout << "Subtraction: " << std::endl;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            result[i][j] = a[i][j] - b[i][j];
            std::cout << a[i][j] << " - " << b[i][j] << " = " << result[i][j] << " \n";
        }
    }
}

// Addition
void add(int a[ROW][COLUMN], int b[ROW][COLUMN], int result[ROW][COLUMN])
{
    std::cout << "Addition: " << std::endl;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
            std::cout << a[i][j] << " + " << b[i][j] << " = " << result[i][j] << " \n";
        }
    }
}

// Multiply
void multiply(int a[ROW][COLUMN], int b[ROW][COLUMN], int result[ROW][COLUMN])
{
    std::cout << "Multiplication: " << std::endl;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            result[i][j] = a[i][j] * b[i][j];
            std::cout << a[i][j] << " x " << b[i][j] << " = " << result[i][j] << " \n";
        }
    }
}

void print(int arr[ROW][COLUMN])
{
    std::cout << '[';
    for (int i = 0; i < ROW; i++)
    {
        std::cout << '[';
        for (int j = 0; j < COLUMN; j++)
        {
            std::cout << arr[i][j];
            // space and comma between the elements
            if (i != ROW && j != COLUMN - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << ']';
        // space and comma between the inner arrays
        if (i != ROW - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << ']' << std::endl;
}

int main()
{
    int numbers[ROW][COLUMN] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    print(numbers);

    int numbers_1[ROW][COLUMN] = {
        {13, 14, 15, 16},
        {17, 18, 19, 20},
        {21, 22, 23, 24}};

    print(numbers_1);

    int result[ROW][COLUMN];

    subtract(numbers_1, numbers, result);
    print(result);

    add(numbers_1, numbers, result);
    print(result);

    multiply(numbers_1, numbers, result);
    print(result);

    int name;
    name = 1;

    return 0;
}