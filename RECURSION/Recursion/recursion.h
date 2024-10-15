#ifndef RECURSION_H
#define RECURSION_H
typedef long long ll;
#include <iostream>
#include <vector>

/* Recursion is the process of a function invoking it self until a stopping condition is met.*/

// Recursion with strings
std::string reverse_string(std::string word)
{
    // base condition
    if (word.length() == 0) // or word == ""
    {
        return "";
    }
    // recursion that reverses the string
    return reverse_string(word.substr(1)) + word.at(0);
}

// in the case where a word is a palindrome(a word whose pronounciation remains the same when spelt
// backward e.g non, nun, racecar, mum)
bool is_palindrome(std::string word)
{
    if (word.length() <= 1) // word == o or word == 1
    {
        return true;
    }
    else
    {
        if (word[0] != word[word.length() - 1])
        {
            return false;
        }
        else
        {
            return is_palindrome(word.substr(1, word.length() - 2));
        }
    }
}

// Recursion with numbers
void decimal_to_binary(int decimal)
{
    if (decimal == 0)
    {
        return;
    }
    else
    {
        decimal_to_binary(decimal / 2);
        int result = decimal % 2;
        std::cout << result;
    }
}

// Sum of natural numbers
int sum(int number)
{
    if (number <= 1)
    {
        return number;
    }

    return number + sum(number - 1);
}

// Fibonacci sequence(unoptimized)
ll fib(int num)
{
    if (num == 0 || num == 1)
    {
        return num;
    }

    return fib(num - 1) + fib(num - 2);
}

// Generating Subsets
/*  generate all subsets of a set of n elements. For example, the subsets of{1, 2, 3}
are ,{1},{2},{3},{1, 2},{1, 3},{2, 3}, and {1, 2, 3}. */

// Syntax .1
std::vector<int> subset;
void search(int num) //
{
    int n = 3; // number of elements in the set
    if (num == n + 1)
    {
        // process subset
        std::cout << "{";
        for (int i = 0; i < subset.size(); i++)
        {
            if (i > 0)
            {
                std::cout << ", ";
            }
            std::cout << subset[i];
        }
        std::cout << "}\n";
        return;
    }
    else
    {
        // add element at the index to the subset
        subset.push_back(num);
        search(num + 1);
        subset.pop_back();
        // remove element at the index from the subset
        search(num + 1);
    }
}

// Syntax .2
void subsets(const std::vector<int> &set, std::vector<int> &subset, int index)
{
    if (index == set.size())
    {
        // Print the subset
        std::cout << "{";
        for (int i = 0; i < subset.size(); i++)
        {
            if (i > 0)
            {
                std::cout << ", ";
            }
            std::cout << subset[i];
        }
        std::cout << "}\n";
        return;
    }

    // add current element to the subset
    subset.push_back(set[index]);
    subsets(set, subset, index + 1);

    // remove current element from the subset
    subset.pop_back();
    subsets(set, subset, index + 1);
}

/* generate all the permutations of a set of n elements. For example, the permutations
of {1, 2, 3} are (1, 2, 3), (1, 3, 2), (2, 1, 3), (2, 3, 1), (3, 1, 2), and (3, 2, 1) */
void permutate(const std::vector<int> &set, std::vector<int> &permutation, std::vector<bool> &used)
{
    if (permutation.size() == set.size())
    {
        // Print the permutation
        std::cout << "(";
        for (int i = 0; i < permutation.size(); i++)
        {
            if (i > 0)
            {
                std::cout << ", ";
            }
            std::cout << permutation[i];
        }
        std::cout << ")\n";
        return;
    }

    for (int i = 0; i < set.size(); i++)
    {
        if (!used[i])
        {
            used[i] = true;
            permutation.push_back(set[i]);
            permutate(set, permutation, used);
            permutation.pop_back();
            used[i] = false;
        }
    }
}

/* Using recursion through bactracking, calculate number of ways n queens can be
placed on an n * n chessboard such that the queens do not kill each other.
Called the N-Queens problem.*/
bool is_safe(const std::vector<int> &board, int row, int col)
{
    // Check if placing a queen at (row, col) is safe
    for (int i = 0; i < row; i++)
    {
        // Check if there is a queen in the same column or diagonals
        if (board[i] == col || board[i] - col == i - row || board[i] - col == row - i)
        {
            return false;
        }
    }
    return true;
}

void solve_NQueens(int n, int row, std::vector<int> &board, int &count)
{
    if (row == n)
    {
        // All queens have been placed successfully
        count++;
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (is_safe(board, row, col))
        {
            // Place the queen at (row, col)
            board[row] = col;
            // Recurse for the next row
            solve_NQueens(n, row + 1, board, count);
        }
    }
}

int total_NQueens(int n)
{
    std::vector<int> board(n);
    int count = 0;
    solve_NQueens(n, 0, board, count);
    return count;
}

#endif // !RECURSION_H