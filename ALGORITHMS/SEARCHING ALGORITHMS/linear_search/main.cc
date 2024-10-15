#include <iostream>
#include <vector>
#include <string>
/* Linear search is used to seacrh for and find elements in an unsorted data structure e.g array,
etc. The element being searched(target) is compared with all the elements in the array since the
array in not sorted, during the seacrh, the moment the target matches an element in the array, the
index of the element is returned which means the element has been found, else it returns -1, meaning
the target is not found. */

// Iterative syntax
/* int search(int *arr, int n, int target)
{
    for (int i = 0; i <= n; i++)
    {
        if (target == arr[i])
        {
            std::cout << target << " is found at index ";
            return i;
        }
    }

    return -1;
} */

// Recursive syntax
int search(int arr[], int n, int target)
{
    int index = n - 1; // index of the element in the array

    if (n == 0)
    {
        return -1;
    }

    if (target == arr[index])
    {
        std::cout << target << " is found at index ";
        return index;
    }

    return search(arr, index, target);
}

// Linear search for 2 dimensional array can be modified for 3D
std::vector<int> search_2D(std::vector<std::vector<int>> arr, int target)
{
    for (int i = 0; i <= arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (target == arr[i][j])
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

// string search
void str_search(std::string arr[], int n, std::string target)
{
    for (int i = 0; i < n; i++)
    {
        if (target == arr[i])
        {
            std::cout << target << " is found at index " << i << "\n";
            return;
        }
    }

    std::cout << target << " not found. ";
}

// Generic linnear search
template <typename A, typename T>
void linear_search(A *arr, int n, T target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            std::cout << target << " found at index " << i << std::endl;
            return;
        }
    }
    std::cout << target << " not found" << std::endl;
}

int main()
{
    std::cout << std::endl;

    int arr[] = {2, 3, 1, 4, 56, 8}, length = sizeof(arr) / sizeof(arr[0]), target = 56;
    int result = search(arr, length, target);
    std::cout << result << std::endl;

    target = 30;
    result = search(arr, length, target);
    std::cout << result << std::endl;

    target = 3;
    result = search(arr, length, target);
    std::cout << result << std::endl;

    std::cout << std::endl;

    // 2D linear search
    std::vector<std::vector<int>> arr_2D = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    target = 5;
    std::vector<int> my_result = search_2D(arr_2D, target);
    std::cout << "target " << target << " found at index " << my_result[0] << "(outer) and at index "
              << my_result[1] << "(inner)" << std::endl;
    std::cout << std::endl;

    // String search
    std::string cars[] = {"Toyota", "Bentley", "Porsche", "Lexus", "Rolls Royce"};
    int n = sizeof(arr) / sizeof(arr[0]);
    str_search(cars, n, "Bentley");
    std::cout << std::endl;

    // Generic linear search
    std::cout << "Generic linear search" << std::endl;
    linear_search(arr, length, 8);
    linear_search(arr, length, 80);

    linear_search(cars, n, "Rolls Royce");
    linear_search(cars, n, "Mustang");
    linear_search(cars, n, "Toyota");

    char ch_arr[] = {'a', 'b', 'c', 'd'};
    n = sizeof(ch_arr) / sizeof(ch_arr[0]);
    linear_search(ch_arr, n, 'a');
    linear_search(ch_arr, n, 'b');
    linear_search(ch_arr, n, 'g');

    return 0;
}
