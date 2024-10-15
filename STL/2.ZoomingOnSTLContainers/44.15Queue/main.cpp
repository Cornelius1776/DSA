#include <iostream>
#include <queue>
#include <list>
#include <deque>

/* The queue container is built to function like the queue data structure FIFO(first in, first out)
 */

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

template <typename T, typename Container = std::deque<T>>
void print_queue(std::queue<T, Container> queue)
{

    std::cout << " queue of items : [";
    while (!queue.empty())
    {
        T item = queue.front();
        std::cout << " " << item;
        queue.pop();
    }
    std::cout << "]" << std::endl;
}

template <typename T, typename Container = std::deque<T>>
void clear_queue(std::queue<T, Container> &queue)
{
    std::cout << " Clearing queue of size : " << queue.size() << std::endl;

    while (!queue.empty())
    {
        queue.pop();
    }
}

int main()
{

    // Code1 : Creating  pushing and accessing
    std::cout << "Creating pushing and accessing : " << std::endl;
    std::queue<int> numbers_1;

    std::cout << " numbers_1 : ";
    print_queue(numbers_1);

    numbers_1.push(10);
    numbers_1.push(20);
    numbers_1.push(30);

    std::cout << " numbers_1 : ";
    print_queue(numbers_1);

    numbers_1.push(40);
    numbers_1.push(50);

    std::cout << " numbers_1 : ";
    print_queue(numbers_1);

    // Acess
    std::cout << " numbers_1.front() :  " << numbers_1.front() << std::endl;
    std::cout << " numbers_1.back() : " << numbers_1.back() << std::endl;

    // Code2 : Modify through top : this is because front and back return  a reference
    std::cout << std::endl;
    std::cout << "modify top element through front and back :" << std::endl;

    std::cout << " numbers_1 (before modification) : ";
    print_queue(numbers_1);

    numbers_1.front() = 500;
    numbers_1.back() = 600;

    std::cout << " numbers_1 (after modification) : ";
    print_queue(numbers_1);

    // Code3 : poping
    std::cout << std::endl;
    std::cout << "poping data : " << std::endl;

    std::cout << " numbers_1 : ";
    print_queue(numbers_1);

    numbers_1.pop();

    std::cout << " numbers_1 : ";
    print_queue(numbers_1);

    numbers_1.pop();

    std::cout << " numbers_1 : ";
    print_queue(numbers_1);

    // Code4 : Clearing a queue
    std::cout << std::endl;
    std::cout << "clearing a queue : " << std::endl;

    std::cout << " queue initial size : " << numbers_1.size() << std::endl;

    std::cout << " numbers_1 (before) : ";
    print_queue(numbers_1);

    clear_queue(numbers_1);

    std::cout << " queue final size : " << numbers_1.size() << std::endl;
    std::cout << " numbers_1(after) : ";
    print_queue(numbers_1);

    // Code5 : Queue of user defined types
    std::cout << std::endl;
    std::cout << "queue of user defined type :" << std::endl;

    std::queue<Book> books;

    books.push(Book(1921, "The Art of War"));
    books.push(Book(2000, "Social Media Marketing"));
    books.push(Book(2020, "How the Pandemic Changed the World"));

    std::cout << " books : ";
    print_queue(books);
    std::cout << " books size : " << books.size() << std::endl;
    std::cout << " front book : " << books.front() << std::endl;
    std::cout << " back book : " << books.back() << std::endl;

    // Code6 Specify underlying container
    std::cout << std::endl;
    std::cout << "custom underlying sequence container : " << std::endl;

    std::queue<int, std::list<int>> numbers_3;
    std::queue<int, std::deque<int>> numbers_4;

    numbers_3.push(3);
    numbers_3.push(4);

    numbers_4.push(5);
    numbers_4.push(6);

    std::cout << " numbers_3 : ";
    print_queue(numbers_3);

    std::cout << " numbers_4 : ";
    print_queue(numbers_4);

    return 0;
}