#include <iostream>

/* Merge Sort is a sorting algorithm that follows the Divide and Conquer paradigm.It divides the array
into two halves, sorts each half, and then merges the sorted halves back creating the sorted array.

 Time complexity = O(nLogn),
 Space complexity = O(n)
 Merge sort is not an in place algorithm because it requires more memory resources to
 copy the sub-array, Good for large datasets.
 */

// function to split the array and merge them after they are sorted using merge_sort
void merge(int arr[], int mid, int left, int right)
{
    int n_1 = mid - left + 1; // size of the left sub_array
    int n_2 = right - mid;    // size of the rigth sub_array

    /* create temporary sub_arrays of size n_1 and n_2 to split up the elements from arr*/
    int left_arr[n_1];
    int right_arr[n_2];

    // fill the sub_arrays
    for (int i = 0; i < n_1; ++i)
    {
        left_arr[i] = arr[left + i];
    }
    for (int j = 0; j < n_2; ++j)
    {
        right_arr[j] = arr[mid + 1 + j];
    }

    /* Merge the temp arrays */
    // Maintainning the index of the array
    int i = 0;    // initial index of the left sub_array
    int j = 0;    // initial index of the rigth sub_array
    int k = left; // initial index of the merged sorted array
    // Merging
    while (i < n_1 && j < n_2)
    {
        if (left_arr[i] <= right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
        }
        else
        {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left_arr[], if any
    while (i < n_1)
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right_arr[], if any
    while (j < n_2)
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

// Recursive syntax
void merge_sort(int arr[], int left, int right)
{
    if (right > left)
    {
        int mid = left + (right - left) / 2;

        // sort each halves of the array
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Merge the sorted halves to form the sorted array
        merge(arr, mid, left, right);
    }
}

// Iterative syntax. this is more complicated and therefore less used(I still find it hard to wrap my head around)
void merge_ite(int arr[], int n)
{
    int sub_arr_size; // current size of the individual sub array to be merged
    int left_start;   // starting index of the left sub array

    for (sub_arr_size = 1; sub_arr_size < n - 1; sub_arr_size = 2 * sub_arr_size)
    {

        for (left_start = 0; left_start < n - 1; left_start += 2 * sub_arr_size)
        {
            int mid = std::min(left_start + sub_arr_size - 1, n - 1);
            int right_end = std::min(left_start + 2 * sub_arr_size - 1, n - 1);
            merge(arr, left_start, mid, right_end);
        }
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
    print(arr, n);

    std::cout << "Sorted " << std::endl;
    int left = 0, right = n - 1;

    // Comment out one to print the others
    // merge_ite(arr, n);
    // print(arr, n);
    merge_sort(arr, left, right);
    print(arr, n);

    return 0;
}