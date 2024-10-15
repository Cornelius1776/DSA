#include <iostream>

void hollow_diamond(int size)
{
    int upper_half = (size - 1) / 2;
    int lower_half = 3 * size / 2 - 1;

    // Loop through the row
    for (int i = 0; i < size; i++)
    {
        // Loop through the columns
        for (int j = 0; j < size; j++)
        {
            // Conditions to print the pattern
            if (i + j == upper_half || i - j == upper_half || j - i == upper_half || i + j == lower_half || i == upper_half || j == upper_half)
            {
                std::cout << "*";
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main()
{
    // To get the perfect pattern, only odd numbers should be used. Even numbers give a crooked pattern
    int size = 11;
    hollow_diamond(size);

    return 0;
}