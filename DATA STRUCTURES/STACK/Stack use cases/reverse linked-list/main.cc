#include <iostream>
#include <stack> // from STL
class Node
{
    int data;
    Node *next;

public:
    void push(Node **head, int new_data)
    {

        Node *new_node = new Node();
        new_node->data = new_data;
        new_node->next = (*head);
        (*head) = new_node;
    }

    void reverse(Node *head)
    {
        if (head == nullptr)
        {
            return;
        }
        std::stack<Node *> my_stack;

        Node *temp = head;
        while (temp != nullptr)
        {
            my_stack.push(temp);
            temp = temp->next;
        }

        temp = my_stack.top();
        head = temp;
        my_stack.pop();

        while (!my_stack.empty())
        {
            temp->next = my_stack.top();
            my_stack.pop();
            temp = temp->next;
        }
        temp->next = nullptr;
    }

    void output(Node *head)
    {
        while (head)
        {
            std::cout << head->data << " ";
            head = head->next;
        }
    }
};

int main()
{
    Node *head = nullptr; // empty linked-list
    Node node;

    node.push(&head, 1);
    node.push(&head, 2);
    node.push(&head, 3);
    node.push(&head, 4);
    node.push(&head, 5);

    node.output(head);

    node.reverse(head);

    return 0;
}