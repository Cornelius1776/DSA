#include "linked_list.h"

int main()
{
    Node queue;

    std::cout << std::boolalpha << queue.is_empty() << std::endl;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.display();
    std::cout << queue.check_front() << std::endl;
    std::cout << std::boolalpha << queue.is_empty() << std::endl;
    queue.dequeue();
    queue.dequeue();
    queue.display();
    std::cout << queue.check_front() << std::endl;
    return 0;
}