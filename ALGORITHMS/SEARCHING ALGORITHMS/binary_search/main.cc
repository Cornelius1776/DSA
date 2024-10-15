#include <iostream>
#include <cmath>

// Recusive approach
/* int binary_search(int arr[], int left, int right, int target)
{
    if (right >= left)
    {

        int mid_point = left + (right - left) / 2; // or = (left + right) / 2

        if (target == arr[mid_point])
        {
            // data found at the mid_point index
            std::cout << target << " is found at index ";
            return mid_point;
        }
        else if (target < arr[mid_point])
        {
            // search target in the left sub-array
            return binary_search(arr, left, mid_point - 1, target);
        }
        else
        {
            // search target in the right sub-array
            return binary_search(arr, mid_point + 1, right, target);
        }
    }
    return -1;
}
 */
// Iterative approach
int binary_search(int arr[], int length, int target)
{
    int left = 0, right = length - 1;
    while (left <= right)
    {
        int mid_point = left + (right - left) / 2;

        // check if target is at the mid point
        if (target == arr[mid_point])
        {
            std::cout << target << " is found at index ";
            return mid_point;
        } // if target is greater than mid point, ignore the left half of the array and mid point
        else if (target > arr[mid_point])
        {
            left = mid_point + 1;
        } // target is less than mid point, ignore the right half
        else
        {
            right = mid_point - 1;
        }
    }
    return -1;
}

// Generic binary search
template <typename C, typename T>
void search(C *arr, size_t n, T target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid_point = left + (right - left) / 2;

        if (arr[mid_point] == target)
        {
            std::cout << target << " is found at index " << mid_point << std::endl;
            return;
        }
        else if (target > arr[mid_point])
        {
            left = mid_point + 1;
        }
        else
        {
            right = mid_point - 1;
        }
    }

    std::cout << target << " not found.\n";
}

/* Since binary search works properly only for sorted arrays. In case the array is not sorted, a sorting
algorithm can be used to sort it before doing the search.  */

// Implementing a  generic bubblesort algorithm
template <typename T>
void sort(T arr[], size_t n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }
    // print the sorted output
    std::cout << "Sorted: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void print_array(T arr[], size_t n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // Recursive driver code
    /* int arr[] = {-1, 0, 1, 2, 3, 4, 5, 7, 9, 10, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 4, left = 0, right = n - 1;
    int result = binary_search(arr, left, right, target);
    std::cout << result << std::endl;

    target = 10;
    result = binary_search(arr, left, right, target);
    std::cout << result << std::endl;

    target = 0;
    result = binary_search(arr, left, right, target);
    std::cout << result << std::endl;

    target = 13;
    result = binary_search(arr, left, right, target);
    std::cout << result << std::endl; */

    // Iterative driver code
    int arr[] = {-1, 0, 1, 2, 3, 4, 5, 7, 9, 10, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 0;
    int result = binary_search(arr, n, target);
    std::cout << result << std::endl;

    target = -1;
    result = binary_search(arr, n, target);
    std::cout << result << std::endl;

    target = 4;
    result = binary_search(arr, n, target);
    std::cout << result << std::endl;
    std::cout << std::endl;

    // Generic driver code
    target = 3;
    search(arr, n, target);

    target = 11;
    search(arr, n, target);

    target = 0;
    search(arr, n, target);

    std::string animals[] = {"caiman", "cat", "dog", "owl", "sheep"};
    n = sizeof(animals) / sizeof(animals[0]);
    std::string animal = "sheep";
    search(animals, n, animal);

    animal = "cow";
    search(animals, n, animal);

    animal = "dog";
    search(animals, n, animal);

    char ch_arr[] = {'a', 'b', 'c', 'd'};
    n = sizeof(ch_arr) / sizeof(ch_arr[0]);
    char letter = 'a';
    search(ch_arr, n, letter);

    letter = 'p';
    search(ch_arr, n, letter);

    letter = 'b';
    search(ch_arr, n, letter);

    // Sorting before doing the search
    int numbers[] = {23, 4, 22, 122, 2, 65, 1, 13};
    n = sizeof(numbers) / sizeof(*numbers);
    print_array(numbers, n);
    sort(numbers, n);
    target = 2;
    search(numbers, n, target);

    return 0;
}
