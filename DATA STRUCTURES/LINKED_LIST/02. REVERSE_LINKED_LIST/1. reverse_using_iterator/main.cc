#include "reverse.h"

int main()
{
    Node linked_list;
    int c = 5 < 2;
    std::cout << c << std::endl;
    std::cout << std::endl;

    Node *head = nullptr;
    head = linked_list.insert(head, 34);
    head = linked_list.insert(head, 43);
    head = linked_list.insert(head, 56);
    head = linked_list.insert(head, 67);
    head = linked_list.insert(head, 98);
    linked_list.output(head);
    head = linked_list.reverse(head);
    linked_list.output(head);

    return 0;
}