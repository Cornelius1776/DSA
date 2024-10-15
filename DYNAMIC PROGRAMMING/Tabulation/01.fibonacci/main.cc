#include <iostream>
#include <vector>
typedef unsigned long long ull;

template <typename T>
void print_vec(const std::vector<T> &vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

ull fib(int num)
{
    int table[num + 2]; // array to store fibonacci values
    // 0th and 1st number of the series are 0 and 1
    table[0] = 0;
    table[1] = 1;
    for (int i = 2; i <= num; i++)
    {
        table[i] = table[i - 1] + table[i - 2]; // generate ith term using previous two terms
    }
    return table[num];
}

int main()
{
    int fib_sequence = 100;
    for (int i = 0; i <= fib_sequence; i++)
    {
        std::cout << "f(" << i << ") = " << fib(i) << std::endl;
    }

    std::cout << fib(5) << std::endl;

    return 0;
}