#include <iostream>
#include <unordered_map>
typedef unsigned long long ull;

ull travel(int m, int n, std::unordered_map<std::string, int> &hash_table)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    else if (m == 1 && n == 1)
    {
        return 1;
    }
    std::string key = std::to_string(m) + std::to_string(n);
    if (hash_table.find(key) != hash_table.end())
    {
        return hash_table[key];
    }

    ull result = travel(m - 1, n, hash_table) + travel(m, n - 1, hash_table);
    hash_table[key] = result;
    return result;
}

int main()
{
    std::unordered_map<std::string, int> hash_table;

    std::cout << travel(2, 3, hash_table) << " ways." << std::endl;
    std::cout << travel(3, 3, hash_table) << " ways." << std::endl;
    std::cout << travel(7, 3, hash_table) << " ways." << std::endl;
    std::cout << travel(7, 7, hash_table) << " ways." << std::endl;
    std::cout << travel(10, 13, hash_table) << " ways." << std::endl;
    std::cout << travel(20, 18, hash_table) << " ways." << std::endl;

    return 0;
}