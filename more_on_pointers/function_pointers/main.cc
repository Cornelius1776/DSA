#include <iostream>
#include <cmath>

int multiply(int q, int r)
{
    return q * r;
}

void greet(std::string name)
{
    std::cout << "Hello " << name << std::endl;
}

void called()
{
    std::cout << "Hi everyone" << std::endl;
}

void call_back(void (*called_ptr)())
{
    called_ptr();
}

// Function pointers use cases
// .1 Sorting
// ascending sort
int ascending(int a, int b)
{
    if (a > b)
    {
        return 1;
    }
    return -1;
    // return a - b; is equivalent to the above
}

// Descending sort
int descending(int a, int b)
{
    if (a > b)
    {
        return -1;
    }
    return 1;
    // return b - a;
}

void bubble_sort(int arr[], int n, int (*compare)(int, int))
{
    int temp_var;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (compare(arr[j], arr[j + 1]) > 0)
            {
                temp_var = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp_var;
            }
        }
    }
}

// Sort in increasing order of absolute integers
int absolute(int a, int b)
{
    if (abs(a) < abs(b)) // abs() from the cmath library
    {
        return -1;
    }
    return 1;

    // return abs(a) - abs(b);
}

// const void allows the arguments received to be generic, until it's type is educed at runtime
template <typename T>
T compare(const void *a, const void *b)
{
    T x = *((T *)a); // Typecast (), dereferenced (())
    T y = *((T *)b);
    return x - y; // Ascending
    // return y - x; // Descending
    //  return abs(x) - abs(y); // increasing order of absolute integers
}

// passing functions to pointer functions
int (*f_ptr)(int); // recieves a function that returns an int

int square(int num)
{
    return num * num;
}

int square_1(int num_1, int num_2)
{
    std::cout << num_1 << " * " << num_2 << " = ";
    return num_1 * num_2;
}

int my_add(int num_1, int num_2)
{
    std::cout << num_1 << " + " << num_2 << " = ";
    return num_1 + num_2;
}
int subtract(int num_1, int num_2)
{
    std::cout << num_1 << " - " << num_2 << " = ";
    return num_1 - num_2;
}

// It is good to use type definition for function pointers
typedef int (*func_ptr_operation)(int, int);
int compute(func_ptr_operation operation, int num_1, int num_2)
{
    return operation(num_1, num_2);
}

int main()
{
    // Function Pointers
    int q = 3, r = 4;
    int (*func_ptr)(int, int);
    func_ptr = &multiply;   // or &multiply
    int o = func_ptr(q, r); // or (*func_ptr)(q, r)
    std::cout << "o = " << o << std::endl;

    void (*greet_ptr)(std::string) = greet;
    std::string name = "Cornelius";
    greet_ptr(name);
    std::cout << std::endl;

    // Function pointers and callbacks
    void (*call_ptr)() = called;
    call_back(call_ptr);
    // instead of the 2 lines above, single line below does the same
    call_back(called);
    std::cout << std::endl;

    // Function pointers use cases
    // 1. sorting
    std::cout << "Sorting in..." << std::endl;
    int prices[] = {12, 5, 76, 8, 4, 10, 1, -1, -5, 2, -4, 9, -6};
    int n = sizeof(prices) / sizeof(prices[0]);
    // Sort in ascending order
    bubble_sort(prices, n, ascending);
    std::cout << "Ascending order: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << prices[i] << " ";
    }
    std::cout << std::endl;

    // Sort in descending order
    bubble_sort(prices, n, descending);
    std::cout << "Descending order: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << prices[i] << " ";
    }
    std::cout << std::endl;

    // Sort in increasing order of absolute integers
    bubble_sort(prices, n, absolute);
    std::cout << "Absolute order: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << prices[i] << " ";
    }
    std::cout << std::endl;

    // Using the generic qsort(quick sort algorithm) from standard library
    int rates[] = {32, 5, 2, 6, 1, 7, 98, 67, -2, 1, -5, 8};
    n = sizeof(rates) / sizeof(*rates);
    qsort(rates, n, sizeof(int), compare);
    std::cout << "Generic using qsort(): ";
    for (int i = 0; i < n; i++)
    {
        std::cout << rates[i] << " ";
    }
    std::cout << std::endl;

    std::string names[] = {"paul", "toafeek", "abiola", "ade"};
    n = sizeof(names) / sizeof(*names);
    qsort(names, n, sizeof(std::string), compare);
    for (int i = 0; i < n; i++)
    {
        std::cout << names[i] << " ";
    }
    std::cout << std::endl;

    // passing a function to a function pointer
    n = 5;
    f_ptr = square;
    std::cout << "the square of " << n << " is " << f_ptr(n) << std::endl;

    std::cout << compute(my_add, 6, 5) << std::endl;
    std::cout << compute(subtract, 6, 5) << std::endl;
    std::cout << compute(square_1, 6, 5) << std::endl;

    return 0;
}