#include <iostream>

void insertion_sort(int arr[], int n)
{
    int temp, empty;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        empty = i - 1;
        while (empty >= 0 && arr[empty] > temp)
        {
            arr[empty + 1] = arr[empty];
            empty = empty - 1;
        }

        arr[empty + 1] = temp;
    }
}

void print(int arr[], int n)
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
    int price[] = {32, 45, 4, 56, 7, 12, 8};
    int n = sizeof(price) / sizeof(price[0]);
    print(price, n);
    insertion_sort(price, n);
    print(price, n);

    return 0;
}