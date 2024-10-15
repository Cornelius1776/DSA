#include <iostream>
#include <algorithm>

// Time complexity = O(n^2)
// Space complexty O(1) in-place algorithm

void bubble_sort(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++) // or j = i + 1; j < n; j++
        {
            if (arr[j] > arr[j + 1]) // arr[i] > arr[j] then these should also be used for the swapping
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                // The swapping can be done using std::swap(arr[j], arr[j + 1])
            }
        }
    }
    // print the sorted array
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Customized bubblesort to allow ascending and descending sort
// create 2 callback functions for bubblesort. one returns 1 if the first argument is greater than the second
// the other returns -1 if the second argument is greater, 0 if the arguments are equal
int ascending(int a, int b)
{
    return a - b;
    // same as below;
    /*  if (a > b)
     {
         return 1;
     }
     return -1; */
}

int descending(int a, int b)
{
    return b - a;
    /* if (a > b)
    {
        return -1;
    }
    return 1; */
}

void sort(int *arr, int n, int (*customize)(int, int))
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (customize(arr[i], arr[j]) > 0)
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Generic bubble_sort
template <typename A, typename T>
void gen_sort(A arr[], T n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// i wrote this to help me break down and understand the sorting process
void test(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                // shows the detail of the sorting steps
                for (int i = 0; i < n; i++)
                {
                    std::cout << arr[i] << " ";
                }
                std::cout << std::endl;
            }
        }
    }
}

int main()
{
    int arr[] = {3, 76, 8, 2, 4, 1, 60, 98};
    int n = sizeof(arr) / sizeof(arr[0]); // or *arr instead of arr[0]
    std::cout << "Original array" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorted array" << std::endl;
    bubble_sort(arr, n);

    // Customizable bubblesort
    std::cout << "Customizable bubblesort" << std::endl;
    int rate[] = {23, 12, 3, 2, 1, 46, -2, 87, 98, 35};
    n = sizeof(rate) / sizeof(rate[0]);
    sort(rate, n, descending); // biggest to smallest
    sort(rate, n, ascending);  // smallest to biggest

    // Generic bubblesort
    std::cout << "Generic bubble_sort" << std::endl;
    int price[] = {32, 45, 4, 56, 7, 12, 8};
    n = sizeof(price) / sizeof(price[0]);
    for (int i = 0; i < n; i++)
    {
        std::cout << price[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorted : ";
    gen_sort(price, n);

    // string
    std::string cars[] = {"Toyota", "Bentley", "Porsche", "Lexus", "Rolls Royce"};
    n = sizeof(cars) / sizeof(cars[0]);
    for (int i = 0; i < n; i++)
    {
        std::cout << cars[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorted : ";
    gen_sort(cars, n);

    // char
    char ch_arr[] = {'a', 'j', 's', 'u', 'b', 'c', 'd'};
    n = sizeof(ch_arr) / sizeof(ch_arr[0]);
    for (int i = 0; i < n; i++)
    {
        std::cout << ch_arr[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "Sorted : ";
    gen_sort(ch_arr, n);

    // test
    int test_arr[] = {203, 78, 85, 98, 4, 23, 12, 2, 1, 10};
    n = sizeof(test_arr) / sizeof(test_arr[0]);
    test(test_arr, n);

    // Built-in sort function
    std::string name[] = {"sam", "paul", "dami", "aaron"};
    n = sizeof(name) / sizeof(*name);
    std::cout << "Using the built-in sort" << std::endl;
    std::sort(name, name + n);
    for (int i = 0; i < n; i++)
    {
        std::cout << name[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}