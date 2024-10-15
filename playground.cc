#include <iostream>
#include <algorithm>
#include <vector>

class Node
{
    int m_data;
    Node *m_next;

public:
    // Methods
    // Add elements into the linked list at the beginning
    void insert(Node **head, int data)
    {
        Node *temp = new Node();
        temp->m_data = data;
        temp->m_next = *head;
        *head = temp;
    }

    // check if linked list is empty
    bool is_empty(Node *head)
    {
        if (head == nullptr)
        {
            return true;
        }
        return false;
    }

    // Print out the linked list
    void print(Node *head)
    {
        if (is_empty(head))
        {
            std::cout << "The linked list is empty! ";
        }
        while (head != nullptr)
        {
            std::cout << head->m_data << " ";
            head = head->m_next;
        }

        std::cout << std::endl;
    }

    // Print using recursion
    void print_recurse(Node *head)
    {
        if (head != nullptr)
        {
            std::cout << head->m_data << ", ";
            print_recurse(head->m_next);
        }
        std::cout << std::endl;
    }

    // Search for elements in the linked list
    void search(Node *head, int target)
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            if (temp->m_data == target)
            {
                std::cout << target << " is found." << std::endl;
                return;
            }

            temp = temp->m_next;
        }
        std::cout << target << " not found." << std::endl;
    }

    // Sum of all element in the linked list
    void sum(Node *head)
    {
        Node *temp = head;
        int sum_total = 0;
        while (temp != nullptr)
        {
            sum_total += temp->m_data;
            temp = temp->m_next;
        }
        std::cout << "The sum of the linked list is " << sum_total << std::endl;
    }

    // Printing the vectors
    void print_vec(std::vector<int> &vec)
    {
        std::cout << "[";
        for (int i = 0; i < vec.size(); i++)
        {
            std::cout << vec[i];
            if (i < vec.size() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
        std::cout << std::endl;
    }

    // check odd or even in the linked list
    void odd_or_even(Node *head)
    {
        Node *temp = head;

        std::vector<int> odd;  // Hold elements that are odd numbers
        std::vector<int> even; // Hold elements that are even numbers
        while (temp != nullptr)
        {
            if (temp->m_data & 1)
            {
                std::cout << temp->m_data << " is an odd number" << std::endl;
                odd.push_back(temp->m_data);
            }
            else
            {
                std::cout << temp->m_data << " is an even number" << std::endl;
                even.push_back(temp->m_data);
            }
            temp = temp->m_next;
        }
        std::cout << "the odd numbers are ";
        print_vec(odd);

        std::cout << "the even numbers are ";
        print_vec(even);
    }

    // Find largest element in the linked list
    void largest(Node *head)
    {
        Node *temp = head;
        int max = temp->m_data;

        while (temp->m_next != nullptr)
        {
            if (temp->m_data > max)
            {
                max = temp->m_data;
            }
            temp = temp->m_next;
        }
        std::cout << "the largest element is " << max << std::endl;
    }
};

// binary search using void
void binary_search(int *arr, int n, int target)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid_point = right - (right - left) / 2;

        if (target > arr[mid_point])
        {
            left = mid_point + 1;
        }
        else if (target < arr[mid_point])
        {
            right = mid_point - 1;
        }
        else
        {
            std::cout << target << " is found at index " << mid_point << std::endl;
            return;
        }
    }

    std::cout << target << " not found" << std::endl;
}

// Using STL binary search
void stl_search(int arr[], int target, int n)
{
    int left = 0;
    int right = n;
    if (std::binary_search(arr + left, arr + right, target))
    {
        std::cout << target << " found!" << std::endl;
    }
    else
    {
        std::cout << target << " not found!" << std::endl;
    }
}

void sum(int *arr, int n)
{
    int my_sum = 0;
    for (int i = 0; i < n; i++)
    {
        my_sum += arr[i];
    }
    std::cout << "Array sum is " << my_sum << std::endl;
}

// Print arrays
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Node node;
    Node *head = nullptr;

    node.print(head);
    std::cout << std::boolalpha << node.is_empty(head) << std::endl;
    node.insert(&head, 23);
    node.insert(&head, 2);
    node.insert(&head, 45);
    node.insert(&head, 31);
    node.insert(&head, 521);
    node.insert(&head, 50);
    node.insert(&head, 18);
    node.insert(&head, 41);
    std::cout << std::boolalpha << node.is_empty(head) << std::endl;
    node.print(head);
    std::cout << "Print using recursion: ";
    node.print_recurse(head);
    node.search(head, 2);
    node.search(head, 24);
    node.sum(head);
    node.odd_or_even(head);
    node.largest(head);
    std::cout << std::endl;

    // binary search driver code
    int arr[] = {2, 3, 23, 54, 56, 68};
    int n = sizeof(arr) / sizeof(arr[0]), target = 23;
    binary_search(arr, n, target);

    target = 2;
    binary_search(arr, n, target);

    target = 25;
    binary_search(arr, n, target);

    target = 3;
    binary_search(arr, n, target);
    sum(arr, n);

    int test[2][2][2][2] = {
        {{{1, 2}, {3, 4}},

         {{5, 6}, {7, 8}}},

        {{{9, 10}, {11, 12}},

         {{13, 14}, {15, 16}}}};

    std::cout << test[1][0][0][1] << std::endl;

    for (int i = 0; i < std::size(test); i++)
    {
        for (int j = 0; j < std::size(test[i]); j++)
        {
            std::cout << "{";
            for (int k = 0; k < std::size(test[i][j]); k++)
            {
                std::cout << "{";
                for (int l = 0; l < std::size(test[i][j][k]); l++)
                {
                    std::cout << test[i][j][k][l];
                    if (l < std::size(test) - 1)
                    {
                        std::cout << ", ";
                    }
                }
                std::cout << "}";
                if (k < std::size(test) - 1)
                {
                    std::cout << ", ";
                }
            }
            std::cout << "}";
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;

    int a[] = {3, 1, 5, 2, 4, 7, 9, 6, 8};
    std::cout << a[2] << std::endl;
    n = sizeof(a) / sizeof(*a);
    print(a, n);
    std::sort(a, a + n);
    print(a, n);
    target = 9;
    stl_search(a, target, n);

    target = 2;
    stl_search(a, target, n);

    target = 7;
    stl_search(a, target, n);

    target = 74;
    stl_search(a, target, n);

    return 0;
}