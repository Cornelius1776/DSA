#include <iostream>
#include <algorithm>
#include <vector>

int main()
{

    // int n = 23;
    std::vector<int> collection{14, 24, 72, 8, 98, 112};
    int target = 24;

    auto result = std::find(std::begin(collection), std::end(collection), target);

    if (result != std::end(collection))
    {
        std::cout << "collection contains: " << target << std::endl;
    }
    else
    {
        std::cout << "collection does not contain: " << target << std::endl;
    }

    std::cout << "------------" << std::endl;

    auto odd = [](int x)
    {
        if ((x % 2) != 0)
            return true;
        return false;
    };

    auto find_odd = std::find_if(std::begin(collection), std::end(collection), odd);

    if (find_odd != std::end(collection))
    {
        std::cout << "collection contains at least one odd number : " << *find_odd << std::endl;
    }
    else
    {
        std::cout << "collection does not contain any odd number" << std::endl;
    }

    return 0;
}