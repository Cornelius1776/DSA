#include <iostream> 
#include <vector>

// Returns the index of the two elements that sum up to the target 
std::vector<int> two_sum (std::vector<int> &arr, int target) 
{
    for (int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr.size(); j++) 
        {
            if (arr[i] + arr[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {};
}

void print(std::vector<int> &arr) 
{
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void print_result(std::vector<int> &vec, int target) 
{
    if (!vec.empty())
    {
        std::cout << "Found at indices " << vec[0] << " and " << vec[1] << std::endl;
    }
    else
    {
        std::cout << "No two sum solution found." << std::endl;
    }
}

int main() 
{   
    std::vector<int> numbers = {4, 2, 6, 8, 1, 5};
    print(numbers);
    int target = 11;
    std::vector<int> indices = two_sum(numbers, target);
    print_result(indices, target);

    return 0;
}