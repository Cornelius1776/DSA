#include <iostream>
// A maths problem called Collatz conjecture or simply 3n + 1
/* Consider a function that takes as input a positive integer n. If n is even, the algorithm
divides it by two, and if n is odd, the algorithm multiplies it by three and adds one. The
algorithm repeats this, n always ends in 1. For example, the sequence for n = 3 is as follows:
3 → 10 → 5 → 16 → 8 → 4 → 2 → 1 */

void collatz(size_t num)
{
    while (true) // or num != 1
    {
        std::cout << num;
        if (num != 1)
        {
            std::cout << " => ";
        }

        if (num == 1)
        {
            break;
        }
        if (num % 2 == 0)
        {
            num = num / 2;
        }
        else
        {
            num = num * 3 + 1;
        }
    }
    std::cout << std::endl;
}

int main()
{
    int a = 138367;
    collatz(a);
    a = 3;
    collatz(a);

    return 0;
}