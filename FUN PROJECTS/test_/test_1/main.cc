#include <iostream>
#include <array>

void add(int *num)
{
    (*num)++;
    // std::cout << num << std::endl;
}
/*Technically the above is called pass by pointer but since refernce is made to the memory address, it can
simply be called pass by reference. Tecnically also, pass by refernce add() is done below. same output.
void add(int &num)
{
    n++;
}
Inside main() simply use the variable as such add(num), the address has already been used as the parameter.
*/

template <typename T>
void print_array(const T &arr)
{
    auto element = arr.begin();

    std::cout << "[";
    while (element != arr.end())
    {
        std::cout << *element;
        if (element != arr.end() - 1)
        {
            std::cout << ", ";
        }
        element++;
    }
    std::cout << "]";
    std::cout << std::endl;
}

int main()
{
    int num = 10;
    int *num_ptr = &num;
    add(num_ptr);
    std::cout << num << std::endl;

    int arr[] = {1, 2, 3, 4, 5, 6};
    for (auto &&element : arr)
    {
        std::cout << &element << " : " << element << "\n";
    }

    std::cout << arr << std::endl;

    /*  std::array<int, 5> numbers = {23, 43, 54, 76, 87};
     std::array<std::string, 4> fruits = {"apple", "banana", "avocado", "watermelon"};
     print_array(numbers);
     print_array(fruits);
     std::cout << numbers[4] << std::endl;
     std::cout << numbers.at(4) << std::endl;
     std::cout << fruits[0] << std::endl;
     std::cout << fruits.at(0) << std::endl; */

    /*  // Out of bound test
     std::cout << "Out of bound" << std::endl;
     std::cout << numbers[8] << std::endl;    // outputs junk value
     std::cout << numbers.at(8) << std::endl; // Terminates execution */

    return 0;
}