#include <iostream>

// Time Complexity: Average case = O(nLogn), Worst case = O(n^2). Worst case is extremly rare and is prevented
// entirely using a randomised version of quick sort.
// Quick Sort is an in-place, Not stable, fast and useful for large datasets. Most sorting algorithms provided
// by default in Programming languages are quick sort implementation.

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

// Find pivot, and partition
int partition(int array[], int left, int right)
{
    int pivot = array[right]; // pivot = last element in the array
    int i = (left - 1);       // Larger element

    // Compare each array element with the pivot
    for (int j = left; j < right; j++)
    {
        if (array[j] <= pivot) // Depending on the desired sorting order >= can be used for descending
        {

            // if element at j is smaller than pivot is found, swap with the larger element pointed to by i
            i++;
            // swap element at i with element at j
            swap(array[i], array[j]);
        }
    }
    // swap pivot with the larger element at i
    swap(array[i + 1], array[right]);

    // return the partition point
    return (i + 1);
}

// Sorting
void quick_sort(int array[], int left, int right)
{
    if (left < right)
    {
        // Partitioning
        int pivot = partition(array, left, right);

        // elements smaller than pivot are on left of pivot
        quick_sort(array, left, pivot - 1);

        // elements greater than pivot are on righ of pivot
        quick_sort(array, pivot + 1, right);
    }
}

// print the arrays
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i];
        if (i != n - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

int main()
{
    int arr[] = {12, 3, 4, 23, 2, 4, 14, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Unsorted: ";
    print(arr, n);

    quick_sort(arr, 0, n - 1);

    std::cout << "Sorted: ";
    print(arr, n);

    return 0;
}