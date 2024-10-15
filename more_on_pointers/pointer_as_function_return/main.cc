#include "draw_line.h"

// returns value pass by value
int add(int u, int w)
{
    std::cout << "memory address in add() u = " << &u << " : w = " << &w << std::endl;
    int z = u + w;
    return z;
}

// returns reference, pass by reference
int *add_1(int *u, int *w)
{
    // The value of u and w in add() is the memory address of u and w in main().
    // u and w in add() are pointers to u and w in main(). so, the 2 immediate lines below gives the same output
    std::cout << "value of u and w in add() u = " << u << " : w = " << w << std::endl; // Same as below
    // std::cout << "memory address in add() u = " << u << " : w = " << w << std::endl;
    int *z = new int;
    *z = (*u) + (*w);
    std::cout << "value of z in add() = " << z << std::endl;
    delete z;
    return z;
}

// returns reference, pass by value
int *add_2(int u, int w)
{
    std::cout << "memory address in add() u = " << &u << " : w = " << &w << std::endl;
    int *z = new int;
    *z = u + w;
    std::cout << "value of z in add() = " << z << std::endl;
    delete z;
    return z;
}

int main()
{
    // returns value
    std::cout << "Pointers as function return(pass by value) " << std::endl;
    int u = 2;
    int w = 3;
    int x = add(u, w); // The values of u and w  variables in main() is copied to u and w arguments of add()
    std::cout << "z = " << x << std::endl;
    std::cout << "memory address in main() u = " << &u << " : w = " << &w << std::endl;
    draw_line();

    // returns reference, pass by reference
    std::cout << "Pointers as function return(return reference, pass by reference) " << std::endl;
    u = 2;
    w = 3;
    int *y = add_1(&u, &w); // The address of u and w  variables in main() is copied to u and w arguments of add()
    std::cout << "memory address of u and w in main() u = " << &u << " : w = " << &w << std::endl;
    std::cout << "(dereferenced) y = " << *y << std::endl;
    std::cout << "value of y in main() = " << y << std::endl; // which is the address of add_1()
    std::cout << std::endl;
    draw_line();

    // returns reference, passs by value
    std::cout << "Pointers as function return(return reference, pass by value) " << std::endl;
    u = 2;
    w = 3;
    int *z = add_2(u, w); // The address of u and w  variables in main() is copied to u and w arguments of add()
    std::cout << "memory address of u and w in main() u = " << &u << " : w = " << &w << std::endl;
    std::cout << "(dereferenced) z = " << *z << std::endl;
    std::cout << "value of z in main() = " << z << std::endl;
    std::cout << std::endl;
    draw_line();

    return 0;
}
