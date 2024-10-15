#include <iostream>

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Check if an array is sorted

bool is_sorted(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

void check(int *arr, int n)
{
    if (is_sorted(arr, n))
    {
        std::cout << "The array is sorted!" << std::endl;
        return;
    }
    std::cout << "Not sorted!" << std::endl;
}

// Bubblesort Algorithm and improvement

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Bubble sort algorithm improvement
void sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
}

int main()
{
    int rates[] = {23, 5, 45, 76, 8, 71};
    int n = sizeof(rates) / sizeof(*rates);
    print(rates, n);
    check(rates, n);

    // bubble_sort(rates, n);
    sort(rates, n);

    print(rates, n);
    check(rates, n);

    return 0;
}