#include <iostream>
#include <unordered_map>
/*Write a function that counts the numbers of occurence of an element in an array */

// for a specific target
void count(int arr[], int n, int element)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            count++;
        }
    }
    if (count == 1)
        std::cout << element << " found once" << std::endl;
    else
        std::cout << element << " occured " << count << " times\n";
}

// For all the elements in the array
void count_all(int arr[], int n)
{
    // Create unordered map to store each elements as a key and the number of occurence as the value.
    std::unordered_map<int, int> frequency;
    for (int i = 0; i < n; i++)
    {
        if (frequency.find(arr[i]) == frequency.end())
        {
            frequency[arr[i]] = 1;
        }
        else
        {
            frequency[arr[i]]++;
        }
    }
    // Printing the result
    for (auto pair : frequency)
    {
        if (pair.second == 1)
            std::cout << pair.first << " occurred once." << std::endl;
        else
            std::cout << pair.first << " occurred " << pair.second << " times." << std::endl;
    }
    return;
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int price[] = {23, 2, 1, 2, 45, 2, 1, 32, 23, 32, 1, 2, 98, 0};
    int n = sizeof(price) / sizeof(price[0]);
    int target = 45;
    print_array(price, n);

    // For one element
    count(price, n, target);

    target = 1;
    count(price, n, target);

    std::cout << "_______________________________________________________" << std::endl;
    // For every element in the array
    count_all(price, n);
    return 0;
}