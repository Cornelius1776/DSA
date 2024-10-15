#include <iostream>

int ternary_search(int *arr, int target, int left, int right)
{
    if (right >= left)
    {
        int mid_1 = left + (right - left) / 3;
        int mid_2 = left + (right - left) / 3;
        // int mid_2 = right - (right - left) / 3;

        if (arr[mid_1] == target)
        {
            std::cout << target << " found at index ";
            return mid_1;
        }
        if (arr[mid_2] == target)
        {
            std::cout << target << " is found at index ";
            return mid_2;
        }

        if (target < arr[mid_1])
        {
            return ternary_search(arr, target, left, mid_1 - 1);
        }
        else if (target > arr[mid_2])
        {
            return ternary_search(arr, target, mid_2 + 1, right);
        }
        else
        {
            return ternary_search(arr, target, mid_1 + 1, mid_2 - 1);
        }
    }

    return -1;
}

void print(int *arr, int n)
{
    static int i;
    if (i == n)
    {
        std::cout << std::endl;
        return;
    }
    std::cout << arr[i] << " ";
    i++;
    print(arr, n);
}

int main()
{
    int prices[] = {23, 34, 45, 54, 56, 76, 78, 98, 293};
    int n = sizeof(prices) / sizeof(prices[0]);
    int left = 0, right = n - 1, target = 56;

    print(prices, n);

    int result = ternary_search(prices, target, left, right);
    std::cout << result << std::endl;
    std::cout << std::endl;

    target = 23;
    result = ternary_search(prices, target, left, right);
    std::cout << result << std::endl;
    std::cout << std::endl;

    target = 293;
    result = ternary_search(prices, target, left, right);
    std::cout << result << std::endl;
    std::cout << std::endl;

    target = 98;
    result = ternary_search(prices, target, left, right);
    std::cout << result << std::endl;
    std::cout << std::endl;

    return 0;
}