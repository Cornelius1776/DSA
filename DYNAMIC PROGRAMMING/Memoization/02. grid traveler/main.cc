#include <iostream>
#include <unordered_map>
typedef unsigned long long ull;

ull grid_traveler(int row, int column)
{
    if (row == 1 && column == 1)
    {
        return 1;
    }
    if (row == 0 || column == 0)
    {
        return 0;
    }

    ull result = grid_traveler(row - 1, column) + grid_traveler(row, column - 1);
    return result;
}

// Optimized using memoization
/* cache must be passed by reference(&) to avoid creating many copies of the value this is
crucial, else the memoization will not work */
ull memo(int row, int column, std::unordered_map<std::string, ull> &cache) // size_t can be used
{
    // Check if the solution is already memoized
    std::string key = std::to_string(row) + ", " + std::to_string(column);
    if (cache.find(key) != cache.end())
    {
        // std::cout << key << std::endl;
        return cache[key];
    }

    if (row == 1 && column == 1)
    {
        return 1;
    }
    if (row == 0 || column == 0)
    {
        return 0;
    }

    // Calculate and memoize the result
    ull result = memo(row - 1, column, cache) + memo(row, column - 1, cache);
    cache[key] = result;
    return result;
}

int main()
{
    // Optimized grid traveler using memoization
    std::cout << "optimized using memoization" << std::endl;
    int row = 3;
    int column = 3;
    std::unordered_map<std::string, ull> cache;

    ull result = memo(row, column, cache);
    std::cout << result << " ways to go through " << row << " by " << column << std::endl;

    row = 80, column = 50;
    result = memo(row, column, cache);
    std::cout << result << " ways to go through " << row << " by " << column << std::endl;
    std::cout << std::endl;

    row = 18, column = 18;
    result = memo(row, column, cache);
    std::cout << result << " ways to go through " << row << " by " << column << std::endl;
    std::cout << std::endl;

    int count = 50;
    for (int i = 0; i <= count; i++)
    {
        result = memo(i, i, cache);
        std::cout << result << " ways to go through " << i << " by " << i << std::endl;
    }

    return 0;
}
