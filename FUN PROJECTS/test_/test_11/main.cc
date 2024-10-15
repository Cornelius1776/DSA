#include <iostream>

// time complexity = O(n)
// Brute force
/*void find_largest(int arr[], int n)
{
    int largest = arr[0];
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
            index = i;
        }
    }
    std::cout << "The largest element in the array is " << largest << " at index " << index << std::endl;
} */

// Two pointer approach
// Time complexity = O(n), but with fewer comparison. So, it is faster
void find_largest(int arr[], int n)
{
    int left = 0, right = n - 1, largest = arr[0], index = 0;
    while (left < right)
    {
        if (arr[left] > largest)
        {
            largest = arr[left];
            index = left;
        }
        if (arr[right] > largest)
        {
            largest = arr[right];
            index = right;
        }
        left++;
        right--;
    }
    std::cout << "The largest element in the array is " << largest << " at index " << index << std::endl;
}

int main()
{
    int arr[] = {76, 89, 82, 77, 83, 73, 98, 74, 70, 88};
    int n = sizeof(arr) / sizeof(*arr);
    find_largest(arr, n);

    return 0;
}