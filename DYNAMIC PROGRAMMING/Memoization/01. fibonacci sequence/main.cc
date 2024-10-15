#include <iostream>
#include <unordered_map>
typedef unsigned long long ull;

// Unoptimized fibonacci
// Time complexity = O(2^n)
ull fib(int num)
{
    if (num <= 1)
    {
        return num;
    }
    ull result = fib(num - 1) + fib(num - 2);
    return result;
}

// Optimized fibonacci function using memoization
// Time complexity = O(n)
ull opt_fib(int num, std::unordered_map<int, ull> &cache) // container to store previous recursive return values.
{
    if (num <= 1)
    {
        return num;
    }
    if (cache.find(num) != cache.end())
    {
        return cache[num];
    }

    ull result = opt_fib(num - 1, cache) + opt_fib(num - 2, cache);
    cache[num] = result;
    return result;
}

int main()
{
    /* std::cout << "Unoptimized fibonacci" << std::endl;
    unsigned long long result = fib(10);
    std::cout << result << std::endl;
    result = fib(100);
    std::cout << result << std::endl; */

    std::cout << std::endl;

    std::unordered_map<int, ull> cache;
    std::cout << "Optimized fibonacci " << std::endl;
    ull result = opt_fib(100, cache);
    std::cout << result << std::endl;

    int fib_sequence = 100;
    for (int i = 0; i <= fib_sequence; i++)
    {
        std::cout << "f(" << i << ") = " << opt_fib(i, cache) << std::endl;
    }

    return 0;
}