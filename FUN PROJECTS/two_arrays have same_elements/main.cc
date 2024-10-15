#include <iostream>

void check(int a[], int b[], int a_n, int b_n)
{
    int count = 0;
    for (int i = 0; i < a_n; i++)
    {
        for (int j = 0; j < b_n; j++)
        {
            if (a[i] == b[j])
            {
                count++;
                std::cout << a[i] << ", ";
            }
        }
    }
    std::cout << "are the " << count << " elements are shared in common." << std::endl;
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int x[] = {2, 4, 3, 22, 1, 13, 5};
    int x_n = sizeof(x) / sizeof(*x);
    int y[] = {9, 2, 7, 20, 1, 12, 5, 8, 22};
    int y_n = sizeof(y) / sizeof(*y);
    print_array(x, x_n);
    print_array(y, y_n);

    check(x, y, x_n, y_n);

    return 0;
}