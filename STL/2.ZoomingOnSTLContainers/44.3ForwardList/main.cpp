#include <iostream>
#include <forward_list>
#include <algorithm>

/* Forward_list also called singly linked list. because we can only move forward but we can't
traverse back like a doubly-linked list(called List isn STL). */

template <typename T>
void print_collection(const T &container)
{

    auto element = container.begin();

    std::cout << " Forward_List contains [";
    while (element != container.end())
    {
        std::cout << " " << *element;
        ++element;
    }
    std::cout << "]" << std::endl;
}

int main()
{

    std::forward_list<int> numbers = {100, 2, 3, 4, 5};
    print_collection(numbers);

    // Code1 : Element access
    std::cout << " front element : " << numbers.front() << std::endl;

    // Modifiers

    std::cout << "---------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "modifiers : " << std::endl;

    // Clear
    std::cout << std::endl;
    std::cout << "clear :" << std::endl;
    print_collection(numbers);

    numbers.clear();

    print_collection(numbers);
    std::cout << std::boolalpha;

    // Insert after
    std::cout << std::endl;
    std::cout << "insert_after : " << std::endl;

    numbers = {11, 12, 13, 14, 15};
    print_collection(numbers);

    numbers.insert_after(numbers.begin(), 10);
    print_collection(numbers);

    auto insert_element = numbers.before_begin();
    numbers.insert_after(insert_element, 300);

    print_collection(numbers);

    // Emplace after : create object in place after an iterator
    std::cout << std::endl;
    std::cout << "emplace_after : " << std::endl;

    print_collection(numbers);

    insert_element = numbers.before_begin();

    numbers.emplace_after(insert_element, 444);

    print_collection(numbers);

    // Erase_after
    std::cout << std::endl;
    std::cout << "erase_after : " << std::endl;

    print_collection(numbers);

    auto erase_element = std::find(numbers.begin(), numbers.end(), 13);

    if (erase_element != numbers.end())
    {
        std::cout << " Found 13 !" << std::endl;
    }
    else
    {
        std::cout << " Couldn't find 13 !" << std::endl;
    }

    numbers.erase_after(erase_element); // Erase 14, because it comes after 13 in the list
    print_collection(numbers);

    // pop_front
    std::cout << std::endl;
    std::cout << "pop_front : " << std::endl;

    print_collection(numbers);

    numbers.pop_front();

    print_collection(numbers);

    // resize : up or down
    std::cout << std::endl;
    std::cout << "resize : " << std::endl;

    print_collection(numbers);

    numbers.resize(10); // resize up will add space for more elements

    print_collection(numbers);

    numbers.resize(3); // When you resize down, the elements are lost for good.
                       // if you resize up again,you won't get them back.

    print_collection(numbers);

    numbers.resize(10);

    print_collection(numbers);

    // swap
    std::cout << std::endl;
    std::cout << "swap : " << std::endl;

    std::forward_list<int> other_numbers{200, 400, 600};

    std::cout << " numbers : ";
    print_collection(numbers);

    std::cout << " other_numbers :";
    print_collection(other_numbers);

    numbers.swap(other_numbers);

    std::cout << " numbers : ";
    print_collection(numbers);

    std::cout << " other_numbers :";
    print_collection(other_numbers);

    // Other operations
    std::cout << std::endl;
    std::cout << "merge : " << std::endl;

    // merge
    std::forward_list<int> numbers_1{1, 5, 6};
    std::forward_list<int> numbers_2{9, 2, 4};

    std::cout << " numbers_1 : ";
    print_collection(numbers_1);
    std::cout << " numbers_2 : ";
    print_collection(numbers_2);

    numbers_1.merge(numbers_2);

    std::cout << " numbers_1 : ";
    print_collection(numbers_1);

    std::cout << " numbers_2 : ";
    print_collection(numbers_2);

    // Can also be sorted before merging
    numbers_1.sort();
    numbers_2.sort();
    numbers_1.merge(numbers_2);
    print_collection(numbers_1);

    // splice_after : moving a range of elements from one container to another
    std::cout << std::endl;
    std::cout << "splice_after : " << std::endl;

    numbers_1 = {1, 5, 6, 8, 3};
    numbers_2 = {9, 2, 4, 7, 13, 11, 17};

    std::cout << " numbers_1 : ";
    print_collection(numbers_1);

    std::cout << " numbers_2 : ";
    print_collection(numbers_2);

    numbers_1.splice_after(numbers_1.before_begin(), numbers_2);

    std::cout << " numbers_1 : ";
    print_collection(numbers_1);

    std::cout << " numbers_2 : ";
    print_collection(numbers_2);

    // Remove
    std::cout << std::endl;
    std::cout << "remove : " << std::endl;

    numbers = {1, 100, 2, 3, 10, 1, 11, -1, 12};

    print_collection(numbers);

    numbers.remove(1); // remove both elements equal to 1

    print_collection(numbers);

    // Remove(based on a condition)
    numbers.remove_if([](int n)
                      { return n % 2 != 0; }); // remove odd numbers

    print_collection(numbers);

    // reverse
    std::cout << std::endl;
    std::cout << "reverse : " << std::endl;

    numbers = {1, 100, 2, 3, 10, 1, 11, -1, 12};

    print_collection(numbers);

    numbers.reverse();

    print_collection(numbers);

    // Unique : Removes duplicates from the container
    // Removes only adjacent(side by side) duplicates e.g 100, 11, but will not remove 1 and 2
    std::cout << std::endl;
    std::cout << "unique : " << std::endl;

    numbers = {1, 100, 100, 2, 3, 10, 1, 11, 11, -1, 12, 2, 10, 1};

    print_collection(numbers);

    numbers.unique();

    print_collection(numbers);

    /* An algorithm to remove all the duplicates will be to sort the elements first and then
    use unique(), this way sorting will place all the duplicates beside each other. */

    // Sort
    std::cout << std::endl;
    std::cout << "sort : " << std::endl;

    print_collection(numbers);

    numbers.sort();

    print_collection(numbers);

    // sorted then duplicates can be removed efficiently.
    numbers.unique();

    print_collection(numbers);

    return 0;
}