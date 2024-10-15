#include <iostream>

// Find the largest and smallest largest in an array
void smallest_largest(int *arr, int n)
{
    int largest = *arr;
    int smallest = *arr;
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
            x = i;
        }
        if (arr[i] < smallest)
        {
            smallest = arr[i];
            y = i;
        }
    }
    std::cout << "The largest element in the array is " << largest << " at index " << x << std::endl;
    std::cout << "The smallest element in the array is " << smallest << " at index " << y << std::endl;
}

// Using helper functions
int largest(int x, int y)
{
    return x - y;
}
int smallest(int x, int y)
{
    return y - x;
}

void find(int arr[], int n, int (*compare)(int, int))
{
    int target = arr[0];
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (compare(arr[i], target) > 0)
        {
            target = arr[i];
            index = i;
        }
    }
    std::cout << "target is " << target << " at index " << index << std::endl;
}

int main()
{
    int prices[] = {12, 34, 134, 56, 2, 45, 86, 71, -3};
    int n = sizeof(prices) / sizeof(*prices);
    smallest_largest(prices, n);
    find(prices, n, smallest);
    find(prices, n, largest);

    return 0;
}