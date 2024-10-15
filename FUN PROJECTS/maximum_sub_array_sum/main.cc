#include <iostream>
#include <limits.h>
/* Given an array of n numbers, calculate the maximum subarray sum, i.e., the largest possible
sum of a sequence of consecutive values in the array. implement in C++ with different time
complexities of O(n^3), O(n^2),  and O(n) */

// O(n ^ 3) worst
/*void max_sum(int arr[], int n)
{
    int largest = INT_MIN;      // or simply 0, like sum below
    for (int i = 0; i < n; i++) // i = size of the sub-array
    {
        for (int j = i; j < n; j++) // j = start index
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            largest = std::max(largest, sum);
        }
    }
    std::cout << "max sum is " << largest << "\n";
}*/

// O(n ^ 2) better
/*void max_sum(int arr[], int n)
{
    int largest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            largest = std::max(largest, sum);
        }
    }
    std::cout << "max sum is " << largest << "\n";
}*/

// O(n) best. also called Kadane's algorithm. This is better than the two brute force approach above
void max_sum(int arr[], int n)
{
    int largest = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = std::max(arr[i], sum + arr[i]);
        largest = std::max(largest, sum);
    }
    std::cout << "max sum is " << largest << "\n";
}

// Printing the array
void print_array(int *arr, int n)
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

// Using Divide and Conquer algoritm(Split the problem into small chunks and solve one by one)
// 0(n log n)
int div_and_conq(int arr[], int n)
{
    // Base case. if the array has only one element, then that is the max sum.
    if (n == 1)
    {
        return arr[0];
    }

    int half_size = n / 2;
    int left_sub_arr = div_and_conq(arr, half_size);
    int right_sub_arr = div_and_conq(arr + half_size, n - half_size);
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    int sum = 0;

    for (int i = half_size; i < n; i++)
    {
        sum += arr[i];
        right_sum = std::max(right_sum, sum);
    }

    sum = 0;

    for (int i = (half_size - 1); i >= 0; i--)
    {
        sum += arr[i];
        left_sum = std::max(left_sum, sum);
    }

    int largest = std::max(left_sub_arr, right_sub_arr);
    return std::max(largest, left_sum + right_sum);
}

int main()
{
    int arr[] = {9, 2, -6, 7, -3, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, n);
    max_sum(arr, n);
    std::cout << "Using divide and conquer:\nMax sum is " << div_and_conq(arr, n) << std::endl;

    return 0;
}