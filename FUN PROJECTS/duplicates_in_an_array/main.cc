#include <iostream>
#include <unordered_set>

// Brute force approach
// Time complexity O(n ^ 2)
/* bool has_duplicate(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                return true;
            }
        }
    }
    return false;
}

void print_array(int *arr, int n)
{
    if (has_duplicate(arr, n))
    {
        std::cout << std::boolalpha << has_duplicate(arr, n) << ": ";
    }
    else
    {
        std::cout << std::boolalpha << has_duplicate(arr, n) << ": ";
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
} */

// Using set
// Time complexity is O(n)
bool has_duplicate_set(int *arr, int n)
{
    std::unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.find(arr[i]) != s.end())
        {
            return true;
        }
        else
        {
            s.insert(arr[i]);
        }
    }
    return false;
}

void print_array(int *arr, int n)
{
    if (has_duplicate_set(arr, n))
    {
        std::cout << std::boolalpha << true << ": ";
    }
    else
    {
        std::cout << std::boolalpha << false << ": ";
    }
    // Print out the element
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::unordered_set<int> set_var = {12, 34, 45, 12, 10, 12, 34, 6, 4, 12, 10};
    for (auto &&i : set_var)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Check if the array has duplicates
    int arr[] = {2, 4, 1, 4, 5, 2, 2, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, n);

    int rates[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    n = sizeof(rates) / sizeof(rates[0]);
    print_array(rates, n);

    return 0;
}
