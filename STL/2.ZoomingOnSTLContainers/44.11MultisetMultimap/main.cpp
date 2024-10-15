#include <iostream>
#include <set> // multiset
#include <map> //multimap

/* A multimap is an associative container that store data as key/value pairs just like map, but
map, multimap keys are not unique */

/* A multiset allows duplicates, everything else is the same as a set.*/

class Book
{
    friend std::ostream &operator<<(std::ostream &out, const Book &operand);

public:
    Book() = default;
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
void print_multiset(const std::multiset<T> &m_set)
{

    auto it = m_set.begin();

    std::cout << "multiset of elements : [";
    while (it != m_set.end())
    {

        std::cout << " " << *it;
        ++it;
    }
    std::cout << "]" << std::endl;
}

template <typename T, typename K>
void print_multimap(const std::multimap<T, K> &m_map)
{

    auto it = m_map.begin();

    std::cout << "multimap of elements : [";
    while (it != m_map.end())
    {

        std::cout << " [" << it->first << "," << it->second << "]";
        ++it;
    }
    std::cout << "]" << std::endl;
}

int main()
{

    std::multiset<int> numbers = {1, 2, 1, 6, 2, 8, 3, 9, 4, 24, 6, 2};
    std::cout << "numbers : ";
    print_multiset(numbers);

    std::multiset<Book> books = {
        Book(1734, "Cooking Food"),
        Book(1930, "Building Computers"),
        Book(1734, "Farming for Beginners")};

    std::cout << "books : ";
    print_multiset(books);

    std::cout << "-----------------------------------------------------" << std::endl;

    std::cout << std::endl;
    std::cout << "multimap : " << std::endl;

    std::multimap<int, std::string> office_numbers = {
        std::make_pair(101, "Daniel Gray"),
        std::make_pair(102, "John Snow"),
        std::make_pair(103, "Jamie Lanister"),
        std::make_pair(102, "Van Gomir"),
        std::make_pair(101, "Kay Moris"),
        std::make_pair(102, "Zuba Loy"),
    };

    office_numbers.insert(std::make_pair(104, "John Doe"));

    std::cout << "office_numbers : ";
    print_multimap(office_numbers);

    std::multimap<int, Book> other_books = {
        std::make_pair(0, Book(1734, "Cooking Food")),
        std::make_pair(1, Book(1930, "Building Computers")),
        std::make_pair(1, Book(1995, "Farming for Beginners"))};

    std::cout << "other_books : ";
    print_multimap(other_books);
    std::cout << std::endl;

    std::multimap<char, int> my_multimap;
    my_multimap.insert(std::make_pair('x', 2));
    my_multimap.insert(std::make_pair('x', 1));
    my_multimap.insert(std::make_pair('x', 3));
    my_multimap.insert(std::make_pair('y', 4));
    my_multimap.insert(std::make_pair('y', 5));
    print_multimap(my_multimap);
    // auto contain = my_multimap.contains('x') this is a C++20 feature, I have C++17
    auto pair = my_multimap.find('x');
    std::cout << pair->first /* key */ << " " << pair->second /* value */ << std::endl;

    pair = my_multimap.find('y');
    std::cout << pair->first << " " << pair->second << std::endl;

    pair = my_multimap.find('z');
    std::cout << pair->first << " " << pair->second << std::endl;

    return 0;
}