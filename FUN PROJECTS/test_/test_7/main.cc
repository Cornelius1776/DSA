#include <iostream>

int main()
{
    std::cout << "Hello World" << std::endl;
    std::string name = "Cornelius";
    std::cout << "the size is " << sizeof(name) << std::endl;
    int arr[] = {24, 45, 30, 1, 29, 5, 76, 70};
    int n = sizeof(arr) / sizeof(*arr);
    int target_sum = 30;

    // Time complexity = O(n^2)
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target_sum)
            {
                std::cout << arr[i] << ", " << arr[j] << std::endl;
            }
        }
    }

    return 0;
}