#include <iostream>

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Check if an array is sorted
bool is_sorted(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

void check(int *arr, int n)
{
    if (is_sorted(arr, n))
    {
        std::cout << "The array is sorted!" << std::endl;
        return;
    }
    std::cout << "Not sorted!" << std::endl;
}

int main()
{
    int rates[] = {23, 5, 45, 76, 8, 71};
    int n = sizeof(rates) / sizeof(*rates);
    print(rates, n);
    check(rates, n);

    int num[] = {1, 2, 3, 4, 5};
    n = sizeof(num) / sizeof(num[0]);
    print(num, n);
    check(num, n);

    return 0;
}