#include <iostream>

template <typename T>
void print_array(T *arr, int n)
{
    if (n <= 0)
    {
        std::cout << std::endl;
        return;
    }
    std::cout << *arr << " ";
    print_array(arr + 1, n - 1);
}

int main()
{
    int numbers[] = {2, 3, 2, 6, 4, 7, 8};
    int n = sizeof(numbers) / sizeof(*numbers);
    print_array(numbers, n);

    std::string cities[] = {"New York", "London", "Tokyo", "Shangai"};
    n = sizeof(cities) / sizeof(*cities);
    print_array(cities, n);

    std::cout << "Element " << *numbers << " Address " << numbers << std::endl;
    std::cout << "Element " << *numbers + 1 << " Address " << &numbers + 1 << std::endl;

    return 0;
}