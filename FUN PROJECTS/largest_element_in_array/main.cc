#include <iostream>

// Finding the largest element in the array
// Brute force O(n) time, O(1) space
void largest(int *arr, int n)
{
    if (n == 0) {
        std::cout << "Array is empty" << std::endl;
        return;
    } 
    
    int largest_element = arr[0];
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest_element )
        {
            largest_element = arr[i];
            index = i;
        }
    }
    std::cout << "The largest is " << largest_element << " at index " << index << std::endl;
}

// Two pointer approach O(n) time also but still more efficient due to fewer number of comparisons
void largest_2(int *arr, int n)
{
    if (n == 0) {
        std::cout << "Array is empty" << std::endl;
        return;
    } 
    int largest_element = arr[0]; 
    int index = 0;  
    // two pointers
    int start_index = 0;
    int end_index = n - 1;
    
    while (start_index <= end_index)
    {
        if (arr[start_index] > largest_element )
        {
            largest_element = arr[start_index];
            index = start_index;
        }
        if (arr[end_index] > largest_element )
        {
            largest_element = arr[end_index];
            index = end_index;
        }
        start_index++;
        end_index--;
    }
    
    std::cout << "The largest element is " << largest_element << " at index " << index << std::endl;
}


// print array
void print(int arr[], int n)
{
    std::cout << "[";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i];
        if (i < n - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    int rate[] = {23, 8, 17, 5, 45, 76, 54, 9, 7};
    int n = sizeof(rate) / sizeof(*rate);
    print(rate, n);
    largest(rate, n);
    largest_2(rate, n);

    return 0;
}