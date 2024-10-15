#include <iostream>

// Using Recurson
int factorial(int num)
{
    if (num == 1)
    {
        return num;
    }
    return num = num * factorial(num - 1);
}

// Using Iteraton

void print(int num)
{
    std::cout << factorial(num) << "\n";
}

int main()
{
    print(5);
    print(8);

    fact(5);
    fact(8);

    return 0;
}