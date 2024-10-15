#include <iostream>
#include <math.h>
#include <vector>

void print_vector(std::vector<int> &vec)
{
    std::cout << "The prime numbers are: ";
    for (auto &num : vec)
    {
        std::cout << num << " ";
    }
}

void find_prime(int num, std::vector<int> &prime_numbers)
{
    if (num <= 1)
    {
        std::cout << "1 is not a prime" << std::endl;
        return;
    }

    if (num <= 3)
    {
        std::cout << num << " is a prime number." << std::endl;
        prime_numbers.push_back(num);
        return;
    }

    if (num % 2 == 0 || num % 3 == 0)
    {
        std::cout << num << " is not a prime number." << std::endl;
        return;
    }

    for (int i = 5; i <= sqrt(num); i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            std::cout << num << " is not a prime number." << std::endl;
            return;
        }
    }
    std::cout << num << " is a prime number." << std::endl;
    prime_numbers.push_back(num);
}

int main()
{
    std::vector<int> prime_numbers;
    int number = 100;
    for (int i = 0; i <= number; i++)
    {
        find_prime(i, prime_numbers);
    }
    print_vector(prime_numbers);

    return 0;
}