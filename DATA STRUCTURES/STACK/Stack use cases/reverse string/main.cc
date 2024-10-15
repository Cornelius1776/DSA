#include "string.h"

int main()
{
    Stack stack;
    char my_string[] = "Technology";
    std::cout << my_string << std::endl;
    stack.reverse(my_string);
    std::cout << "String reversed: " << my_string << std::endl;

    return 0;
}