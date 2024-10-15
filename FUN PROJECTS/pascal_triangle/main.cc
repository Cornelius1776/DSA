#include <iostream>

void pascal_triangle(int num)
{
    for (int row = 0; row < num; row++)
    {
        // Loop to print spaces for triangular display
        for (int i = 1; i < num - row + 1; i++)
            std::cout << "  ";

        // Performing the combinations
        int coeff = 1;
        for (int j = 0; j <= row; j++)
        {
            std::cout << coeff << "  ";
            coeff = coeff * (row - j) / (j + 1);
        }
        std::cout << std::endl;
    }
}

int main()
{
    pascal_triangle(10);

    return 0;
}