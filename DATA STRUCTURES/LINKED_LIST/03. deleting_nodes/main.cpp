#include <iostream>
#include "delete.h"

int main()
{
    head = nullptr;

    insert(36);
    insert(65);
    insert(45);
    insert(78);
    output();

    int n; // nth position
    std::cout << "Enter a positon" << std::endl;
    std::cin >> n;
    delete_node(n);

    output();

    return 0;
}