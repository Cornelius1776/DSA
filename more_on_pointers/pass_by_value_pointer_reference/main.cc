#include "draw_line.h"

// Pass by value
void test(int a)
{
    a++;
    // std::cout << a << std::endl; // increments inside test() but not in main()
    std::cout << "Memory address of the value argument inside test() " << &a << std::endl;
}

// pass by reference (Using pointer)
void test_ptr(int *a)
{
    //(*a) + 1 or *a = (*a) + 1; Also valid
    (*a)++; // point to the address of the argument when test_ptr() is called in main and increments its value.
    std::cout << "Memory address of the argument inside test_ptr() " << a << std::endl;
}

// Pass by reference
void test_ref(int &a)
{
    a++; // having receive memory address as argument, it increments the value of the argument passed
    std::cout << "Memory address of the argument inside test_ref() " << &a << std::endl;
}

/* Under the hood, refernce is a pointer, but with syntax sugar meaning in some cases, it is easier to implement */

int main()
{
    // pass by value
    std::cout << "function pass by value" << std::endl;
    int a = 2;
    test(a);
    std::cout << a << std::endl;
    std::cout << "Memory address of the variable argument inside main() " << &a << std::endl;
    draw_line();

    // pass by reference (Using pointers)
    std::cout << "function pass by reference(Using pointers)" << std::endl;
    a = 2;
    test_ptr(&a);
    std::cout << a << std::endl; // increments
    std::cout << "Memory address of the argument inside main() " << &a << std::endl;
    draw_line();

    // pass by reference
    std::cout << "function pass by reference" << std::endl;
    a = 2;
    test_ref(a);
    std::cout << a << std::endl; // increments
    std::cout << "Memory address of the argument inside main() " << &a << std::endl;
    draw_line();

    return 0;
}