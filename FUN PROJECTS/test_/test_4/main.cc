#include <iostream>

void add(int &num)
{
    num++;
    std::cout << "num is " << num << " the address inide add() is " << &num << std::endl;
}

int main()
{
    int n = 5;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Reverse loop gives the same output
    for (int j = n; j < n - 1; j--)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    add(n);
    std::cout << n << std::endl;

    n++;
    std::cout << n << " address inside main() is " << &n << std::endl;

    return 0;
}