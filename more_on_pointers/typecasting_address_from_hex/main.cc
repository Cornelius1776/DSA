#include <iostream>
/* By typecasting, we convert the hexadecimal value to the integer type that has enough range to hold the value */

int main()
{
    int a = 20;
    int *a_ptr = &a;
    std::cout << a << std::endl;
    std::cout << *a_ptr << std::endl;
    std::cout << "Without typecasting " << a_ptr << std::endl;
    std::cout << "With typecasting " << (unsigned long long)a_ptr << std::endl;

    return 0;
}