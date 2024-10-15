#include <iostream>

/* Heap sort is a sorting algorithm that uses the binary-heap data structure */

/* heapify() helps heapify a subtree with the root at the given index. It assumes that the
 left and right sub-tree children of i are already max heaps, but the heap
 rooted at i may not be max heap. heapify() makes sure the heap property is maintained.

 heapify is the process of creating a heap from a binary tree
  */
void heapify(int arr[], int n, int i)
{
    /* Find largest element in array */
    int max = i;           // make the largest element the root
    int left = 2 * i + 1;  // index of the left sub-tree
    int right = 2 * i + 2; // index of the right sub-tree

    // check if largest is in the left sub-tree
    if (left < n && arr[i] < arr[left])
        max = left;

    // Check if largest is in the right sub-tree
    if (right < n && arr[max] < arr[right])
        max = right;

    // If largest is not at root then swap and recursively call for the new root
    if (max != i)
    {
        std::swap(arr[i], arr[max]);
        heapify(arr, n, max);
    }
}

// The heap sort itself
void heap_sort(int arr[], int n)
{
    // Build heap from input data. This rearranges the array
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        heapify(arr, n, i);
    }

    // Extracting an item from the heap one after the other
    for (int i = n - 1; i >= 0; i--)
    {
        std::swap(arr[0], arr[i]); // move current root to end
        heapify(arr, i, 0);        // call max heapify on the reduced heap
    }
}

// Print array
void print_arr(int arr[], int n)
{
    std::cout << "[";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i];
        if (i != n - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    int arr[] = {32, 20, 45, 34, 25, 60, 78, 91, 54};
    int n = sizeof(arr) / sizeof(arr[0]);
    print_arr(arr, n);

    std::cout << "Sorted" << std::endl;
    heap_sort(arr, n);
    print_arr(arr, n);

    return 0;
}