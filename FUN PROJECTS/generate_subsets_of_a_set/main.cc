#include <iostream>
#include <vector>

// Syntax .1
std::vector<int> set;
void sub_set(int num)
{
    int n = 5; // elements of the set are btw num and n. if num is greater than n, there will be an error
    if (num == n + 1)
    {
        // process subset
        std::cout << "{";
        for (int i = 0; i < set.size(); i++)
        {
            if (i > 0)
            {
                std::cout << ", ";
            }
            std::cout << set[i];
        }
        std::cout << "}\n";
        return;
    }
    else
    {
        // add element at the index to the subset
        set.push_back(num);
        sub_set(num + 1);
        set.pop_back();
        // remove element at the index from the subset
        sub_set(num + 1);
    }
}

// Syntax .2 For more flexibility
void subsets(const std::vector<int> &set, std::vector<int> &sub_set, int index)
{
    if (index == set.size())
    {
        // Print the subset
        std::cout << "{";
        for (int i = 0; i < sub_set.size(); i++)
        {
            if (i > 0)
            {
                std::cout << ", ";
            }
            std::cout << sub_set[i];
        }
        std::cout << "}\n";
        return;
    }

    // add current element to the subset
    sub_set.push_back(set[index]);
    subsets(set, sub_set, index + 1);

    // remove current element from the subset
    sub_set.pop_back();
    subsets(set, sub_set, index + 1);
}

int main()
{
    std::cout << "Syntax .1\n";
    sub_set(0); // Set will be 0, 1, 2, 3, 4, 5 same output as syntax 2

    std::cout << "Syntax .2\n";
    std::vector<int> set = {0, 1, 2, 3, 4, 5};
    std::vector<int> subset;
    subsets(set, subset, 0); // Syntax 2 makes it flexible to specify the starting index
    std::cout << std::endl;

    return 0;
}