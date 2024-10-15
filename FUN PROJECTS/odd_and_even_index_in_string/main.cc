#include <iostream>

// Find characters of the string with an odd or even index
void odd_or_even(std::string word, int n)
{
    std::string even, odd;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            even += word[i]; // characters at even indices
        }
        else
        {
            odd += word[i]; // Characters at odd indices
        }
    }
    std::cout << "Odds = " << odd << ": Even = " << even << std::endl;
}

int main()
{
    std::string word = "cat";
    odd_or_even(word, 3);

    word = "caterpillar";
    odd_or_even(word, 11);

    word = "money";
    odd_or_even(word, 5);

    std::cout << word[0] << std::endl;
    std::cout << word[1] << std::endl;
    std::cout << word[2] << std::endl;

    return 0;
}