#include <iostream>

int main()
{
    int a;
    int b;
    int bottom_half_size = 20;
    int top_half_size = 6;
    std::cout << std::endl;

    for (a = top_half_size; a < bottom_half_size; a = a + 2)
    {
        for (b = 0; b < bottom_half_size - a; b = b + 2)
        {
            std::cout << " ";
        }
        for (b = 1; b <= a; b++)
        {
            std::cout << "*";
        }
        for (b = 1; b <= bottom_half_size - a; b++)
        {
            std::cout << " ";
        }
        for (b = 1; b <= a; b++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    for (a = bottom_half_size; a >= 0; a--)
    {
        for (b = a; b < bottom_half_size; b++)
        {
            std::cout << " ";
        }
        for (b = 1; b <= ((a * 2) - 1); b++)
        {
            if (((a * 2) - 1) == 1)
            {
                break;
            }

            std::cout << "*";
        }

        std::cout << std::endl;
    }

    return 0;
}