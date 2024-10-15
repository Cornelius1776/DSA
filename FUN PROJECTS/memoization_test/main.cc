#include <iostream>
#include <unordered_map>

int test(int a, int b, std::unordered_map<int, int> &cache)
{
    // std::cout << "Memory address of cache in test() is " << &cache << std::endl;
    int key = a + b;
    if (cache.find(key) != cache.end())
    {
        std::cout << "returning from cache: ";
        return cache[key];
    }
    std::cout << "Executing for the first time ";
    return cache[key] = key;
}

// Fun recursion example
int func(int num)
{
    if (num == 1)
    {
        return num;
    }
    std::cout << num << " ";
    return func(num - 1);
}

int main()
{
    // int result = func(5);
    // std::cout << result << std::endl;

    std::unordered_map<int, int> cache;
    // std::cout << "Memory address of cache in main() is " << &cache << std::endl; // Pass by reference

    std::cout << test(2, 4, cache) << std::endl;

    std::cout << test(2, 4, cache) << std::endl;

    std::cout << test(5, 1, cache) << std::endl;

    std::cout << test(3, 3, cache) << std::endl;

    std::cout << test(10, 5, cache) << std::endl;

    std::cout << test(10, 5, cache) << std::endl;

    std::cout << test(7, 8, cache) << std::endl;

    return 0;
}