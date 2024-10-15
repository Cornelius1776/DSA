#include "linked_list.h"

int main()
{
    Node *head = nullptr; // linked-list is empty

    insert(32, 0); // 32
    insert(42, 0); // 42, 32
    insert(46, 1); // 42, 46, 32
    insert(47, 1); // 42, 47, 46, 32
    insert(75, 0); // 75, 42, 47, 46, 32
    insert(79, 3); // 75, 42, 47, 79, 46, 32
    output();

    return 0;
}