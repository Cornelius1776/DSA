#include <iostream>
#include <string.h> // for getline()

// change the value of a variable using a function
void greet(std::string *name)
{
    (*name) = "Ryan";
}

void add(int &x, int &y)
{
    int z = x + y;
    std::cout << z << std::endl;
}

int main()
{
    std::string name = "Cornelius";
    std::cout << name << std::endl;
    greet(&name);
    std::cout << name << std::endl;

    int rates[] = {1, 3, 2, 6, 4, 9, 7, 31};
    int n = sizeof(rates) / sizeof(*rates);
    add(rates[2], *rates);
    add(1 [rates], 5 [rates]);

    return 0;
}