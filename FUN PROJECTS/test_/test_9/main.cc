#include <iostream>

int main()
{
    int age = 25;
    std::cout << age << std::endl;
    std::cout << &age << std::endl;
    int *age_ptr = &age;
    std::cout << age_ptr << std::endl;

    *age_ptr = 40;
    std::cout << age << std::endl;

    std::string names[2][3] = {
        {"peter", "Corn", "ya"},
        {"Bio", "Temi", "ish"}};
    // std::cout << names[0][0] << std::endl;

    for (int i = 0; i < std::size(names); i++)
    {
        for (int j = 0; j < std::size(names[0]); j++)
        {
            std::cout << names[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    // String optimizations
    char letter = 'A';
    std::string word_1 = "Hi people";
    char word_2[] = {"Hello Everyone"};              // Can simply use the string literal, without {}
    const char *word_3 = {"Hello wonderful people"}; // Array decayed into a char pointer. also works without {}
    char word_4[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'}; // Char array
    std::cout << letter << " (" << sizeof(letter) << " byte.)" << std::endl;
    std::cout << word_1 << " (" << sizeof(word_1) << " bytes.)" << std::endl;
    std::cout << word_2 << " (" << sizeof(word_2) << " bytes.)" << std::endl;
    std::cout << word_3 << " (" << sizeof(word_3) << " bytes.)" << std::endl;
    std::cout << word_3 << " (" << sizeof(*word_3) << " bytes.)" << std::endl; // Still don't know why this is 1 byte
    std::cout << word_4 << " (" << sizeof(word_4) << " bytes.)" << std::endl;

    word_1 = "Hello";
    // word_2 = "World"; // Arrays can't be reassigned
    word_3 = "Bye"; // Decayed pointer can be reassigned
    std::cout << word_3 << " (" << sizeof(word_3) << " bytes.)" << std::endl;

    /* The size of a pointer depends on the system architechture. on my 64 bits system, the size of a pointer
    is 8 bytes. Hence, word_3 is 8 bytes. this is drastically more memory efficient */

    return 0;
}