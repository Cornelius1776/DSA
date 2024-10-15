#include <iostream>

// Call by value
std::string message(std::string name)
{
    std::cout << "The name is " << name << " and its memory address inside message() is " << &name << "\n";
    return "Hello " + name;
}

// Call by pointer
std::string message_1(std::string *name)
{
    std::cout << "The name is " << *name << " and its memory address inside message() is " << name << "\n";
    return "Hello " + *name;
}

// Call by reference
std::string message_1(std::string &name)
{
    std::cout << "The name is " << name << " and its memory address inside message() is " << &name << "\n";
    return "Hello " + name;
}

int main()
{
    std::string name = "Cornelius";

    std::cout << "Call by value" << std::endl;
    std::cout << message(name) << " and its memory address inside main() is " << &name << "\n";
    std::cout << std::endl;

    std::cout << "Call by pointer" << std::endl;
    std::cout << message_1(&name) << " and its memory address inside main() is " << &name << "\n";
    std::cout << std::endl;

    std::cout << "Call by reference" << std::endl;
    std::cout << message_1(name) << " and its memory address inside main() is " << &name << "\n";
    std::cout << std::endl;

    return 0;
}