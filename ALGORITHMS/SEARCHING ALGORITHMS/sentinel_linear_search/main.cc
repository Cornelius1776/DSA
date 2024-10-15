#include <iostream>

int sentinel_search(int arr[], int n, int target)
{
    int last_element = arr[n - 1]; // sentinel

    arr[n - 1] = target;
    int element = 0;

    while (arr[element] != target)
    {
        element++;
    }

    arr[n - 1] = last_element;

    if ((element < n - 1) || arr[n - 1] == target)
    {
        std::cout << target << " is found at index ";
        return element;
    }
    return -1;
}

// Generic syntax
template <typename A, typename T>
void search(A arr[], T target, size_t n)
{
    int last_index = n - 1;
    T last_element = arr[last_index]; // T or A as the type would work
    arr[last_index] = target;
    int element = 0;

    while (arr[element] != target)
    {
        element++;
    }

    arr[last_index] = last_element;

    if (element < last_index || arr[last_index] == target)
    {
        std::cout << target << " found at index " << element << std::endl;
    }
    else
    {
        std::cout << target << " not found." << std::endl;
    }
}

template <typename T>
void print_array(T arr[], int n)
{
    std::cout << "[";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i];
        if (i < n - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main()
{
    std::cout << std::endl;

    int arr[] = {2, 3, 1, 4, 56, 8};
    int length = sizeof(arr) / sizeof(arr[0]), target = 1;
    print_array(arr, length);
    int result = sentinel_search(arr, length, target);
    std::cout << result << std::endl;

    target = 38;
    result = sentinel_search(arr, length, target);
    std::cout << result << std::endl;

    target = 8;
    result = sentinel_search(arr, length, target);
    std::cout << result << std::endl;

    target = 3;
    result = sentinel_search(arr, length, target);
    std::cout << result << std::endl;

    std::cout << std::endl;

    // Generic driver code
    std::cout << "Generic implementation" << std::endl;
    print_array(arr, length);
    target = 22;
    search(arr, target, length);

    target = 1;
    search(arr, target, length);

    std::string fruits[] = {"apple", "mango", "watermelon", "banana"};
    int size = sizeof(fruits) / sizeof(fruits[0]);
    print_array(fruits, size);
    std::string target_fruit = "apple";
    search(fruits, target_fruit, size);

    target_fruit = "banana";
    search(fruits, target_fruit, size);

    target_fruit = "mango";
    search(fruits, target_fruit, size);

    return 0;
}