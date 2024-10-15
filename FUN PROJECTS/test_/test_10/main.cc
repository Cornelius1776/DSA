#include <iostream>

// Trying out swapping without using an extra variable.
void bubble_sort(int arr[], int n)
{
    std::cout << "Sorted: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                arr[i] ^= arr[j];
                arr[j] ^= arr[i];
                arr[i] ^= arr[j];
            }
        }
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // Swapping variables
    int x = 10;
    int y = 20;

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;

    x ^= y; // x is currently holding both 10 and 20, so at this point x = 30
    std::cout << x << std::endl;
    y ^= x; // y has recieved 10, so y = 10
    x ^= y; // x has given away 10, now x = 20. The values has been swapped.

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;

    int rates[] = {32, 45, 2, 76, 12, 1, 55, 14};
    int n = sizeof(rates) / sizeof(rates[0]);
    std::cout << "Unsorted: ";
    print(rates, n);

    bubble_sort(rates, n);

    print(rates, n);

    return 0;
}