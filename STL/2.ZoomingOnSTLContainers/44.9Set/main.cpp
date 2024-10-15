#include <iostream>
#include <functional>
#include <set>

/* Set is an associative container the stores unique values in a sorted order, and
internally implemented using Red-black tree. */

class Book
{
    friend std::ostream &operator<<(std::ostream &out, const Book &operand);

public:
    Book(int year, std::string title)
        : m_year(year), m_title(title)
    {
    }
    bool operator<(const Book &right_operand) const
    {
        return this->m_year < right_operand.m_year;
    }

private:
    int m_year;
    std::string m_title;
};
std::ostream &operator<<(std::ostream &out, const Book &operand)
{
    out << "Book [" << operand.m_year << ", " << operand.m_title << "]";
    return out;
}

template <typename T>
void print_collection(const T &collection)
{

    auto it = collection.begin();

    std::cout << " Collection [";

    while (it != collection.end())
    {
        std::cout << " " << *it;
        ++it;
    }
    std::cout << "]" << std::endl;
}

// Comparator functor
class IntComparator
{
public:
    bool operator()(int left, int right) const
    {
        return (left < right);
    }
};

// Comparator function pointer
bool compare_ints(int left, int right)
{
    return (left < right);
}

int main()
{

    // Code1 : Building sets
    std::set<int> numbers = {11, 16, 2, 912, 15, 6, 15, 2}; // sorted by the compiler
    std::cout << std::endl;
    std::cout << "building sets (Need < operator for ordering) : " << std::endl;
    print_collection(numbers);

    // Set of custom types
    std::set<Book> books = {Book(2000, "Cooking Food"),
                            Book(1930, "Building Computers"),
                            Book(1995, "Farming for Beginners")};

    print_collection(books);
    std::cout << "---------------------" << std::endl;

    // Code2 : Iterators : forward and back, and constant

    std::cout << std::endl;
    std::cout << "iterators : " << std::endl;

    auto it = numbers.begin();
    std::cout << " set of numbers : [";
    while (it != numbers.end())
    {
        std::cout << " " << *it;
        ++it;
    }
    std::cout << "]" << std::endl;

    auto it_back = numbers.rbegin();
    std::cout << " set of numbers (reverse) : [";
    while (it_back != numbers.rend())
    {
        std::cout << " " << *it_back;
        ++it_back;
    }
    std::cout << "]" << std::endl;

    auto it_back_books = books.rbegin();
    std::cout << " set of books (reverse) : [";
    while (it_back_books != books.rend())
    {
        std::cout << " " << *it_back_books;
        ++it_back_books;
    }
    std::cout << "]" << std::endl;

    // Code3 : Capacity :
    std::cout << "---------------------" << std::endl;

    std::cout << std::endl;
    std::cout << "capacity : " << std::endl;
    std::cout << " numbers : ";
    print_collection(numbers);
    std::cout << " set max_size : " << numbers.max_size() << std::endl;
    std::cout << " set is empty : " << numbers.empty() << std::endl;
    std::cout << " set size : " << numbers.size() << std::endl;

    std::cout << "---------------------" << std::endl;
    // Modifiers

    // Clear
    std::cout << std::endl;
    std::cout << "clear :" << std::endl;
    print_collection(numbers);

    numbers.clear();

    print_collection(numbers);
    std::cout << std::boolalpha;
    std::cout << "numbers is empty : " << numbers.empty() << std::endl;

    // Insert  : returns an std::pair object containing result about the insert operation.
    std::cout << std::endl;
    std::cout << "Insert : " << std::endl;
    numbers = {11, 12, 13, 14, 15};
    print_collection(numbers);

    // Insert 14 : won't insert because std::set doesn't allow duplicates.
    // Will just do nothing and won't give an error though.
    numbers.insert(14);

    std::cout << " After insert 14 : ";
    print_collection(numbers);

    // Can capture the insert result through a returned std::pair object.

    std::cout << "-------" << std::endl;

    // auto result = numbers.insert(14);
    auto result = numbers.insert(20);

    std::cout << " first : " << *result.first << std::endl;
    std::cout << " second : " << result.second << std::endl;

    std::cout << "------" << std::endl;
    if (result.second)
    {
        std::cout << " Insertion of " << *result.first << " successful" << std::endl;
    }
    else
    {
        std::cout << " Couldn't insert " << *result.first << " in the set. It's a duplicate!" << std::endl;
    }
    print_collection(numbers);

    // Emplace
    std::cout << std::endl;
    std::cout << "emplace : " << std::endl;

    print_collection(numbers);

    // auto result_emplace = numbers.emplace(421); // Succeeds
    auto result_emplace = numbers.emplace(13); // Fails

    if (result_emplace.second)
    {
        std::cout << " Emplace of " << *result_emplace.first << " successful" << std::endl;
    }
    else
    {
        std::cout << " Emplace of " << *result_emplace.first << " FAILED" << std::endl;
    }

    print_collection(numbers);

    // Erase
    std::cout << std::endl;
    std::cout << "erase : " << std::endl;

    print_collection(numbers);

    auto it_erase = std::find(numbers.begin(), numbers.end(), 13);

    if (it_erase != numbers.end())
    {
        std::cout << "Found 13 !" << std::endl;
    }
    else
    {
        std::cout << "Couldn't find 13 !" << std::endl;
    }

    // Erase the 13
    if (it_erase != numbers.end())
        numbers.erase(it_erase);

    print_collection(numbers);

    // swap
    std::cout << std::endl;
    std::cout << "swap : " << std::endl;

    std::set<int> other_numbers = {200, 400, 600};

    std::cout << " numbers : ";
    print_collection(numbers);
    std::cout << " other_numbers :";
    print_collection(other_numbers);

    numbers.swap(other_numbers);

    std::cout << " numbers : ";
    print_collection(numbers);
    std::cout << " other_numbers :";
    print_collection(other_numbers);

    // Change comparator using built-in functor
    std::cout << std::endl;
    std::cout << "change comparator : " << std::endl;

    std::set<int> numbers_1 = {11, 16, 2, 9, 12, 15, 6, 15, 2}; // Ascending order by default.

    // std::less sorts the set in ascending order
    std::set<int, std::less<int>> numbers_2 = {11, 16, 2, 9, 12, 15, 6, 15, 2};

    // std::greater sorts the set in descending order
    std::set<int, std::greater<int>> numbers_3 = {11, 16, 2, 9, 12, 15, 6, 15, 2};

    // Use Custom function
    std::set<int, IntComparator> numbers_4 = {11, 16, 2, 9, 12, 15, 6, 15, 2};

    // Function pointer

    std::set<int, bool (*)(int, int)> numbers_5(compare_ints);
    numbers_5.insert({11, 16, 2, 9, 12, 15, 6, 15, 2});

    std::set<int, std::function<bool(int, int)>> numbers_6([](int left, int right)
                                                           { return left > right; });
    numbers_6.insert({11, 16, 2, 9, 12, 15, 6, 15, 2}); // Lambda function

    std::cout << " numbers_2 :[ ";
    for (const auto &element : numbers_6)
    {
        std::cout << " " << element;
    }
    std::cout << "]" << std::endl;

    return 0;
}