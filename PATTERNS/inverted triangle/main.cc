#include <iostream>

void inv_triangle(int num)
{
    for (int i = 0; i < num; i++)
    {
        int space = i;
        for (int j = 0; j < 2 * num - i - 1; j++)
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
    inv_triangle(6);

    return 0;
}