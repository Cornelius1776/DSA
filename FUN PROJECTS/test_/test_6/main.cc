#include <iostream>
#include <vector>

void print_vector(std::vector<int> arr)
{
    int count = 0;
    for (const auto element : arr)
    {
        std::cout << element << " ";
        count++;
    }
    std::cout << " (" << count << " in total)." << std::endl;
}

int main()
{
    int numbers[] = {2, 77, 45, 12, 93, 4, 86, 76, 23, 82};
    int n = sizeof(numbers) / sizeof(*numbers);

    for (int i = 0; i < n; i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> odd_elements, even_elements;

    for (int i = 0; i < n; i++)
    {
        if (numbers[i] % 2 == 0)
        {
            even_elements.push_back(numbers[i]);
        }
        else
        {
            odd_elements.push_back(numbers[i]);
        }
    }

    std::cout << "The odd_elements elements: ";
    print_vector(odd_elements);

    std::cout << "The even_elements elements: ";
    print_vector(even_elements);

    return 0;
}