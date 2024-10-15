#include <iostream>

/* A palindrome is a word whose pronounciation remains the same when spelt
backward e.g non, nun, racecar, mum, dad etc.*/
bool is_palindrome(std::string word)
{
    if (word.length() <= 1) // Base case
    {
        return true;
    }

    if (word[0] != word[word.length() - 1])
    {
        return false;
    }
    else
    {
        return is_palindrome(word.substr(1, word.length() - 2));
    }
}

// Print palindrome
void print_palindrome(std::string word)
{
    if (is_palindrome(word))
        std::cout << word << " is a palindrome \n";
    else
        std::cout << word << " is not a palindrome \n";
    std::cout << std::endl;
}

int main()
{
    std::string word = "money";
    print_palindrome(word);

    word = "racecar";
    print_palindrome(word);

    word = "person";
    print_palindrome(word);

    word = "a";
    print_palindrome(word);

    word = "mum";
    print_palindrome(word);

    word = "dad";
    print_palindrome(word);

    std::cout << std::boolalpha << is_palindrome(word) << std::endl;

    return 0;
}