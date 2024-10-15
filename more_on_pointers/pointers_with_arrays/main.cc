#include <iostream>

int main()
{ // Typecasting the hex memory address to long long
    int b = 2;
    int *b_ptr = &b;
    uint_fast64_t c = (uint_fast64_t)b_ptr;
    std::cout << c << std::endl;
    std::cout << b_ptr << std::endl;

    int arr[5] = {2, 4, 6, 8, 10};
    int *element_1 = &arr[0];
    int *element_5 = &arr[4];

    std::cout << "address of element at index 4 " << (uint_fast64_t)element_5 << std::endl;
    std::cout << "address of element at index 0 " << (uint_fast64_t)element_1 << std::endl;
    std::cout << "Difference = " << element_5 - element_1 << std::endl; // 4
    /* We get 4 because even though the difference of the bytes address of the first element(element_1) and
    last element (element_5) are 16 bytes, the difference is 4 because only the address of the first bytes of
    the integers is taken into consideration and is also the relevant address of the variable. So, the first
    addresses amount to 4. */

    std::cout << "Using the array" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Address: " << &arr[i] << " Element: " << arr[i] << std::endl;
    }

    std::cout << "Using pointers" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "address = " << element_1 << " element = " << *element_1 << std::endl;
        element_1++;
    }

    return 0;
}