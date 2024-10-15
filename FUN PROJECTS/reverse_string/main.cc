#include <iostream>

std::string reverse(std::string word)
{
    if (word.length() == 0)
    {
        return "";
    }
    return reverse(word.substr(1)) + word.at(0);
}

int main()
{
    std::string name = "Cornelius";
    std::cout << name << std::endl;

    std::string result = reverse(name);
    std::cout << result << std::endl;

    name = "Hello";
    result = reverse(name);
    std::cout << result << std::endl;

    return 0;
}