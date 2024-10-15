#include <iostream>
#include <vector>
#include <unordered_map>
/* Check if a target sum can be found in an array of numbers, by the sum of 2 elements in the
array   */

// non optimized
bool can_sum(int target_sum, const std::vector<int> &arr)
{
    if (target_sum == 0)
    {
        return true;
    }
    if (target_sum < 0)
    {
        return false;
    }

    for (int num : arr)
    {
        int remainder = target_sum - num;
        if (can_sum(remainder, arr) == true)
        {
            return true;
        }
    }

    return false;
}

// Optimized using memoization
bool can_sum_optimized_helper(int target_sum, const std::vector<int> &arr, std::unordered_map<int, bool> &cache)
{
    if (target_sum == 0)
    {
        return true;
    }
    if (target_sum < 0)
    {
        return false;
    }
    for (int num : arr)
    {
        int remainder = target_sum - num;
        if (cache.find(remainder) != cache.end())
        {
            if (cache[remainder] == true)
            {
                return true;
            }
        }
        else
        {
            cache[remainder] = can_sum_optimized_helper(remainder, arr, cache);
            if (cache[remainder] == true)
            {
                return true;
            }
        }
    }
    return false;
}
bool can_sum_optimized(int target_sum, const std::vector<int> &arr)
{
    std::unordered_map<int, bool> cache;
    return can_sum_optimized_helper(target_sum, arr, cache);
}

int main()
{
    std::cout << "Optimized " << std::endl;
    std::cout << std::boolalpha << can_sum_optimized(7, {2, 4}) << std::endl;
    std::cout << std::boolalpha << can_sum_optimized(5, {2, 3}) << std::endl;
    std::cout << std::boolalpha << can_sum_optimized(7, {2, 3}) << std::endl;
    std::cout << std::boolalpha << can_sum_optimized(7, {5, 3, 4, 7}) << std::endl;
    std::cout << std::boolalpha << can_sum_optimized(400, {7, 14}) << std::endl;
    std::cout << std::endl;

    std::cout << "Unoptimized " << std::endl;
    std::cout << std::boolalpha << can_sum(7, {2, 4}) << std::endl;
    std::cout << std::boolalpha << can_sum(5, {2, 3}) << std::endl;
    std::cout << std::boolalpha << can_sum(7, {2, 3}) << std::endl;
    std::cout << std::boolalpha << can_sum(7, {5, 3, 4, 7}) << std::endl;
    std::cout << std::boolalpha << can_sum(400, {7, 14}) << std::endl;

    return 0;
}