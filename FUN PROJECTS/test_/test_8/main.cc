#include <iostream>

class Greet
{
    std::string _message;

public:
    // Constructor
    Greet() = default;
    Greet(std::string message)
    {
        _message = message;
    }

    // Setters
    std::string set_message(std::string message)
    {
        _message = message;
        return message;
    }

    // Getters
    void get_message()
    {
        std::cout << _message << std::endl;
    }
};

int main()
{
    int age = 25;
    std::cout << "age = " << age << std::endl;

    std::string a = std::to_string(3) + std::to_string(4);
    std::string b = std::to_string(3) + ", " + std::to_string(4);
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    Greet greet("Hello World");
    Greet greet_1;
    greet_1.set_message("Hello People");
    greet.get_message();
    greet_1.get_message();

    return 0;
}