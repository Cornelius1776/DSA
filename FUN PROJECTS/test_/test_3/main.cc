#include <iostream>

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 8;
    int y = 10;
    std::cout << "x = " << x << " y = " << y << std::endl;

    swap(x, y);

    std::cout << "x = " << x << " y = " << y << std::endl;
    std::string name;
    std::cout << "What is your name? ";
    std::getline(std::cin, name);
    std::cout << "Hi " << name << std::endl;

    return 0;
}