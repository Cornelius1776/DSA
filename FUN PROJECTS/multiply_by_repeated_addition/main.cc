#include <iostream>

// Using iteration
void test(int a, int b)
{
    int result = 0;
    while (a != 0)
    {
        result += b;
        a--;
    }
    std::cout << result << std::endl;
}

// Using recursion
int test_2(int x, int y)
{
    if (x == 0 || y == 0)
    {
        return 0;
    }
    if (y == 1)
    {
        return x;
    }
    return x + test_2(x, y - 1);
}

int main()
{
    test(3, 6);
    test(5, 4);
    std::cout << test_2(5, 2) << std::endl;
    std::cout << test_2(6, 10) << std::endl;

    return 0;
}