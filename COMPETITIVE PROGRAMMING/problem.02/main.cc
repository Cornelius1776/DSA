#include <iostream>
#include <vector>
#include <unordered_map>

/* Given an array of integers nums and an integer target, return indices of the two numbers
such that they add up to target. */

class Two_sum
{
public:
    // The method
    std::vector<int> sum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> hash_table; // create an empty hash table to store each element and its index

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i]; // calculate the complement of the current number

            if (hash_table.find(complement) != hash_table.end())
            {
                // if the complement is already in the hash table
                // return the indices of the current number and its complement
                return {hash_table[complement], i};
            }

            hash_table[nums[i]] = i; // add the current number and its index to the hash table
        }

        return {}; // if no two elements add up to the target, return an empty vector
    }

    // print
    void print(std::vector<int> &nums, int &target)
    {
        Two_sum obj;
        std::vector<int> indices = obj.sum(nums, target);

        if (indices.size() == 2)
        {
            std::cout << "Indices: " << indices[0] << ", " << indices[1] << "\n";
            std::cout << "Elements: " << nums[indices[0]] << ", " << nums[indices[1]] << "\n";
            std::cout << std::endl;
        }
        else
        {
            std::cout << "No two elements add up to the target.\n";
            std::cout << std::endl;
        }
    }
};

int main()
{
    Two_sum obj;

    std::vector<int> nums = {2, 7, 11, 15, 3, 10, 4, 5};
    int target = 10;
    obj.print(nums, target);

    target = 3;
    obj.print(nums, target);

    target = 15;
    obj.print(nums, target);

    return 0;
}