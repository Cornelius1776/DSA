#include <iostream>

void right_triangle(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 2 * i - 1; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int size = 8;
    right_triangle(size);

    return 0;
}