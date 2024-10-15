#include "recursion.h"

int main()
{
    std::cout << "Reverse String" << std::endl;
    std::cout << reverse_string("Hello") << std::endl;

    std::cout << "Check Palindrome\n";
    std::string word = "dad";
    /* std::string word;
    std::cout << "Which word do you want to check?" << std::endl;
    std::cin >> word; */
    if (is_palindrome(word))
    {
        std::cout << word << " is a palindrome.\n";
    }
    else
    {
        std::cout << word << " is not a palindrome.\n";
    }
    std::cout << std::endl;

    std::cout << "Find binary\n";
    decimal_to_binary(245);
    std::cout << std::endl;

    std::cout << "Sum of natural numbers\n";
    std::cout << sum(5) << std::endl;  // 1 + 2 + 3 + 4 + 5
    std::cout << sum(10) << std::endl; // 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10
    std::cout << std::endl;

    std::cout << "Unoptimized Fibonacci\n";
    int x = 15;
    std::cout << "The number at fibonacci sequence " << x << " is " << fib(x) << "\n";

    int my_arr[] = {2, 14, 3, 5, 6, 13, 15};
    for (long long &&i : my_arr)
    {
        std::cout << "The number at fibonacci sequence " << i << " is " << fib(i) << "\n";
    }
    std::cout << std::endl;

    std::cout << "Generate subsets of a set\n";
    std::cout << "Syntax .1\n";
    search(2);

    std::cout << "Syntax .2\n";
    std::vector<int> set = {1, 2, 3};
    std::vector<int> subset;
    subsets(set, subset, 0);
    std::cout << std::endl;

    std::cout << "Generate the permutations of a set\n";
    set = {1, 2, 3, 4};
    std::vector<int> permutation;
    std::vector<bool> used(set.size(), false);
    permutate(set, permutation, used);
    std::cout << std::endl;

    std::cout << "N-Queens solution\n";
    int n = 7; // Chessboard size and number of queens
    int totalWays = total_NQueens(n);
    std::cout << "Total number of ways to safely place " << n << " queens on a "
              << n << "x" << n << " chessboard: " << totalWays << std::endl;

    // signed and unsigned experiments
    /* a signed number −x equals an unsigned number 2^n − x. e.g signed number a = −54 equals
    the unsigned number b = 2^32 − 54*/
    int a = -54;
    unsigned int b = a;
    if (a == b)
    {
        std::cout << a << " is equal to " << b << std::endl;
    }
    else
    {
        std::cout << a << " is not equal to " << b << std::endl;
    }

    /* Initially, the value of c is 2147483647 or 2^31 − 1. This is the largest value that can
    be stored in an int variable, so the next number after 2^31 − 1 is −2^31. */
    int c = 2147483647;
    std::cout << c << "\n"; // 2147483647
    c++;                    // exceeds the int upper limit 2^31 - 1 becomes -2^31
    std::cout << c << "\n"; // -2147483648

    unsigned int c_1 = 2147483647;
    std::cout << c_1 << "\n"; // 2147483647
    c_1++;                    // exceeds the int upper limit 2^31 - 1 becomes 0
    std::cout << c_1 << "\n"; // 2147483648 or 0

    return 0;
}