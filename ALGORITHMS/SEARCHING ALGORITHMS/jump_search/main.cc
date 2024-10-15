#include <iostream>
#include <cmath>

int jump_search(int *arr, int target, int n)
{
    int steps = sqrt(n); // Calculate the steps
    int previous = 0;

    // Jumping through the arry until the current element is less than the target
    while (arr[std::min(steps, n) - 1] < target)
    {
        previous = steps;
        steps += sqrt(n);

        // target not in the array
        if (previous >= n)
        {
            return -1;
        }
    }
    // Implementing the linear search
    for (int i = previous; i < std::min(steps, n); i++)
    {
        if (arr[i] == target)
        {
            std::cout << target << " found at index ";
            return i;
        }
    }
    return -1;
}

// Generic implementation of jump search
template <typename A, typename T>
void search(A *arr, T target, size_t n)
{
    size_t step = sqrt(n);
    size_t prev = 0;

    while (arr[std::min(step, n) - 1] < target)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
        {
            std::cout << target << " not found in the array" << std::endl;
            return;
        }
    }

    for (size_t i = 0; i < std::min(step, n); i++)
    {
        if (arr[i] == target)
        {
            std::cout << target << " is found at index " << i << std::endl;
            std::cout << prev << " steps." << std::endl;
            return;
        }
    }
    std::cout << target << " not found." << std::endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 8, 10};
    int length = sizeof(arr) / sizeof(arr[0]);
    int target = 3;
    int result = jump_search(arr, target, length);
    std::cout << result << std::endl;
    std::cout << std::endl;

    target = 1;
    result = jump_search(arr, target, length);
    std::cout << result << std::endl;
    std::cout << std::endl;

    target = 11;
    result = jump_search(arr, target, length);
    std::cout << result << std::endl;
    std::cout << std::endl;

    target = 10;
    result = jump_search(arr, target, length);
    std::cout << result << std::endl;
    std::cout << std::endl;

    // Generic driver code
    std::cout << "Generic implementation" << std::endl;

    target = 4;
    search(arr, target, length);
    std::cout << std::endl;

    std::string cars[] = {"Bentley", "Lexus", "Porsche", "Rolls Royce", "Toyota"};
    int n = sizeof(arr) / sizeof(arr[0]);
    search(cars, "Bentley", n);
    std::cout << std::endl;

    search(cars, "Rolls Royce", n);
    std::cout << std::endl;

    return 0;
}