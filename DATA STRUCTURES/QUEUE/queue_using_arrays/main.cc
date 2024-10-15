#include "array.h"

int main()
{
    Queue my_q;
    my_q.enqueue(1);
    my_q.enqueue(23);
    my_q.enqueue(14);
    my_q.enqueue(5);

    my_q.display();
    std::cout << "Element at the back is: " << my_q.back() << std::endl;
    std::cout << "Element at the front is: " << my_q.Front() << std::endl;
    std::cout << std::boolalpha << my_q.is_full() << std::endl;
    std::cout << std::boolalpha << my_q.is_empty() << std::endl;
    my_q.dequeue();
    my_q.dequeue();
    my_q.dequeue();
    my_q.display();
    my_q.dequeue();
    my_q.dequeue();
    my_q.dequeue();
    std::cout << my_q.Front() << std::endl;
    std::cout << std::boolalpha << my_q.is_full() << std::endl;
    std::cout << std::boolalpha << my_q.is_empty() << std::endl;

    /* The enqueue() \ rear = (rear + 1) % MAXSIZE;\ and dequeue() \front = (front + 1) % MAXSIZE;\ lines of
    code allows for circular array implementation pattern. what this means is that without
    these 2 modififcations, if for instance 5 elements are enqueue into the queue and 3 are
    dequeued, when another enqueue operation is performed, the space of the 3 dequeued elements
    will not be occupied, and this is not an efficient designed. So, adding those 2 lines of code
    in the functions make the elements to adjust as some are enqueud and dequeued  */

    return 0;
}