#include <iostream>
#include <vector>

void print(std::vector<int> &vec)
{
    std::cout << "[";
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i];
        if (i < vec.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
    std::cout << std::endl;
}

void test(int number)
{
    std::vector<int> divisible_by_3;
    std::vector<int> divisible_by_5;
    std::vector<int> divisible_by_3_and_5;
    std::vector<int> not_divisible;

    static int count, count_1, count_2, count_3;
    
    for (int i = 1; i <= number; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            std::cout << i << " = FIZZBUZZ" << std::endl;
            divisible_by_3_and_5.push_back(i);
            count++;
        }
        else if (i % 3 == 0)
        {
            std::cout << i << " = FIZZ" << std::endl;
            divisible_by_3.push_back(i);
            count_1++;
        }
        else if (i % 5 == 0)
        {
            std::cout << i << " = BUZZ" << std::endl;
            divisible_by_5.push_back(i);
            count_2++;
        }
        else
        {
            std::cout << i << std::endl;
            not_divisible.push_back(i);
            count_3++;
        }
    }
    std::cout << "divisible by 3 and 5 are " << count << " in total = ";
    print(divisible_by_3_and_5);

    std::cout << "divisible by 3 are " << count_1 << " in total = ";
    print(divisible_by_3);

    std::cout << "divisible by 5 are " << count_2 << " in total = ";
    print(divisible_by_5);

    std::cout << "not divisible are " << count_3 << " in total = ";
    print(not_divisible);
}

int main()
{
    int number = 100;
    test(number);
}