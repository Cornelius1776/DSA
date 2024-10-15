#include <iostream>
#include <cstdlib>
#include <ctime>

std::string random_password()
{
    srand(time(nullptr));

    // Generate random length between 7 and 10
    int length = rand() % 4 + 7;

    // Generate random password
    std::string password;
    for (int i = 0; i < length; i++)
    {

        // ascii Characters from 33 to 126
        char random_characters = rand() % 94 + 33;
        password.push_back(random_characters);
    }
    return password;
}

void generate()
{
    std::cout << "Password is " << random_password() << std::endl;
}

int main()
{
    generate();

    return 0;
}