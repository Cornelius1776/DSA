#include <iostream>

int main()
{
    int a;
    int *a_ptr = &a;
    int b[100] = {};
    std::string fruits[] = {"Apple", "Banana", "Pineapple", "Watermelon"};
    std::string name;
    std::string *name_ptr;
    char x;
    char *x_ptr;
    short y;
    short *y_ptr;
    long long z;
    long long *z_ptr;
    double rate;
    double *rate_ptr;

    std::cout << "Size of int variable a is " << sizeof(a) << " bytes." << std::endl;
    std::cout << "Size of the pointer a_ptr is " << sizeof(a_ptr) << " bytes." << std::endl;
    std::cout << "Size of int b array is " << sizeof(b) << " bytes." << std::endl;
    std::cout << "Size of string fruits array is " << sizeof(fruits) << " bytes." << std::endl;
    std::cout << "Size of string name variable is " << sizeof(name) << " bytes." << std::endl;
    std::cout << "Size of string name pointer is " << sizeof(name_ptr) << " bytes." << std::endl;
    std::cout << "Size of char x variable is " << sizeof(x) << " bytes." << std::endl;
    std::cout << "Size of char x pointer is " << sizeof(x_ptr) << " bytes." << std::endl;
    std::cout << "Size of short y variable is " << sizeof(y) << " bytes." << std::endl;
    std::cout << "Size of short y pointer is " << sizeof(y_ptr) << " bytes." << std::endl;
    std::cout << "Size of long long z variable is " << sizeof(z) << " bytes." << std::endl;
    std::cout << "Size of long long z pointer is " << sizeof(z_ptr) << " bytes." << std::endl;
    std::cout << "Size of double rate variable is " << sizeof(rate) << " bytes." << std::endl;
    std::cout << "Size of double rate pointer is " << sizeof(rate_ptr) << " bytes." << std::endl;
    // short, int and long long are the same size as their unsigned counterparts
    return 0;
}
