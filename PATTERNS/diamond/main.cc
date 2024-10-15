#include <iostream>

void diamond(int size)
{
    int i, j;
    // Upper part
    for (i = 0; i < size; i++)
    {
        // Print leading spaces
        for (j = 0; j < size - i; j++)
            std::cout << " ";
        // Print stars
        for (j = 0; j < 2 * i - 1; j++)
            std::cout << "*";
        // Move to next line
        std::cout << "\n";
    }
    // Lower part
    for (i = 1; i < size; i++) // i = 0 for a more extended mid section
    {
        int space = i;
        for (j = 0; j < 2 * size - i - 1; j++)
        {
            if (space)
            {
                std::cout << " ";
                space--;
            }
            else
            {
                std::cout << "*";
            }
        }
        std::cout << std::endl;
    }
}

int main()
{
    int size = 8;
    diamond(size);

    return 0;
}