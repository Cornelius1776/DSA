#include <iostream>

/*
   Interpolation search is an efficient search algorithm used to find a specific element within a sorted array.
   It is an improvement over binary search, particularly when the data is uniformly distributed.
   Interpolation search estimates the position of the target element by extrapolating its position
   based on the values at the ends of the search range.
*/

int interpolation_search(int arr[], int target, int left, int right)
{
    while (left <= right && target >= arr[left] && target <= arr[right])
    {
        if (left == right)
        {
            if (arr[left] == target)
            {
                return left; // Element found
            }
            return -1; // Element not found
        }

        // Estimate the position of the target
        int position = left + ((double)(target - arr[left]) / (arr[right] - arr[left])) * (right - left);

        if (arr[position] == target)
        {
            std::cout << target << " found at index: ";
            return position; // return index of the target
        }

        if (arr[position] < target)
        {
            left = position + 1;
        }
        else
        {
            right = position - 1;
        }
    }

    return -1; // Element not found
}

// Recursive syntax
int search(int arr[], int target, int left, int right)
{
    if (left <= right && target >= arr[left] && target <= arr[right])
    {
        if (left == right)
        {
            if (arr[left] == target)
            {
                return left; // Element found
            }
            return -1; // Element not found
        }

        // Estimate the position of the target
        int position = left + ((double)(target - arr[left]) / (arr[right] - arr[left])) * (right - left);

        if (arr[position] == target)
        {
            std::cout << "Target " << target << " found at index: ";
            return position; // Element found
        }

        if (arr[position] < target)
        {
            return search(arr, target, position + 1, right);
        }
        else
        {
            return search(arr, target, left, position - 1);
        }
    }

    return -1; // Element not found
}

int main()
{
    int arr[] = {4, 5, 6, 7, 8, 12, 14, 17, 18, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    int left = 0, right = n - 1, target = 12;
    int result = interpolation_search(arr, target, left, right);
    std::cout << result << std::endl;

    target = 4;
    result = interpolation_search(arr, target, left, right);
    std::cout << result << std::endl;

    target = 9;
    result = interpolation_search(arr, target, left, right);
    std::cout << result << std::endl;
    std::cout << "\n";

    std::cout << "Recursion" << std::endl;
    target = 21;
    result = search(arr, target, left, right);
    std::cout << result << std::endl;

    target = 5;
    result = search(arr, target, left, right);
    std::cout << result << std::endl;

    return 0;
}
