#include <iostream>
/* Time complexity = O(n^2)
   Space Complexity = O(1)
   unstable, in-place, internal sorting algorithm
*/
void selection_sort(int arr[], int n)
{
    std::cout << "int selection_sort" << std::endl; // Added this to check the function overloading
    for (int i = 0; i < n - 1; i++)
    {
        int smallest = i; // elements from i to n -1 are all included
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallest])
            {
                smallest = j; // Update the index of the smallest element in the array
            }
        }
        std::swap(arr[i], arr[smallest]);
    }
}

// Generic Selection selection_sort
template <typename A, typename T>
void selection_sort(A arr[], T n)
{
    std::cout << "generic sort" << std::endl; // Added this to check the function overloading
    for (int i = 0; i < n - 1; i++)
    {
        T smallest = i; // elements from i to n -1 are all included
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallest])
            {
                smallest = j; // Update the index of the smallest element in the array
            }
        }
        std::swap(arr[i], arr[smallest]);
    }
}

// Sort string
void sort_string(std::string arr[], int n)
{
    std::cout << "String sort" << std::endl; // Added this to check the function overloading
    for (int i = 0; i < n - 1; i++)
    {
        int smallest = i; // elements from i to n -1 are all included
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j].length() < arr[smallest].length()) // .length() allow to sort based on the length of the string
            {
                smallest = j; // Update the index of the smallest element in the array
            }
        }
        std::swap(arr[i], arr[smallest]);
    }
}

// To print the arrays
template <typename T>
void print_array(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int arr[] = {3, 4, 1, 2, 6, 7, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, n);

    std::cout << "Sorted" << std::endl;
    selection_sort(arr, n);
    print_array(arr, n);

    std::cout << "Using generic implementation" << std::endl;

    int prices[] = {34, 23, 43, 54, 12, 21};
    n = sizeof(prices) / sizeof(prices[0]);
    print_array(prices, n);
    selection_sort(prices, n); // Function overloading, it will use the int selection_sort() instead of the generic one
    print_array(prices, n);

    std::cout << std::endl;

    float frequencies[] = {91.9, 87.5, 99.1, 89.6, 97.3, 101.9, 95.5};
    n = sizeof(frequencies) / sizeof(frequencies[0]);
    print_array(frequencies, n);
    selection_sort(frequencies, n);
    print_array(frequencies, n);

    std::cout << std::endl;

    std::string names[] = {"Samuel", "John", "Abiola", "Peter", "Cornelius", "Ola"};
    n = sizeof(names) / sizeof(names[0]);
    print_array(names, n);
    selection_sort(names, n);
    print_array(names, n);

    sort_string(names, n);
    print_array(names, n);

    return 0;
}