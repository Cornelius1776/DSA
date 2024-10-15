#include <iostream>

int *global_ptr;
// because global and static variables are equal to zero by default, their pointers are nullptr by default.

int main()
{
    std::cout << std::endl;

    // Storing variable memory address
    std::cout << "Storing variable memory address " << std::endl;
    int a = 10;
    int *a_ptr = &a;
    std::cout << "Address is " << a_ptr << " the value is " << *a_ptr << std::endl;
    a = 23;
    std::cout << "Address is " << a_ptr << " the value is " << *a_ptr << std::endl;

    // Pointer to pointer(pointer chain)
    std::cout << "Pointer to pointer" << std::endl;
    int x = 4;
    int *x_ptr = &x;
    int **x_ptr_ptr = &x_ptr;
    int ***x_ptr_ptr_ptr = &x_ptr_ptr;

    std::cout << "The variable " << x << std::endl;
    std::cout << x_ptr << std::endl;
    std::cout << x_ptr_ptr << std::endl;
    std::cout << x_ptr_ptr_ptr << std::endl;

    // Dereferencing pointer to pointer
    std::cout << "Dereferencing pointer to pointers" << std::endl;
    std::cout << "The variable " << x << std::endl;
    std::cout << *x_ptr << std::endl;
    std::cout << **x_ptr_ptr << std::endl;
    std::cout << ***x_ptr_ptr_ptr << std::endl;

    // reassigning the variable using the outermost pointer
    std::cout << "reassigning the variable using the outermost pointer" << std::endl;
    ***x_ptr_ptr_ptr = 10;
    std::cout << "The variable " << x << std::endl;
    std::cout << *x_ptr << std::endl;
    std::cout << **x_ptr_ptr << std::endl;
    std::cout << ***x_ptr_ptr_ptr << std::endl;

    // Using the mid pointer
    std::cout << "Using the mid pointer" << std::endl;
    **x_ptr_ptr = *x_ptr + 5;
    std::cout << "The variable " << x << std::endl;
    std::cout << *x_ptr << std::endl;
    std::cout << **x_ptr_ptr << std::endl;
    std::cout << ***x_ptr_ptr_ptr << std::endl;
    std::cout << std::endl;

    // Using pointers in logical expressions
    int *price_ptr = nullptr;

    if (price_ptr) // evalutess to true for holding an address
    {
        std::cout << "the pointer holds an address" << std::endl; // true
    }
    else
    {
        std::cout << "the pointer is NOT holding an address" << std::endl; // false
    }

    int price = 200;
    price_ptr = &price;

    if (price_ptr)
    {
        std::cout << "the pointer holds an address" << std::endl;
    }
    else
    {
        std::cout << "the pointer is NOT holding an address" << std::endl;
    }

    // void pointers: they are generic.
    /*  Void pointers can NOT be derefrenced. Because memory is assigned at compile time, while assigning type
     to generics take place at runtime, therefore there is no way for the compiler to know what type it is
     and/or read its memory address. However, as always C++ has a short-cut for every(almost every) scenario.
     So, to dereference a void pointer, typecast it first, then dereference. Done below */

    int age = 26;
    std::string name = "Cornelius";
    float pi = 3.142;
    void *ptr = nullptr;

    std::cout << "Using void pointer" << std::endl;
    ptr = &age;
    std::cout << ptr << " : " << *(int *)ptr << std::endl;

    ptr = &name;
    std::cout << ptr << " : " << *(std::string *)ptr << std::endl;

    ptr = &pi;
    std::cout << ptr << " : " << *(float *)ptr << std::endl;

    std::cout << sizeof(int) << " bytes." << std::endl;
    std::cout << sizeof(int *) << " bytes." << std::endl;
    std::cout << sizeof(void *) << " bytes." << std::endl;

    // Global and static pointers
    static int *static_ptr;

    int y = 509, z = 600;

    std::cout << static_ptr << std::endl;
    std::cout << global_ptr << std::endl;

    static_ptr = &y;
    global_ptr = &z;

    std::cout << static_ptr << " : " << *static_ptr << std::endl;
    std::cout << global_ptr << " : " << *global_ptr << std::endl;

    return 0;
}
