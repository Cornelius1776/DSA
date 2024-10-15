#include "linked_list.h"

int main()
{
    Node node;

    node.push(3);
    node.output();
    node.push(4);
    node.output();
    node.push(5);
    node.output();
    node.push(6);
    node.output();
    node.show_top();
    node.pop();
    node.output();
    node.show_top();
    node.pop();
    node.output();
    node.show_top();
    node.pop();
    node.output();
    node.pop();
    node.output();
    std::cout << std::boolalpha << node.is_empty() << std::endl;
    node.push(125);
    std::cout << std::boolalpha << node.is_empty() << std::endl;
    node.output();

    // boolalpha helps to display true/false instead of 1/0

    return 0;
}